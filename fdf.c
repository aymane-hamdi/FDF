/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:38 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/17 20:24:59 by ahamdi           ###   ########.fr       */
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

int key_hook(int key, fdf *data)
{
    if (key == 53)
        close_window(data);
    return (0);
}

int key_press(int keycode, fdf **data)
{
    printf("%d\n",keycode);
    if (keycode == 53) 
        close_window(*data);
    return (0);
}

int main(int argc, char **argv)
{
    fdf *data;
    int width = 1000, height = 1000;
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
        free(data); // Libérer la mémoire allouée à data
        return 1;
    } 
    draw (argv,&data); 
    mlx_key_hook(data->win_ptr, key_press, &data);
    mlx_hook(data->win_ptr, 17, 1L<<17, close_window, data);
    mlx_loop(data->mlx_ptr);
    return(0);
}