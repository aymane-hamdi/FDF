/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keybord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:01:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/24 12:02:55 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int autour_pres(int key, fdf **data)
{
    if(key == 7  )
        (*data)->angel_x +=0.2;
    else if(key == 2  )
        (*data)->angel_x -=0.2;
    if(key == 16 )
        (*data)->angel_y +=0.2;
    else if(key == 32 )
        (*data)->angel_y -=0.2;
    if(key == 6  )
            (*data)->angel_z +=0.2;
    if(key == 257 )
        (*data)->angel_z -=0.2;
    return(0);
}
void zoom(int key, fdf **data)
{
    if (key == 69)
        (*data)->zoom +=1;
    else if (key == 78)
    {
        (*data)->zoom -= 1;
        if((*data)->zoom < 2)
            (*data)->zoom = 1;
    }
}
void mouv_cote(int key,fdf **data)
{
    if(key == 124)
        (*data)->mov_cote += 100;
    else if(key == 123)
        (*data)->mov_cote -= 100;
}
void mouve_haute(int key ,fdf **data)
{
    if(key == 	126)
        (*data)->mouv_haut -= 100;
    else if(key == 125)
         (*data)->mouv_haut += 100;
}
int key_press(int key, fdf **data)
{
    autour_pres(key,data);
     if (key == 53)
        close_window(*data); 
    else if(key == 84)
        (*data)->form = 2;
    else if(key == 85)
        (*data)->form = 3; 
    if(key == 8)
      (*data)->color_change =16777216;
    else if(key == 9)
        (*data)->color_change =16777215;
    mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
    zoom(key, data);
    mouv_cote(key,data);
    mouve_haute(key ,data);
    if((*data)->form == 2)
        draw_2D(data); 
    else
        draw_3D(data); 
    print_menu(*data);
    return (0);
}
