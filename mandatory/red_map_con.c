/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_map_con.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:22:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/13 17:53:35 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_line(t_fdf **data, char **line, char ***line_int, int *i)
{
	int		y;

	if ((*data)->width > get_width(*line))
		error();
	(*data)->matrix[*i] = malloc (((*data)->width + 1) * sizeof(char *));
	if ((*data)->matrix[*i] == NULL)
		exit(1);
	*line_int = ft_split(*line, ' ');
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

void	cheke_map(char *argv)
{
	char	*str;

	str = ft_strrchr(argv, '.');
	if (!str)
		error();
	if (ft_strncmp(str, ".fdf", ft_strlen(str)))
		error();
}

void	error(void)
{
	ft_putstr_fd("invalid map\n", 2);
	exit(1);
}
