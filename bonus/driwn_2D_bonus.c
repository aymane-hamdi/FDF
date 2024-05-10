/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driwn_2D_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:37:31 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/10 12:42:17 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	center_and_zoom(t_fdf **data)
{
	double	new_with;
	double	new_height;

	new_with = (*data)->width / 2;
	new_height = (*data)->height / 2;
	(*data)->x1 = ((*data)->x1 - new_with) * (*data)->zoom;
	(*data)->y1 = ((*data)->y1 - new_height) * (*data)->zoom;
	(*data)->x2 = ((*data)->x2 - new_with) * (*data)->zoom;
	(*data)->y2 = ((*data)->y2 - new_height) * (*data)->zoom;
	if ((*data)->z_max <= 50)
	{
		(*data)->z1 *= (*data)->zoom;
		(*data)->z2 *= (*data)->zoom;
	}
}

void	while_loop(t_fdf **data, double x_step, double y_step)
{
	int		color;

	while ((x_step > 0 && (*data)->x1 <= (*data)->x2)
		|| (x_step < 0 && (*data)->x1 >= (*data)->x2)
		|| (y_step > 0 && (*data)->y1 <= (*data)->y2)
		|| (y_step < 0 && (*data)->y1 >= (*data)->y2))
	{
		if (ft_strchr((*data)->matrix[(*data)->color_start_y]
				[(*data)->color_start_x], ',') != NULL)
			color = hexto_int(ft_strchr((*data)->matrix[(*data)->color_start_y]
					[(*data)->color_start_x], ',') + 1);
		else
			color = get_color_3d(data);
		my_mlx_pixel_put(data, (*data)->x1 + (*data)->mov_cote,
			(*data)->y1 + (*data)->mouv_haut, color);
		(*data)->x1 += x_step;
		(*data)->y1 += y_step;
	}
	(*data)->x1 = (*data)->color_start_x;
	(*data)->x2 = (*data)->color_end_x;
	(*data)->y1 = (*data)->color_start_y;
	(*data)->y2 = (*data)->color_end_y;
}

void	dda_2d(t_fdf **data)
{
	double	x_step;
	double	y_step;
	double	abs_x_step;
	double	abs_y_step;

	draw_dda(data);
	center_and_zoom(data);
	x_step = (*data)->x2 - (*data)->x1;
	y_step = (*data)->y2 - (*data)->y1;
	abs_x_step = fabs(x_step);
	abs_y_step = fabs(y_step);
	x_step /= fmaxf(abs_x_step, abs_y_step);
	y_step /= fmaxf(abs_x_step, abs_y_step);
	(*data)->start_x = (*data)->x1;
	(*data)->start_y = (*data)->y1;
	while_loop(data, x_step, y_step);
}

void	draw_2d(t_fdf **data)
{
	(*data)->y1 = 0;
	(*data)->img = mlx_new_image((*data)->mlx_ptr, 2000, 2000);
	while ((*data)->y1 < (*data)->height)
	{
		(*data)->x1 = 0;
		while ((*data)->x1 < (*data)->width)
		{
			(*data)->x2 = (*data)->x1 + 1;
			(*data)->y2 = (*data)->y1;
			if ((*data)->matrix[(int)(*data)->y1][(int)(*data)->x1 + 1])
				dda_2d(data);
			(*data)->y2 = (*data)->y1 + 1;
			(*data)->x2 = (*data)->x1;
			if ((*data)->matrix[(int)(*data)->y1 + 1])
				dda_2d(data);
			(*data)->x1++;
		}
		(*data)->y1++;
	}
	mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr, 
		(*data)->img, 0, 0);
}

void	draw_2d_inverce(t_fdf **data)
{
	(*data)->y1 = 0;
	while ((*data)->y1 < (*data)->height)
	{
		(*data)->x1 = 0;
		while ((*data)->x1 < (*data)->width)
		{
			(*data)->x2 = (*data)->x1 + 1;
			(*data)->y2 = (*data)->y1 + 1;
			if ((*data)->y1 + 1 < (*data)->height
				&& (*data)->x1 + 1 < (*data)->width
				&& (*data)->matrix[(int)(*data)->y2][(int)(*data)->x2])
				dda_2d(data);
			if ((*data)->y1 - 1 >= 0)
			{
				(*data)->y2 = (*data)->y1 - 1;
				(*data)->x2 = (*data)->x1 + 1;
				if ((*data)->matrix[(int)(*data)->y2][(int)(*data)->x2])
					dda_2d(data);
			}
			(*data)->x1++;
		}
		(*data)->y1++;
	}
	mlx_put_image_to_window((*data)->mlx_ptr, 
		(*data)->win_ptr, (*data)->img, 0, 0);
}
