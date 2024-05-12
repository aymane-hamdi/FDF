/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_keybord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:07:06 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/12 15:12:53 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	reset(int key, t_fdf **data)
{
	if (key == 15)
	{
		set_zoom(data);
		(*data)->angel_x = 0.863597;
		(*data)->angel_y = -0.040001;
		(*data)->angel_z = 18.039997;
	}
	return (0);
}

void	draw(t_fdf **data, int key)
{
	if ((*data)->form == 2)
	{
		draw_2d(data);
		draw_2d_inverce(data);
	}
	else
	{
		draw_3d(data);
		draw_3d_inverce(data);
	}
	if (key == 92 && (*data)->form == 2)
	{
		draw_2d(data);
	}
	if (key == 92 && (*data)->form == 3)
	{
		draw_3d(data);
	}
	print_menu(data);
}

void	mouve_haute(int key, t_fdf **data)
{
	if (key == 126)
		(*data)->mouv_haut -= 100;
	else if (key == 125)
		(*data)->mouv_haut += 100;
}

void	free_data(t_fdf **data)
{
	int	i;
	int	j;

	i = 0;
	if ((*data)->matrix != NULL)
	{
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
	free(*data);
}
