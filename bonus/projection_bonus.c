/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:27:04 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/02 21:49:20 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_z(t_fdf**data)
{
	double	x1_temp;
	double	x2_temp;

	x1_temp = (*data)->x1;
	(*data)->x1 = ((*data)->x1 * cos((*data)->angel_z)) 
		- ((*data)->y1 * sin((*data)->angel_z));
	(*data)->y1 = x1_temp * sin((*data)->angel_z) 
		+ ((*data)->y1 * cos((*data)->angel_z));
	x2_temp = (*data)->x2;
	(*data)->x2 = ((*data)->x2 * cos((*data)->angel_z)) 
		- ((*data)->y2 * sin((*data)->angel_z));
	(*data)->y2 = x2_temp * sin((*data)->angel_z) 
		+ ((*data)->y2 * cos((*data)->angel_z));
}

void	rotate_y(t_fdf**data)
{
	float	x1_temp;
	float	x2_temp;

	x1_temp = (*data)->x1;
	(*data)->x1 = (*data)->x1 * cos((*data)->angel_y) + 
		(*data)->z1 * sin((*data)->angel_y);
	(*data)->z1 = -x1_temp * sin((*data)->angel_y) + 
		(*data)->z1 * cos((*data)->angel_y);
	x2_temp = (*data)->x2;
	(*data)->x2 = (*data)->x2 * cos((*data)->angel_y) + 
		(*data)->z2 * sin((*data)->angel_y);
	(*data)->z2 = -x2_temp * sin((*data)->angel_y) + 
		(*data)->z2 * cos((*data)->angel_y);
}

void	rotate_x(t_fdf**data)
{
	float	y1_temp;
	float	y2_temp;

	y1_temp = (*data)->y1;
	(*data)->y1 = ((*data)->y1 * cos((*data)->angel_x)) 
		- ((*data)->z1 * sin((*data)->angel_x));
	(*data)->z1 = (y1_temp * sin((*data)->angel_x)) 
		+ ((*data)->z1 * cos((*data)->angel_x));
	y2_temp = (*data)->y2;
	(*data)->y2 = ((*data)->y2 * cos((*data)->angel_x)) 
		- ((*data)->z2 * sin((*data)->angel_x));
	(*data)->z2 = (y2_temp * sin((*data)->angel_x)) 
		+ ((*data)->z2 * cos((*data)->angel_x));
}

int	len_str(char **str)
{
	int	i;

	i = 0;
	while (str[i]!= NULL)
		i++;
	return (i);
}
