/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:38 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/18 17:54:28 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
int close_window(fdf *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    ft_putstr_fd(" close window",1);
    free(data); // Libérer la mémoire allouée à data
    exit(0); // Quitter le programme
}
int autour_pres(int key, fdf **data)
{
    printf("key = %d\n",key);
    if(key == 7)
    {
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->angel_x +=0.4;
        draw_3D(data); 
        print_menu3D(*data);
    }
    else if(key == 16)
    {
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->angel_y +=0.4;
        draw_3D(data); 
        print_menu3D(*data);
    }
     else if(key == 6)
    {
        printf("rotate z\n");
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->angel_z +=0.2;
        draw_3D(data); 
        print_menu3D(*data);
    }
    return(0);
}
int key_press(int key, fdf **data)
{
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
        print_menu3D(*data);
    }
    else if (key == NUM_PAD_PLUS )
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
            print_menu3D(*data);
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
            print_menu3D(*data);
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
            print_menu3D(*data);
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
            print_menu3D(*data);
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
            print_menu3D(*data);
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
            print_menu3D(*data);
        }
        // Zoom arrière lorsque la touche '-' est pressée
    }
    return (0);
}



int main(int argc, char **argv)
{
    fdf *data;
    int width =  1500, height = 1000;
    data = (fdf*)malloc(sizeof(fdf));
    data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
    {
        printf("Failed to initialize mlx.\n");
        free(data); // Libérer la mémoire allouée à data
        exit (1);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "FDF project");
    if (data->win_ptr == NULL)
    {
        printf("Failed to create a new window.\n");
        free(data); 
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        return 1;
    }
    data->form = 2;
    data->zoom = 20;
    data->mov_cote = 400;
    data->mouv_haut = 500;
    data->button = 0;
    data->argv = argv;
    data->angel_x = 0;
    data->angel_y = 0;
    data->angel_z = 0;
    draw_2D(&data); 
    print_menu2D(data);
    mlx_key_hook(data->win_ptr, key_press, &data);
    mlx_hook(data->win_ptr, 17, 0, close_window, data);
    mlx_loop(data->mlx_ptr);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    return(0);
}