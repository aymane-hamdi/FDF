/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_map_con.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:22:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/20 15:15:14 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_line(t_fdf **data, char **line, char ***line_int, int *i)
{
	int		y;

	(*data)->width = get_width(*line, data);
	if ((*data)->min_with > (*data)->width)
	{
		free_line(*i, data);
		free(*line);
		error(data);
	}
	(*data)->matrix[*i] = malloc (((*data)->width + 1) * sizeof(char *));
	if ((*data)->matrix[*i] == NULL)
	{
		free_line(*i, data);
		free(*line);
		error(data);
	}
	*line_int = ft_split(*line);
	y = 0;
	while ((*line_int)[y])
		process_word(data, line_int, i, &y);
	free(*line_int);
	(*data)->matrix[*i][y] = NULL;
	(*i)++;
	free(*line);
	*line = get_next_line((*data)->fd);
}

void	process_word(t_fdf **data, char ***line_int, int *i, int *y)
{
	(*data)->matrix[*i][*y] = ft_strdup((*line_int)[*y]);
	if (ft_atoi((*line_int)[*y]) > (*data)->z_max)
		(*data)->z_max = ft_atoi((*line_int)[*y]);
	free((*line_int)[*y]);
	(*y)++;
}

void	cheke_map(char *argv, t_fdf **data)
{
	char	*str;

	str = ft_strrchr(argv, '.');
	if (!str || ft_strlen(str) != 4 || ft_strncmp(str, ".fdf", 4) != 0)
	{
		free(*data);
		ft_putstr_fd("invalid map\n", 2);
		exit(1);
	}
}

void	error(t_fdf **data)
{
	close((*data)->fd);
	free(*data);
	ft_putstr_fd("invalid map\n", 2);
	exit(1);
}

void	chek_line(char *line, t_fdf **data, int *j)
{
	char	**str;

	str = ft_split(line);
	if (!str)
	{
		free_line(*j, data);
		free(line);
		error(data);
	}
	if (!str[0])
	{
		free(line);
		free_line(*j, data);
		free_2d_erray(str);
		error(data);
	}
	free_2d_erray(str);
}
