/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:27:59 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/14 10:37:44 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	print(void	*mlx, void	*win, int *y)
{
	mlx_string_put(mlx, win, 65, *y += 20, 0x00FF00FF, "HOW TO USE");
	mlx_string_put(mlx, win, 15, *y += 35, 0x000000FF, "ZOOM:");
	mlx_string_put(mlx, win, 90, *y, 0xEAEAEA, "Scroll or +/-");
}

void	print_menu(t_fdf **data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = (*data)->mlx_ptr;
	win = (*data)->win_ptr;
	print(mlx, win, &y);
	mlx_string_put(mlx, win, 15, y += 35, 0x000000FF, "RESET:");
	mlx_string_put(mlx, win, 90, y, 0xEAEAEA, "R Key");
	mlx_string_put(mlx, win, 15, y += 30, 0x000000FF, "Move");
	mlx_string_put(mlx, win, 90, y, 0xEAEAEA, "< / >");
	mlx_string_put(mlx, win, 15, y += 30, 0x000000FF, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, 0xEAEAEA, "X-Axis - X/D (4)");
	mlx_string_put(mlx, win, 57, y += 25, 0xEAEAEA, "Y-Axis - Y/U (5)");
	mlx_string_put(mlx, win, 57, y += 25, 0xEAEAEA, "Z-Axis - Z/A (6)");
	mlx_string_put(mlx, win, 15, y += 30, 0x000000FF, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, 0xEAEAEA, "ISO: 3 Key");
	mlx_string_put(mlx, win, 57, y += 25, 0xEAEAEA, "Parallel: 2 Key");
	mlx_string_put(mlx, win, 15, y += 30, 0x000000FF, "color");
	mlx_string_put(mlx, win, 57, y += 25, 
		0xEAEAEA, "change color: SHIFT Key");
}

int	mouse_press(int key, t_fdf **data)
{
	if (key == 4)
	{
		(*data)->zoom -= 1;
		if ((*data)->zoom < 2)
			(*data)->zoom = 1;
	}
	else if (key == 5)
		(*data)->zoom += 1;
	mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img);
	if ((*data)->form == 2)
	{
		draw_2d(data);
		draw_2d_inverce(data);
	}
	else
	{
		draw_3d(data);
		draw_3d_inverce(data);
	}
	print_menu(data);
	return (0);
}

void	my_mlx_pixel_put(t_fdf **data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 2000 || y >= 2000)
		return ;
	(*data)->addr = mlx_get_data_addr((*data)->img,
			&(*data)->bits_per_pixel, &(*data)->line_length, &(*data)->endian);
	dst = (*data)->addr + (y * (*data)->line_length 
			+ x * ((*data)->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
