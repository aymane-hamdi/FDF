/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:12:43 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/03 15:45:04 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	ft_count_words(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == sep)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (count);
}

int	get_width(char *line)
{
	int	width;

	width = ft_count_words(line, ' ');
	return (width);
}

int	get_height(char *argv)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	red_map(char *argv, t_fdf **data)
{
	int		i;
	int		y;
	char	*line;
	char	**line_int;
	int		fd;
	int		z_max;

	y = 0;
	z_max = 0;
	i = 0;
	(*data)->height = get_height(argv);
	(*data)->matrix = malloc (((*data)->height + 1) * sizeof(char **));
	fd = open(argv, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		(*data)->width = (get_width(line));
		(*data)->matrix[i] = malloc (((*data)->width + 1) * sizeof(char *));
		line_int = ft_split(line, ' ');
		y = 0;
		while (line_int[y])
		{
			if (ft_strchr(line_int[y], '\n') != NULL)
				line_int[y][ft_strlen(line_int[y]) - 1] = '\0';
			(*data)->matrix[i][y] = ft_strdup(line_int[y]);
			if (ft_atoi(line_int[y]) > z_max)
				z_max = ft_atoi(line_int[y]);
			free(line_int[y]);
			y++;
		}
		free(line_int);
		(*data)->matrix[i][y] = NULL;
		i++;
		free(line);
		line = get_next_line(fd);
	}
	(*data)->matrix[i] = NULL;
	(*data)->z_max = z_max;
	close (fd);
}

int	hexToInt(const char *hex)
{
    return ((int) strtol(hex, NULL, 16));
}
