/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:38 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/20 14:48:59 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_zoom(t_fdf **data)
{
	(*data)->zoom = 1;
	if ((*data)->width > 200 || (*data)->height > 200 || 
		(*data)-> z_max >= 200)
		(*data)->zoom = 1;
	else if ((*data)->width >= 100 || (*data)->height >= 100 
		|| (*data)-> z_max >= 100)
		(*data)->zoom = 5;
	else if ((*data)->width >= 50 || (*data)->height >= 50 
		|| (*data)-> z_max >= 50)
		(*data)->zoom = 15;
	else
		(*data)->zoom = 20;
	(*data)->mov_cote = ((*data)->width_window) / 2 ;
	(*data)->mouv_haut = (((*data)->height_window) / 2) + 100;
}

int	close_window(t_fdf **data)
{
	mlx_destroy_window((*data)->mlx_ptr, (*data)->win_ptr);
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img);
	ft_putstr_fd(" close window", 1);
	free_3d_char_array(data);
	free(*data); 
	exit(0); 
}

void	initial_data(t_fdf **data, char **argv)
{
	(*data)->width_window = 1300;
	(*data)->height_window = 1300;
	(*data)->form = 3;
	(*data)->argv = argv;
	set_zoom(data);
	(*data)->angel_x = 48 * M_PI / 180;
	(*data)->angel_y = 1 * M_PI / 180;
	(*data)->angel_z = 30 * M_PI / 180;
}

void	fontion_mlx_and_draw(t_fdf **data)
{
	draw_3d(data);
	mlx_key_hook((*data)->win_ptr, key_press, data);
	mlx_hook((*data)->win_ptr, 17, 0, close_window, data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	invalid_argument(argc);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	red_map(argv[1], &data);
	data->mlx_ptr = mlx_init();
	initial_data(&data, argv);
	if (data->mlx_ptr == NULL)
		error_intalis(&data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width_window,
			data->height_window, "t_fdf project");
	if (data->win_ptr == NULL)
		error_intalis(&data);
	data->img = mlx_new_image(data->mlx_ptr, 1300, 1300);
	if (!data->img)
		error_intalis(&data);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, 
			&data->line_length, &data->endian);
	fontion_mlx_and_draw(&data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
