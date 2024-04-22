/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driwn_2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:37:31 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/21 16:28:10 by ahamdi           ###   ########.fr       */
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
    char *color_split;
    int color;
    
    (*data)->x1 = x1;
    (*data)->x2 = x2;
    (*data)->y1 = y1;
    (*data)->y2 = y2;
    color = get_color(data);
    x_step = (*data)->x2 - (*data)->x1;
    y_step =  (*data)->y2 -  (*data)->y1;
    MAX = fmaxf(fabsf(x_step), fabsf(y_step)); // Utilisation de fmaxf pour trouver le maximum absolu
    x_step /= MAX;
    y_step /= MAX; // Correction de la division par MAX
    while (((*data)->x2 - (*data)->x1) != 0 || ( (*data)->y2 -  (*data)->y1) != 0)
    { 
        (*data)->x= (*data)->x1 + (*data)->mov_cote;
        (*data)->y= (*data)->y1+(*data)->mouv_haut;
        mlx_pixel_put((*data)->mlx_ptr,(*data)->win_ptr,(*data)->x ,(*data)->y, color); // Arrondissement à la valeur entière la plus proche
        (*data)->x1 += x_step;
         (*data)->y1 += y_step;
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
