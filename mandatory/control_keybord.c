/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keybord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:01:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/17 10:31:01 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int key, t_fdf **data)
{
	if (key == 53)
		close_window(data);
	return (0);
}

void	center_and_zoom(t_fdf **data)
{
	double	new_with;
	double	new_height;

	new_with = (*data)->width / 2;
	new_height = (*data)->height / 2;
	if ((*data)->z_max < 20)
	{
		(*data)->x1 = ((*data)->x1 - new_with) * (*data)->zoom;
		(*data)->y1 = ((*data)->y1 - new_height) * (*data)->zoom;
		(*data)->x2 = ((*data)->x2 - new_with) * (*data)->zoom;
		(*data)->y2 = ((*data)->y2 - new_height) * (*data)->zoom;
		(*data)->z1 *= (*data)->zoom;
		(*data)->z2 *= (*data)->zoom;
	}
	else
	{
		(*data)->x1 = ((*data)->x1 - new_with) * (*data)->zoom / 2;
		(*data)->y1 = ((*data)->y1 - new_height) * (*data)->zoom / 2;
		(*data)->x2 = ((*data)->x2 - new_with) * (*data)->zoom / 2;
		(*data)->y2 = ((*data)->y2 - new_height) * (*data)->zoom / 2;
		(*data)->z1 *= (*data)->zoom / 2;
		(*data)->z2 *= (*data)->zoom / 2;
	}
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

void	free_data(t_fdf **data)
{
	free_3d_char_array(data);
	free(*data);
}

int	hexto_int(const char *hex)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (hex[i])
	{
		result *= 16;
		if (hex[i] >= '0' && hex[i] <= '9' )
			result += hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			result += hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			result += hex[i] - 'A' + 10;
		i++;
	}
	return (result);
}
