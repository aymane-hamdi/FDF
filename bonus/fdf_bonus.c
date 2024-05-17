/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:38 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/17 19:24:49 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void leaks(void)
{
	system("leaks fdf_bonus");
}
void	set_zoom(t_fdf **data)
{
	(*data)->zoom = fminf(((*data)->width_window) / (*data)->width / 2, 
			(*data)->height_window / (*data)->height / 2);
	(*data)->mov_cote = ((*data)->width_window) / 2 ;
	(*data)->mouv_haut = ((*data)->height_window) / 2 + 100;
}

int	close_window(t_fdf**data)
{
	mlx_destroy_window((*data)->mlx_ptr, (*data)->win_ptr);
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img);
	free_data(data);
	ft_putstr_fd(" close window", 1);
	exit(0); 
}

void	initial_data(t_fdf **data, char **argv)
{
	(*data)->width_window = 1320;
	(*data)->height_window = 1320;
	(*data)->form = 3;
	set_zoom(data);
	(*data)->argv = argv;
	(*data)->h = 0;
	(*data)->angel_x = 48 * M_PI / 180;
	(*data)->angel_y = 1 * M_PI / 180;
	(*data)->angel_z = 30 * M_PI / 180;
}

void	fontion_mlx_and_draw(t_fdf**data)
{
	draw_3d(data);
	draw_3d_inverce(data);
	print_menu(data); 
	mlx_key_hook((*data)->win_ptr, key_press, data);
	mlx_hook((*data)->win_ptr, 17, 0, close_window, data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	atexit(leaks);
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
	data->img = mlx_new_image(data->mlx_ptr, 1080, 1080);
	if (!data->img)
		error_intalis(&data);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, 
			&data->line_length, &data->endian);
	fontion_mlx_and_draw(&data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

