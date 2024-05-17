/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:16:23 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/17 19:11:54 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_2d_erray(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_line(int pos, t_fdf **data)
{
	int	i;
	int	j;

	i = 0;
	while ((*data)->matrix[i])
	{
		if (i == pos)
			break ;
		j = 0;
		while ((*data)->matrix[i][j])
		{
			free((*data)->matrix[i][j]);
			j++; 
		}
		free((*data)->matrix[i]);
		i++;
	}
	free((*data)->matrix);
}

void	free_3d_char_array(t_fdf **data)
{
	int	i;
	int	j;

	i = 0;
	while ((*data)->matrix[i])
	{
		j = 0;
		while ((*data)->matrix[i][j])
		{
			free((*data)->matrix[i][j]);
			j++; 
		}
		free((*data)->matrix[i]);
		i++;
	}
	free((*data)->matrix);
}

void	dd(t_fdf **data)
{
	draw_dda(data);
	trasformation(data);
	printf("%f\n",(*data)->x1);
	(*data)->x_max = fmaxf ((*data)->x_max, (*data)->x1);
	(*data)->y_max = fmaxf((*data)->y_max, (*data)->y1);
	(*data)->x1 = (*data)->color_start_x;
	(*data)->x2 = (*data)->color_end_x;
	(*data)->y1 = (*data)->color_start_y;
	(*data)->y2 = (*data)->color_end_y;
}

void	get_max_x_and_y(t_fdf **data)
{
	(*data)->y1 = 0;
	(*data)->x_max = -34.8045265148;
	(*data)->y_max = -34.8045265148;
	while ((*data)->y1 < (*data)->height)
	{
		(*data)->x1 = 0;
		(*data)->width = len_str((*data)->matrix[(int)(*data)->y1]);
		while ((*data)->x1 < (*data)->width)
		{
			(*data)->x2 = (*data)->x1 + 1;
			(*data)->y2 = (*data)->y1;
			if ((*data)->matrix[(int)(*data)->y1][(int)(*data)->x1 + 1])
				dd(data);
			(*data)->y2 = (*data)->y1 + 1;
			(*data)->x2 = (*data)->x1;
			if ((*data)->matrix[(int)(*data)->y1 + 1])
				dd(data);
			(*data)->x1++;
		}
		(*data)->y1++;
	}
	set_zoom(data);
}
