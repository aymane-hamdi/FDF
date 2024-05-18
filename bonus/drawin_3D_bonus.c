/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawin_3D_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:58:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/18 10:09:08 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	trasformation(t_fdf **data)
{
	rotate_z(data, (*data)->angel_z);
	rotate_y(data, (*data)->angel_y);
	rotate_x(data, (*data)->angel_x);
}

void	draw_dda(t_fdf **data)
{
	(*data)->z1 = ft_atoi((*data)->matrix[(int)(*data)->y1][(int)(*data)->x1]);
	(*data)->z2 = ft_atoi((*data)->matrix[(int)(*data)->y2][(int)(*data)->x2]);
	if ((*data)->z1 != 0)
		(*data)->z1 += (*data)->h;
	if ((*data)->z2 != 0)
		(*data)->z2 += (*data)->h;
	(*data)->color_start_x = (int)(*data)->x1;
	(*data)->color_start_y = (int)(*data)->y1;
	(*data)->color_end_x = (int)(*data)->x2;
	(*data)->color_end_y = (int)(*data)->y2;
}

void	dda(t_fdf **data)
{
	double		x_step;
	double		y_step;
	double		max;
	double		abs_x_step;
	double		abs_y_step;

	draw_dda(data);
	center_and_zoom(data);
	trasformation(data);
	x_step = (*data)->x2 - (*data)->x1;
	y_step = (*data)->y2 - (*data)->y1;
	abs_x_step = fabs(x_step);
	abs_y_step = fabs(y_step);
	max = fmaxf(abs_x_step, abs_y_step);
	x_step /= max;
	y_step /= max;
	(*data)->start_x = (*data)->x1;
	(*data)->start_y = (*data)->y1;
	while_loop(data, x_step, y_step);
}

void	draw_3d(t_fdf **data)
{
	(*data)->y1 = 0;
	creat_img(data);
	while ((*data)->y1 < (*data)->height)
	{
		(*data)->x1 = 0;
		(*data)->width = len_str((*data)->matrix[(int)(*data)->y1]);
		while ((*data)->x1 < (*data)->width)
		{
			(*data)->x2 = (*data)->x1 + 1;
			(*data)->y2 = (*data)->y1;
			if ((*data)->matrix[(int)(*data)->y1][(int)(*data)->x1 + 1])
				dda(data);
			(*data)->y2 = (*data)->y1 + 1;
			(*data)->x2 = (*data)->x1;
			if ((*data)->matrix[(int)(*data)->y1 + 1])
				dda(data);
			(*data)->x1++;
		}
		(*data)->y1++;
	}
	mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr, 
		(*data)->img, 0, 0);
}

void	draw_3d_inverce(t_fdf **data)
{
	(*data)->y1 = 0;
	while ((*data)->y1 + 1 < (*data)->height)
	{
		(*data)->x1 = 0;
		(*data)->width = len_str((*data)->matrix[(int)(*data)->y1]);
		while ((*data)->x1 + 1 < (*data)->width)
		{
			(*data)->x2 = (*data)->x1 + 1;
			(*data)->y2 = (*data)->y1 + 1;
			if ((*data)->matrix[(int)(*data)->y2][(int)(*data)->x2])
				dda(data);
			(*data)->y2 = (*data)->y1 - 1;
			(*data)->x2 = (*data)->x1 + 1;
			if ((*data)->y2 >= 0 
				&& (*data)->matrix[(int)(*data)->y2][(int)(*data)->x2])
				dda(data);
			(*data)->x1++;
		}
		(*data)->y1++;
	}
	mlx_put_image_to_window((*data)->mlx_ptr, 
		(*data)->win_ptr, (*data)->img, 0, 0);
}
