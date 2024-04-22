/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driwn_2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:37:31 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/22 23:02:02 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int get_color(fdf **data)
{
   int color;
   
   if(ft_strchr((*data)->matrix[(*data)->y1][(*data)->x1], ',') == NULL)
    {
        if(ft_atoi((*data)->matrix[(*data)->y1][(*data)->x1]) != 0)
        {
            color = 16711680;
            if(ft_atoi((*data)->matrix[(*data)->y2][(*data)->x2]) != 0)
            {
                color = 16711680;
            }
        }
        else
            color = 16777215;
    }  
    else
       color = hexToInt(ft_strchr((*data)->matrix[(*data)->y1][(*data)->x1], ',') + 1 );
    (*data)->x1*=(*data)->zoom;
    (*data)->y1*=(*data)->zoom;
    (*data)->x2*=(*data)->zoom;
    (*data)->y2*=(*data)->zoom;
    return(color);
}
void bresenham_2D(float x1, float y1, float x2, float y2, fdf **data)
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

void draw_2D(fdf **data)
{
    int x;
    int y;
    int x1;
    int y1;
    
    y = 0;
    while(y < (*data)->height)
    {
        x = 0;
        while(x < (*data)->width)
        { 
            if(x + 1 < (*data)->width && (*data)->matrix[y][x + 1])
            {
                x1= (x + 1);
                y1 = y;
                bresenham_2D(x , y , x1 , y1 ,data);
            }
            if(y + 1 <(*data)->height && (*data)->matrix[y + 1])
            {
                x1= x;
                y1 = y+1;
                bresenham_2D(x , y , x1 , y1 ,data);
            }
            x++;
        }
        y++;
    }
}
