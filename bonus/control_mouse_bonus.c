/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:27:59 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/03 11:50:12 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	print_menu(t_fdf **data)
{
	int	img_width;
	int	img_height;

	(*data)->img_print = mlx_xpm_file_to_image((*data)->mlx_ptr,
			"bonus/X-Axis-rotation-_1_.xpm", &img_width, &img_height);
	if ((*data)->img_print == NULL)
	{
		ft_putstr_fd("Failed to load background image.\n", 2);
		return ;
	}
	mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr, 
		(*data)->img_print, 0, 0);
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
