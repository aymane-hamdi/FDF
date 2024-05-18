/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graden_colore.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:32:16 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/18 10:25:24 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_Color	int_to_rgb(unsigned int rgb)
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
	t_Color	start;
	t_Color	rend;
	int		r;
	int		g;
	int		b;

	start = int_to_rgb(start_int);
	rend = int_to_rgb(end_int);
	r = (int)(start.r + ratio * (rend.r - start.r));
	g = (int)(start.g + ratio * (rend.g - start.g));
	b = (int)(start.b + ratio * (rend.b - start.b));
	return ((r << 16) | (g << 8) | b);
}

void	my_mlx_pixel_put(t_fdf **data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 1300 || y >= 1300)
		return ;
	dst = (*data)->addr + (y * (*data)->line_length + 
			x * ((*data)->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
