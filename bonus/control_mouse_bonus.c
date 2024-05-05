/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:27:59 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/05 16:57:26 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	print_menu(t_fdf **data)
{
	int	img_width;
	int	img_height;

	
}

int	mouse_press(int key, int x, int y, t_fdf **data)
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
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img_print);
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
