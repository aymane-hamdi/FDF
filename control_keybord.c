/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keybord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:01:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/22 15:26:08 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int autour_pres(int key, fdf **data)
{
    if(key == 7  && (*data)->form == 3)
        (*data)->angel_x +=0.2;
    else if(key == 2  && (*data)->form == 3)
        (*data)->angel_x -=0.2;
    else if(key == 16 && (*data)->form == 3)
        (*data)->angel_y +=0.2;
    else if(key == 32 && (*data)->form == 3)
        (*data)->angel_y -=0.2;
     else if(key == 6  && (*data)->form == 3)
        (*data)->angel_z +=0.2;
    else if(key == 257  && (*data)->form == 3)
        (*data)->angel_z -=0.2;
    return(0);
}
void zoom(int key, fdf **data)
{
    if (key == NUM_PAD_PLUS)
        (*data)->zoom +=1;
    else if (key == NUM_PAD_MINUS )
    {
        (*data)->zoom -= 1;
        if((*data)->zoom < 2)
            (*data)->zoom = 1;
        // Zoom arrière lorsque la touche '-' est pressée
    }
}
void mouv_cote(int key,fdf **data)
{
    if(key == ARROW_RIGHT)
        (*data)->mov_cote += 100;
    else if(key == ARROW_LEFT)
        (*data)->mov_cote -= 100;
}
void mouve_haute(int key ,fdf **data)
{
    if(key == ARROW_UP)
        (*data)->mouv_haut -= 100;
    else if(key ==ARROW_DOWN)
         (*data)->mouv_haut += 100;
}
// int  c_v(int key,fdf *data)
// {
//     if(key == 8)
//     {
//         mlx_clear_window(data->mlx_ptr, data->win_ptr);
//         draw_3D_sans_bas(&data);
//         print_menu3D(&data);
//     }
//     else if(key == 9)
//     {
//         mlx_clear_window(data->mlx_ptr, data->win_ptr);
//         draw_3D(&data); 
//         print_menu3D(&data);
//     }
//     return(0);
// }
int key_press(int key, fdf **data)
{
    printf("key = %d\n",key);
    autour_pres(key,data);
    if (key == MAIN_PAD_ESC)
        close_window(*data); // Fermer la fenêtre lorsque la touche ESC est pressée
    else if(key == 84)
        (*data)->form = 2;
    else if(key == 85)
        (*data)->form = 3; 
    mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
    // c_v(key,*data);
    zoom(key, data);
    mouv_cote(key,data);
    mouve_haute(key ,data);
     if((*data)->form == 2)
    {
            draw_2D(data); 
            print_menu2D(*data);
    }
    else
    {
        draw_3D(data); 
        print_menu3D(data);
    }   
    return (0);
}
