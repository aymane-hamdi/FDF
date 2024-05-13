/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:38 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/13 18:26:12 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void leaks(void)
{
	system("leaks fdf");
}
void	set_zoom(t_fdf **data)
{
	int	x_zoom;
	int	y_zoom;

	(*data)->zoom = fminf(((*data)->width_window) / (*data)->width / 2, 
			(*data)->height_window / (*data)->height / 2);
	(*data)->mov_cote = ((*data)->width_window) / 2 ;
	(*data)->mouv_haut = ((*data)->height_window) / 2 + 200;
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
	(*data)->width_window = 1080;
	(*data)->height_window = 1080;
	(*data)->form = 3;
	set_zoom(data);
	(*data)->argv = argv;
	(*data)->angel_x = 0.863597;
	(*data)->angel_y = -0.040001;
	(*data)->angel_z = 18.039997;
}

void	fontion_mlx_and_draw(t_fdf **data)
{
	int		img_width;
	int		img_height;
	void	*img_ptr;

	draw_3d(data);
	mlx_key_hook((*data)->win_ptr, key_press, data);
	mlx_hook((*data)->win_ptr, 17, 0, close_window, data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	atexit(leaks);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->mlx_ptr = mlx_init();
	red_map(argv[1], &data);
	initial_data(&data, argv);
	if (data->mlx_ptr == NULL)
	{
		ft_putstr_fd("Failed to initialize mlx.\n", 2);
		free_data(&data);
		exit (1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width_window,
			data->height_window, "t_fdf project");
	if (data->win_ptr == NULL)
	{
		ft_putstr_fd("Failed to create a new window.\n", 2);
		free(data); 
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	fontion_mlx_and_draw(&data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
