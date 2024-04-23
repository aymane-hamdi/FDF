/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:38 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/23 10:44:16 by ahamdi           ###   ########.fr       */
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

void initial_data(fdf **data,char **argv)
{
    (*data)->form = 2;
    (*data)->haut=1;
    (*data)->zoom = 1;
    (*data)->color_change = 16777215;
    (*data)->mov_cote =  0;
    (*data)->mouv_haut = 0;
    (*data)->button = 0;
    (*data)->argv = argv;
    (*data)->angel_x = 0;
    (*data)->angel_y = 0;
    (*data)->angel_z = 0;
    (*data)->width_window = 1500;
    (*data)->height_window = 1500;
}
void fontion_mlx_and_draw(fdf **data)
{
    red_file((*data)->argv[1],data);
    draw_2D(data); 
    print_menu2D(*data);
    mlx_key_hook((*data)->win_ptr, key_press, data);
    mlx_hook((*data)->win_ptr, 17, 0, close_window, *data);
    mlx_hook((*data)->win_ptr, 4, 0, mouse_press, data);
	mlx_hook((*data)->win_ptr, 5, 0, mouse_press, data);
}
int main(int argc, char **argv)
{
    fdf *data;
   
    data = (fdf*)malloc(sizeof(fdf));
    data->mlx_ptr = mlx_init();
     initial_data(&data,argv);
    if (data->mlx_ptr == NULL)
    {
        printf("Failed to initialize mlx.\n");
        free(data); // Libérer la mémoire allouée à data
        exit (1);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr,  data->width_window,   data->height_window, "FDF project");
    if (data->win_ptr == NULL)
    {
        printf("Failed to create a new window.\n");
        free(data); 
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        return 1;
    }
    fontion_mlx_and_draw(&data);
    mlx_loop(data->mlx_ptr);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    return(0);
}
