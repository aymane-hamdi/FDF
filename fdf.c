/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:38 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/19 19:10:52 by ahamdi           ###   ########.fr       */
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


int main(int argc, char **argv)
{
    fdf *data;
    int width =  1500, height = 1500;
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
    red_file(argv[1],&data);
    double centerX = width / 2;
    double centerY = height / 2;
    data->form = 2;
    data->zoom = 1;
    centerX -= data->zoom / 2;
    centerY -= data->zoom / 2;
    data->mov_cote = centerX;
    data->mouv_haut = centerY;
    data->button = 0;
    data->argv = argv;
    data->angel_x = 0;
    data->angel_y = 0;
    data->angel_z = 0;
    draw_2D(&data); 
    print_menu2D(data);
    mlx_key_hook(data->win_ptr, key_press, &data);
    mlx_hook(data->win_ptr, 17, 0, close_window, data);
    mlx_hook(data->win_ptr, 4, 0, mouse_press, &data);
	mlx_hook(data->win_ptr, 5, 0, mouse_press, &data);
    mlx_loop(data->mlx_ptr);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    return(0);
}