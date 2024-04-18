/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driwn_2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:37:31 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/18 17:06:27 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void bresenham_2D(float x1, float y1, float x2, float y2, fdf **data)
{
    float x_step;
    float y_step;
    float MAX;
    int zomm;
    int mov_cote;
    int mouv_haut;
    char **color_split;
    int color;
    mov_cote = (*data)->mov_cote;
    mouv_haut = (*data)->mouv_haut;
    color_split = ft_split((*data)->matrix[(int)y1][(int)x1], ',');
    if(color_split[1] == NULL)
    {
        if(ft_atoi((*data)->matrix[(int)y1][(int)x1]) != 0)
        {
            if(ft_atoi((*data)->matrix[(int)y2][(int)x2]) != 0)
                color = 0x004A4E;
            else
            color = 0xD99BDC;
        }
           
        else
            color = 0xFBE3B4;
    }  
    else
        color = hexToInt(color_split[1]) ;
    x_step = x2 - x1;
    y_step = y2 - y1;
    zomm = (*data)->zoom;
    x1*=zomm;
    y1*=zomm;
    x2*=zomm;
    y2*=zomm;
    MAX = fmaxf(fabsf(x_step), fabsf(y_step)); // Utilisation de fmaxf pour trouver le maximum absolu

    x_step /= MAX;
    y_step /= MAX; // Correction de la division par MAX
    (*data)->x=(int)x1+ mov_cote;
    (*data)->y=(int)y1 + mouv_haut;
    while ((int)(x2 - x1) != 0 || (int)(y2 - y1) != 0)
    {
        mlx_pixel_put((*data)->mlx_ptr,(*data)->win_ptr, (int)x1+ mov_cote , (int)y1 + mouv_haut, color); // Arrondissement à la valeur entière la plus proche
        x1 += x_step;
        y1 += y_step;
    }
}

void draw_2D(fdf **data)
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
                {
                     (*data)->z = ft_atoi((*data)->matrix[y][x + 1]);
                   bresenham_2D(x , y , x1 , y1 ,data);
                }
                else
                {
                  bresenham_2D(x , y , x1 , y1 ,data);
                }
            }
            if(y + 1 <(*data)->height && (*data)->matrix[y + 1])
            {
                x1= x;
                y1 = y+1;
                if(ft_atoi((*data)->matrix[y + 1][x]) != 0)
                {
                   bresenham_2D(x, y , x1, y1,data);
                }
                else
                {
                   bresenham_2D(x , y , x1 , y1 ,data);
                }
            }
            x++;
        }
        free(line);
        y++;
    }
    close(fd);
}