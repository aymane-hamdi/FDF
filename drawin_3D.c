/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawin_3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:58:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/22 22:35:59 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void  isometric(float *x, float *y, int z, fdf *data)
{
    int tmp;
    tmp = *x;
    *x = (tmp - *y) * cos(0.523599);
    *y = (tmp + *y) * sin(0.523599) - z;
}
int get_color_3d(fdf **data)
{
    int color;
    int color1;
    int color2; // Initialisation par défaut de color2
    int value;
    int min;
    int max;
    int start_color;
    int end_color;
    float ratio;

    float dx = (*data)->x2 - (*data)->start_x;
    float dy = (*data)->y2 - (*data)->start_y;
    if (dx > dy)
    {
        value = (*data)->x1;
        min = (*data)->start_x;
        max = (*data)->end_x;
    }
    else
    {
        value = (*data)->y1;
        min = (*data)->start_y;
        max = (*data)->end_y;
    }
    ratio = (value - min) / (float)(max - min);
    start_color = ft_atoi((*data)->matrix[(*data)->color_start_y][(*data)->color_start_x]);
    end_color = ft_atoi((*data)->matrix[(*data)->color_end_y][(*data)->color_end_x]);
    if (start_color != 0)
        color1 = 16711680; // Rouge
    else
        color1 = 16777215; // Blanc
    if (end_color != 0)
        color2 = 16711680; // Rouge
    else
        color2 = 16777215; // Blanc
    color = get_gradient(color1, color2, ratio);
    if(ft_strchr((*data)->matrix[(*data)->color_start_y][(*data)->color_start_x],',') != NULL)
        color = hexToInt(ft_strchr((*data)->matrix[(*data)->color_start_y][(*data)->color_start_x],',')+1);
    return (color);
}

void trasformation(float *x1, float *y1, float *x2, float *y2, fdf **data,float *z1,float *z2)
{
    rotate_x(y1, z1, (*data)->angel_x);
    rotate_x(y2, z2, (*data)->angel_x);
    rotate_y(x1, z1,(*data)->angel_y);
    rotate_y(x2, z2, (*data)->angel_y);
    rotate_z(x1, y1,(*data)->angel_z);
    rotate_z(x2,y2,(*data)->angel_z);
    isometric(x1,y1,*z1,*data);
    isometric(x2,y2,*z2,*data);
}

void bresenham(float x1, float y1, float x2, float y2, fdf **data)
{
    float x_step;
    float y_step;
    float MAX;
    float z1;
    int color;
    float z2;
    z1 = ft_atoi((*data)->matrix[(int)y1][(int)x1]);
    z2 = ft_atoi((*data)->matrix[(int)y2][(int)x2]); 
    (*data)->color_start_x=x1;
    (*data)->color_start_y=y1;
    (*data)->color_end_x=x2;
    (*data)->color_end_y=y2;
    x1*=(*data)->zoom;
    y1*=(*data)->zoom;
    x2*=(*data)->zoom;
    y2*=(*data)->zoom;
    z1*=(*data)->zoom;
    z2*=(*data)->zoom;
    trasformation(&x1, &y1, &x2, &y2,data,&z1,&z2);
    x_step = x2 - x1;
    y_step = y2 - y1;
    MAX = fmaxf(fabsf(x_step), fabsf(y_step));
    x_step /= MAX;
    y_step /= MAX;
    (*data)->x2 = x2;
    (*data)->y2 =y2;
    (*data)->start_x= x1;
    (*data)->start_y= y1;
    (*data)->end_x= x2;
    (*data)->end_y= y2;
    while ((int)(x2 - x1) != 0 || (int)(y2 - y1) != 0)
    {
        (*data)->x1 = x1;
        (*data)->y1 =y1;
        color = get_color_3d(data);
        mlx_pixel_put((*data)->mlx_ptr,(*data)->win_ptr, (int)x1+ (*data)->mov_cote, (int)y1+(*data)->mouv_haut,  color); 
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
    int fd;
    y = 0;
    while(y < (*data)->height)
    {
        x = 0;
        while(x < (*data)->width)
        { 
            x1 = (x + 1);
            y1 = y;
            if(x + 1 < (*data)->width && (*data)->matrix[y][x + 1])
            {
                bresenham(x , y , x1 , y1 ,data);
            }
            if(y + 1 <(*data)->height && (*data)->matrix[y + 1])
            {
                x1 = x;
                y1 = y+1;
                bresenham(x , y , x1 , y1 ,data);
            }
            x++;
        }
        y++;
    }
}