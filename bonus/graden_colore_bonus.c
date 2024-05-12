/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graden_colore_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:32:16 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/12 15:01:42 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_Color	int_to_color(unsigned int rgb)
{
	t_Color	color;

	color.r = (rgb >> 16) & 0xFF;
	color.g = (rgb >> 8) & 0xFF;
	color.b = rgb & 0xFF;
	return (color);
}

unsigned int	get_gradient(unsigned int start_int, 
	unsigned int end_int, double ratio)
{
	t_Color			start;
	t_Color			end;
	int				r;
	int				g;
	int				b;

	start = int_to_color(start_int);
	end = int_to_color(end_int);
	r = (int)(start.r + ratio * (end.r - start.r));
	g = (int)(start.g + ratio * (end.g - start.g));
	b = (int)(start.b + ratio * (end.b - start.b));
	return ((r << 16) | (g << 8) | b);
}

void	intianl(t_fdf *data, float *ratio)
{
	int		max;
	int		min;
	int		value;

	if ((data->x2 - data->start_x) > (data->y2 - data->start_y))
	{
		value = data->x1;
		min = data->start_x;
		max = data->x2;
	}
	else
	{
		value = data->y1;
		min = data->start_y;
		max = data->y2;
	}
	*ratio = (value - min) / (float)(max - min);
}

int	get_color_3d(t_fdf **data)
{
	int		color1;
	int		color2; 
	int		start_color;
	int		end_color;
	float	ratio;

	intianl(*data, &ratio);
	start_color = ft_atoi((*data)->matrix[(*data)->color_start_y]
		[(*data)->color_start_x]);
	end_color = ft_atoi((*data)->matrix[(*data)->color_end_y]
		[(*data)->color_end_x]);
	if (start_color != 0)
		color1 = 16711680;
	else
		color1 = 16777215;
	if (end_color != 0)
		color2 = 16711680;
	else
		color2 = 16777215;
	return (get_gradient(color1, color2, ratio));
}
