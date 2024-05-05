/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_map_con_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:39:53 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/05 15:21:20 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	process_line(t_fdf **data, char **line, char ***line_int, int *i)
{
	int		y;

	(*data)->matrix[*i] = malloc (((*data)->width + 1) * sizeof(char *));
	*line_int = ft_split(*line, ' ');
	if (ft_count_words(*line, ' ') != (*data)->width)
		error(data);
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
	if (ft_strchr((*line_int)[*y], '\n') != NULL)
		(*line_int)[*y][ft_strlen((*line_int)[*y]) - 1] = '\0';
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
	if (!str)
		error(data);
	if (ft_strncmp(str, ".fdf", ft_strlen(".fdf")) != 0)
	{
		ft_putstr_fd("invalid map\n", 2);
		free_data(data);
		exit(1);
	}
}

void	error(t_fdf **data)
{
	ft_putstr_fd("invalid map\n", 2);
	free_data(data);
	exit(1);
}

int	hexto_int(const char *hex)
{
	return ((int)strtol(hex, NULL, 16));
}
