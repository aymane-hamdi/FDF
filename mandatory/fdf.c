/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:38 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/30 21:43:30 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void set_zoom(fdf **data)
{
	int x_zoom;
	int y_zoom;
	
	x_zoom= (((*data)->width_window) / (*data)->width)/2;
	y_zoom = ((*data)->height_window / (*data)->height)/2;
   	if(x_zoom < y_zoom)
		(*data)->zoom = x_zoom+1;
   	else
		(*data)->zoom = y_zoom+1;
   	if((*data)->zoom == 0)
	(*data)->zoom = 2;
}
int close_window(fdf **data)
{
	mlx_destroy_window((*data)->mlx_ptr, (*data)->win_ptr);
	ft_putstr_fd(" close window",1);
	free(*data); 
	exit(0); 
}

void initial_data(fdf **data,char **argv)
{
	(*data)->width_window = 1000;
	(*data)->height_window = 1000;
	(*data)->form = 3;
	set_zoom(data);
	(*data)->color_change = 16777215;
	(*data)->mov_cote = ((*data)->width_window - (*data)->width*(*data)->zoom) /2;
	(*data)->mouv_haut = ((*data)->height_window  - (*data)->height) /2;
	(*data)->argv = argv;
	(*data)->angel_z = -1.400000;
}

void fontion_mlx_and_draw(fdf **data)
{
	
	int img_width, img_height;
    void *img_ptr;

	draw_3d(data);
	mlx_key_hook((*data)->win_ptr, key_press, data);
	mlx_hook((*data)->win_ptr, 17, 0, close_window, data);
}
int main(int argc, char **argv)
{
	fdf *data;
   
	data = (fdf*)malloc(sizeof(fdf));
	data->mlx_ptr = mlx_init();
	red_map(argv[1],&data);
	initial_data(&data,argv);
	if (data->mlx_ptr == NULL)
	{
		ft_putstr_fd("Failed to initialize mlx.\n",2);
		free(data); // Libérer la mémoire allouée à data
		exit (1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr,  data->width_window+200,   data->height_window+200, "FDF project");
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
