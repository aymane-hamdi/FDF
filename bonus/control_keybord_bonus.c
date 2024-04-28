/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keybord_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:01:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/28 21:39:00 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf_bonus.h"

int autour_pres(int key, fdf **data)
{
    printf("key = %d\n",key);
   if(key == 257)
   {
        mlx_loop_hook((*data)->mlx_ptr, change_colore, data);
   }
    if (key == 7)
    {
        (*data)->key = 1;
        mlx_loop_hook((*data)->mlx_ptr, rotate_object_x, data);
    }
    else if (key == 2)
        (*data)->angel_x -= 0.2;
    if (key == 16)
    {
        (*data)->key = 1;
        mlx_loop_hook((*data)->mlx_ptr, rotate_object_y, data);
    }
    else if (key == 32)
        (*data)->angel_y -= 0.2;
    if (key == 6)
    {
        (*data)->key = 1;
        mlx_loop_hook((*data)->mlx_ptr, rotate_object_z, data);
    }
    if(key == 49) 
    {
        (*data)->key = 0;
    }
    if (key == 0)
        (*data)->angel_z -= 0.2;
    return (0);
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
int reset(int key,fdf **data)
{
    if(key== 15)
    {
        set_zoom(data);
        (*data)->mov_cote = (((*data)->width_window - 300) /2);
        (*data)->mouv_haut = (*data)->height_window /2;
        (*data)->angel_x = 0;
        (*data)->angel_y = 0;
        (*data)->angel_z = -1.400000;
    }
    
    return (0);
}
int key_press(int key, fdf **data)
{
    reset(key,data);
    autour_pres(key,data);
     if (key == 53)
        close_window(data);
    else if(key == 116)
    {
        (*data)->h += 1;
    }
    else if(key == 121)
    {
        (*data)->h -= 1;
    }
    else if(key == 84)
        (*data)->form = 2;
    else if(key == 85)
        (*data)->form = 3; 
    if(key == 8)
      (*data)->color_change = 16777216;
    else if(key == 9)
        (*data)->color_change = 16777215;
    mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
    mlx_destroy_image((*data)->mlx_ptr, (*data)->img_print);
    mlx_destroy_image((*data)->mlx_ptr, (*data)->img);
    zoom(key, data);
    mouv_cote(key,data);
    mouve_haute(key ,data);
    if((*data)->form == 2)
        draw_2D(data); 
    else
    {
        draw_3D(data);
        draw_3D_inverce(data);
    }
    print_menu(data);
    return (0);
}
