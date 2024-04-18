/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keybord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:01:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/18 21:24:04 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int autour_pres(int key, fdf **data)
{
    if(key == 7  && (*data)->form == 3)
    {
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->angel_x +=0.4;
        draw_3D(data); 
        print_menu3D(data);
    }
    else if(key == 16 && (*data)->form == 3)
    {
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->angel_y +=0.4;
        draw_3D(data); 
        print_menu3D(data);
    }
     else if(key == 6  && (*data)->form == 3)
    {
        printf("rotate z\n");
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->angel_z +=0.2;
        draw_3D(data); 
        print_menu3D(data);
    }
    return(0);
}
int key_press(int key, fdf **data)
{
    printf("key = %d\n",key);
    autour_pres(key,data);
    if (key == MAIN_PAD_ESC)
        close_window(*data); // Fermer la fenêtre lorsque la touche ESC est pressée
    if(key == 84)
    {
        (*data)->form = 2;
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr); 
        draw_2D(data); 
        print_menu2D(*data);
    }
    else if(key == 85)
    {
         (*data)->form = 3;
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr); 
        draw_3D(data); 
        print_menu3D(data);
    }
    else if (key == NUM_PAD_PLUS || key == 4)
    {
        printf("zoom in\n");
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
       
        (*data)->zoom +=1;
         (*data)->zoom *=2;
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
    } 
    else if (key == NUM_PAD_MINUS )
    {
       
        printf("zoom out\n");
       
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->zoom /= 2;
        if((*data)->zoom < 2)
            (*data)->zoom = 1;
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
        // Zoom arrière lorsque la touche '-' est pressée
    }
    else if(key == ARROW_RIGHT)
    {
         printf("mouv RIGHT\n");
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->mov_cote += 1;
        (*data)->mov_cote *= 2;
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
        // Zoom arrière lorsque la touche '-' est pressée
    }
    else if(key == ARROW_LEFT)
    {
        printf("mouv LEFT\n");
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->mov_cote /= 2;
        if((*data)->form == 2)
        {
            draw_2D(data); 
            print_menu2D(*data);
        }
        else
        {
            draw_3D(data); 
            print_menu3D(data);
        };
        // Zoom arrière lorsque la touche '-' est pressée
    }
    else if(key == ARROW_UP)
    {
        printf("mouv ARROW_UP\n");
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->mouv_haut /= 2;
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
        // Zoom arrière lorsque la touche '-' est pressée
    }
    else if(key ==ARROW_DOWN)
    {
        printf("mouv DOWN\n");
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->mouv_haut += 1;
         (*data)->mouv_haut *= 1.1;
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
        // Zoom arrière lorsque la touche '-' est pressée
    }
    return (0);
}