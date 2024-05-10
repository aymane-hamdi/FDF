/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotaion_contunu_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:10:45 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/10 11:59:41 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	rotate_object_z(t_fdf **data)
{
	if ((*data)->key == 1)
	{
		mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
		mlx_destroy_image((*data)->mlx_ptr, (*data)->img);
		(*data)->angel_z += 0.02;
		draw_3d(data);
		draw_3d_inverce(data); 
		print_menu(data);
	}
	return (0);
}

int	rotate_object_y(t_fdf **data)
{
	if ((*data)->key == 1)
	{
		mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
		mlx_destroy_image((*data)->mlx_ptr, (*data)->img);
		(*data)->angel_y += 0.02;
		draw_3d(data);
		draw_3d_inverce(data); 
		print_menu(data);
	}
	return (0);
}

int	rotate_object_x(t_fdf **data)
{
	if ((*data)->key == 1)
	{
		mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
		mlx_destroy_image((*data)->mlx_ptr, (*data)->img);
		(*data)->angel_x += 0.02;
		draw_3d(data);
		draw_3d_inverce(data);
		print_menu(data);
	}
	return (0);
}

int	rgb_to_number(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}
