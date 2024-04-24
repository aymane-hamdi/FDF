/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:38 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/24 11:00:16 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
void set_zoom(fdf **data)
{
	int x_zoom;
	int y_zoom;
	
	x_zoom= (((*data)->width_window-230) / (*data)->width)/2;
	y_zoom = ((*data)->height_window / (*data)->height)/2;
   	if(x_zoom < y_zoom)
		(*data)->zoom = x_zoom;
   	else
		(*data)->zoom = y_zoom;
   	if((*data)->zoom == 0)
	(*data)->zoom = 1;
}
int close_window(fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_putstr_fd(" close window",1);
	free(data); 
	exit(0); 
}

void initial_data(fdf **data,char **argv)
{
	(*data)->width_window = 1000;
	if((*data)->height >=500)
		(*data)->height_window = (*data)->height *2;
	else
		(*data)->height_window = 1000;
	(*data)->form = 2;
	(*data)->haut=1;
	set_zoom(data);
	(*data)->color_change = 16777215;
	(*data)->mov_cote = (((*data)->width_window - 230) /2) +230;
	(*data)->mouv_haut = (*data)->height_window /2;
	(*data)->argv = argv;
	(*data)->angel_x = 0;
	(*data)->angel_y = 0;
	(*data)->angel_z = 0;
}
void fontion_mlx_and_draw(fdf **data)
{
	draw_2D(data);
	print_menu(*data); 
	mlx_key_hook((*data)->win_ptr, key_press, data);
	mlx_hook((*data)->win_ptr, 17, 0, close_window, *data);
	// mlx_hook((*data)->win_ptr, 4, 0, mouse_press, data);
	// mlx_hook((*data)->win_ptr, 5, 0, mouse_press, data);
}
int main(int argc, char **argv)
{
	fdf *data;
   
	data = (fdf*)malloc(sizeof(fdf));
	data->mlx_ptr = mlx_init();
	red_file(argv[1],&data);
	initial_data(&data,argv);
	if (data->mlx_ptr == NULL)
	{
		ft_putstr_fd("Failed to initialize mlx.\n",2);
		free(data); // Libérer la mémoire allouée à data
		exit (1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr,  data->width_window,   data->height_window, "FDF project");
	if (data->win_ptr == NULL)
	{
		ft_putstr_fd("Failed to create a new window.\n",2);
		free(data); 
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	fontion_mlx_and_draw(&data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return(0);
}
