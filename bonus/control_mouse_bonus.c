/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:27:59 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/17 19:24:05 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	print(void	*mlx, void	*win, int *y)
{
	mlx_string_put(mlx, win, 65, *y += 20, 0x00FF00FF, "HOW TO USE");
	mlx_string_put(mlx, win, 15, *y += 35, 0x000000FF, "ZOOM:");
	mlx_string_put(mlx, win, 90, *y, 0xEAEAEA, "+/-");
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
}

void	my_mlx_pixel_put(t_fdf **data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 1320 || y >= 1320)
		return ;
	dst = (*data)->addr + (y * (*data)->line_length 
			+ x * ((*data)->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	free_line(int pos, t_fdf **data)
{
	int	i;
	int	j;

	i = 0;
	while ((*data)->matrix[i])
	{
		if (i == pos)
			break ;
		j = 0;
		while ((*data)->matrix[i][j])
		{
			free((*data)->matrix[i][j]);
			j++; 
		}
		free((*data)->matrix[i]);
		i++;
	}
	free((*data)->matrix);
}
