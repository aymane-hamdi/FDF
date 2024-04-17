/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:38 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/17 17:58:41 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void adjustWindowSize(int *width, int *height, int direction) {
    if (direction == 1) { // Augmenter la taille de la fenêtre
        (*width) += 10;
        (*height) += 10;
    } else { // Réduire la taille de la fenêtre
        (*width) -= 10;
        (*height) -= 10;
    }
}

int dealWithKeyboard(int keycode, int *width, int *height) {
    if (keycode == 43) // Touche '+' pour augmenter la taille
        adjustWindowSize(width, height, 1);
    else if (keycode == 45) // Touche '-' pour réduire la taille
        adjustWindowSize(width, height, -1);
    else
        return 0;
    return 1;
}

int dealWithMouse(int button, int *width, int *height) {
    if (button == 4) // Bouton de la molette de la souris vers le haut pour augmenter la taille
        adjustWindowSize(width, height, 1);
    else if (button == 5) // Bouton de la molette de la souris vers le bas pour réduire la taille
        adjustWindowSize(width, height, -1);
    else
        return 0;
    return 1;
}

int close_window(char *param)
{
    ft_putstr_fd(param,1);
    exit(0); // Quitte le programme proprement
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
        exit (1);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "FDF project");
    if (data->win_ptr == NULL)
    {
        printf("Failed to create a new window.\n");
        return 1;
    } 
    draw (argv,&data);
    mlx_hook(data->win_ptr, 17, 0, close_window, "Close window\n"); 
     mlx_key_hook(data->win_ptr, dealWithKeyboard, data);
    mlx_mouse_hook(data->win_ptr, dealWithMouse, data);
    mlx_loop(data->mlx_ptr);
    return(0);
}