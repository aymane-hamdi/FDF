/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawin_3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:58:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/06 17:24:27 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trasformation(t_fdf **data)
{
	int		tmp_x1;
	int		tmp_x2;
	double	angle;

	angle = 30 * M_PI / 180;
	tmp_x1 = (*data)->x1;
	(*data)->x1 = (tmp_x1 - (*data)->y1) * cos(angle);
	(*data)->y1 = (tmp_x1 + (*data)->y1) * sin(angle) - (*data)->z1;
	tmp_x2 = (*data)->x2;
	(*data)->x2 = (tmp_x2 - (*data)->y2) * cos(angle);
	(*data)->y2 = (tmp_x2 + (*data)->y2) * sin(angle) - (*data)->z2;
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
	(*data)->img = mlx_new_image((*data)->mlx_ptr, 2000, 2000);
	while ((*data)->y1 < (*data)->height)
	{
		(*data)->x1 = 0;
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
