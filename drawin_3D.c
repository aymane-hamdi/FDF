/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawin_3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:58:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/18 19:13:32 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void rotate_z(float *x, float *y, float angle)
{
    float x_temp;

    x_temp = *x;
    *x = *x * cos(angle) - *y * sin(angle);
    *y = x_temp * sin(angle) + *y * cos(angle);
}
void rotate_y(float *x, float *z, float angle)
{
    float x_temp;

    x_temp = *x;
    *x = *x * cos(angle) + *z * sin(angle);
    *z = -x_temp * sin(angle) + *z * cos(angle);
}
void rotate_x(float *y, float *z,float angle)
{
   float y_temp;

    y_temp = *y;
    *y = *y * cos(angle) - *z * sin(angle);
    *z = y_temp * sin(angle) + *z * cos(angle);
}
void  isometric(float *x, float *y, int z)
{
 int tmp;

    tmp = *x;
 *x = (tmp - *y) * cos(0.523599);
 *y = (tmp + *y) * sin(0.523599) - z;
}
void bresenham(float x1, float y1, float x2, float y2, fdf **data)
{
    int zomm ;
    float x_step;
    float y_step;
    float MAX;
    int mov_cote;
    int mouv_haut;
	float z1;
    char **color_split;
    int color;
    float z2;
    mov_cote = (*data)->mov_cote;
    mouv_haut = (*data)->mouv_haut;
    zomm = (*data)->zoom;
    z1 = ft_atoi((*data)->matrix[(int)y1][(int)x1]);
    color_split = ft_split((*data)->matrix[(int)y1][(int)x1], ',');
    if(color_split[1] == NULL)
    {
        if(ft_atoi((*data)->matrix[(int)y1][(int)x1]) != 0)
        {
            if(ft_atoi((*data)->matrix[(int)y2][(int)x2]) != 0)
                color = 0x122D94;
            else
            color = 0xD5EFF4;
        }
           
        else
            color = 0xFFC7A6;
    }  
    else
        color = hexToInt(color_split[1]) ;
    z2 = ft_atoi((*data)->matrix[(int)y2][(int)x2]);
    rotate_x(&y1, &z1, (*data)->angel_x);
    rotate_x(&y2, &z2, (*data)->angel_x);
    rotate_y(&x1, &z1,(*data)->angel_y);
    rotate_y(&x2, &z2, (*data)->angel_y);
    rotate_z(&x1, &y1,(*data)->angel_z);
    rotate_z(&x2,&y2,(*data)->angel_z);
    isometric(&x1,&y1,z1);
    isometric(&x2,&y2,z2);
    x1*=zomm;
    y1*=zomm;
    x2*=zomm;
    y2*=zomm;
    x_step = x2 - x1;
    y_step = y2 - y1;
    
    MAX = fmaxf(fabsf(x_step), fabsf(y_step)); // Utilisation de fmaxf pour trouver le maximum absolu

    x_step /= MAX;
    y_step /= MAX; // Correction de la division par MAX
    (*data)->x=(int)x1+ mov_cote;
    (*data)->y=(int)y1 + mouv_haut;
    if(z1 !=0)
        (*data)->z = z1;
    while ((int)(x2 - x1) != 0 || (int)(y2 - y1) != 0)
    {
        mlx_pixel_put((*data)->mlx_ptr,(*data)->win_ptr, (int)x1+ mov_cote , (int)y1 + mouv_haut, color); // Arrondissement à la valeur entière la plus proche
        x1 += x_step;
        y1 += y_step;
    }
}

void draw_3D(fdf **data)
{
    int x;
    int y;
    int x1;
    int y1;
    char *line;
    int fd;
    red_file((*data)->argv[1],data);
    y = 0;
    fd = open((*data)->argv[1],O_RDONLY);
    while(y < (*data)->height)
    {
        x = 0;
        line = get_next_line(fd);
       (*data)->width = get_width(line) -1 ;
        while(x < (*data)->width)
        { 
            x1= (x + 1);
            y1 = y;
            if(x + 1 <(*data)->width && (*data)->matrix[y][x + 1])
            {
                x1= (x + 1);
                y1 = y;
                if(ft_atoi((*data)->matrix[y][x + 1]) != 0)
                    bresenham(x , y , x1 , y1 ,data);
                else
                   bresenham(x , y , x1 , y1 ,data);
            }
            if(y + 1 <(*data)->height && (*data)->matrix[y + 1])
            {
                x1= x;
                y1 = y+1;
                if(ft_atoi((*data)->matrix[y + 1][x]) != 0)
                    bresenham(x, y , x1, y1,data);
                else
                    bresenham(x , y , x1 , y1 ,data);
            }
            x++;
        }
        free(line);
        y++;
    }
    close(fd);
}