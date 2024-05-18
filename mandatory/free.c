/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:16:23 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/17 21:07:56 by ahamdi           ###   ########.fr       */
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
