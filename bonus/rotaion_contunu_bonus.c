/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotaion_contunu_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:10:45 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/27 22:18:03 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf_bonus.h"

int rotate_object_z(fdf **data)
{
	if((*data)->key == 1)
	{
		mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
    	(*data)->angel_z += 0.02;
		draw_3D(data); 
    	print_menu(*data);
	}
	return (0);
}
int rotate_object_y(fdf **data)
{
	if((*data)->key == 1)
	{
		mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
    	(*data)->angel_y += 0.02;
		draw_3D(data); 
    	print_menu(*data);
	}
	return (0);
}
int rotate_object_x(fdf **data)
{
	if((*data)->key == 1)
	{
		mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
    	(*data)->angel_x += 0.02;
		draw_3D(data); 
    	print_menu(*data);
	}
	return (0);
}