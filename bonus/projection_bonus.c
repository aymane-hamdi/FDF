/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:27:04 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/17 19:22:51 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_x(t_fdf **data, double angle)
{
	int	y1;
	int	z1;
	int	y2;
	int	z2;

	y1 = (*data)->y1;
	z1 = (*data)->z1;
	y2 = (*data)->y2;
	z2 = (*data)->z2;
	(*data)->y1 = y1 * cos(angle) - z1 * sin(angle);
	(*data)->z1 = y1 * sin(angle) + z1 * cos(angle);
	(*data)->y2 = y2 * cos(angle) - z2 * sin(angle);
	(*data)->z2 = y2 * sin(angle) + z2 * cos(angle);
}

void	rotate_y(t_fdf **data, double angle)
{
	int	x1;
	int	z1;
	int	x2;
	int	z2;

	x1 = (*data)->x1;
	z1 = (*data)->z1;
	x2 = (*data)->x2;
	z2 = (*data)->z2;
	(*data)->x1 = x1 * cos(angle) + z1 * sin(angle);
	(*data)->z1 = z1 * cos(angle) - x1 * sin(angle);
	(*data)->x2 = x2 * cos(angle) + z2 * sin(angle);
	(*data)->z2 = z2 * cos(angle) - x2 * sin(angle);
}

void	rotate_z(t_fdf **data, double angle)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = (*data)->x1;
	y1 = (*data)->y1;
	x2 = (*data)->x2;
	y2 = (*data)->y2;
	(*data)->x1 = x1 * cos(angle) - y1 * sin(angle);
	(*data)->y1 = x1 * sin(angle) + y1 * cos(angle);
	(*data)->x2 = x2 * cos(angle) - y2 * sin(angle);
	(*data)->y2 = x2 * sin(angle) + y2 * cos(angle);
}

int	len_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	exit_err_fd(t_fdf **data)
{
	free(*data);
	ft_putstr_fd("error in open fd\n", 2);
	exit(1);
}
