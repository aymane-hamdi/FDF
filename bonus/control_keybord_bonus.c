/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keybord_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:01:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/10 11:58:37 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	autour_continu(int key, t_fdf **data)
{
	if (key == 86)
	{
		(*data)->key = 1;
		mlx_loop_hook((*data)->mlx_ptr, rotate_object_x, data);
	}
	if (key == 87)
	{
		(*data)->key = 1;
		mlx_loop_hook((*data)->mlx_ptr, rotate_object_y, data);
	}
	if (key == 88)
	{
		(*data)->key = 1;
		mlx_loop_hook((*data)->mlx_ptr, rotate_object_z, data);
	}
	return (0);
}

int	autour_pres(int key, t_fdf **data)
{
	autour_continu(key, data);
	if (key == 257)
		change_colore(data);
	else if (key == 2)
		(*data)->angel_x -= 0.2;
	else if (key == 32)
		(*data)->angel_y -= 0.2;
	else if (key == 7)
		(*data)->angel_x += 0.2;
	else if (key == 16)
		(*data)->angel_y += 0.2;
	if (key == 49) 
		(*data)->key = 0;
	if (key == 0)
		(*data)->angel_z -= 0.2;
	if (key == 6)
		(*data)->angel_z += 0.2;
	return (0);
}

void	zoom(int key, t_fdf **data)
{
	if (key == 69)
		(*data)->zoom += 1;
	else if (key == 78)
	{
		(*data)->zoom -= 1;
		if ((*data)->zoom < 2)
			(*data)->zoom = 1;
	}
}

void	mouv_cote(int key, t_fdf **data)
{
	if (key == 124)
		(*data)->mov_cote += 100;
	if (key == 123)
		(*data)->mov_cote -= 100;
}

int	key_press(int key, t_fdf **data)
{
	reset(key, data);
	autour_pres(key, data);
	if (key == 53)
		close_window(data);
	else if (key == 116)
		(*data)->h += 1;
	else if (key == 121)
		(*data)->h -= 1;
	else if (key == 84)
		(*data)->form = 2;
	else if (key == 85)
		(*data)->form = 3; 
	if (key == 8)
		(*data)->color_change = 16777216;
	else if (key == 9)
		(*data)->color_change = 16777215;
	mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
	mlx_destroy_image((*data)->mlx_ptr, (*data)->img);
	zoom(key, data);
	mouv_cote(key, data);
	mouve_haute(key, data);
	draw(data, key);
	return (0);
}
