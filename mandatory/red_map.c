/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:50:07 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/08 10:36:00 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_words(char const *str, char sep)
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

	i = 0;
	fd = open(argv, O_RDONLY);
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

static void	invalid_argument(char *argv)
{
	if (!argv)
	{
		ft_putstr_fd("invalid argument\n", 2);
		ft_putstr_fd("EX : ./fdf map\n", 2);
		exit(1);
	}
}

void	red_map(char *argv, t_fdf **data)
{
	int		i;
	int		y;
	char	*line;
	char	**line_int;
	int		fd;

	invalid_argument(argv);
	cheke_map(argv);
	(*data)->height = get_height(argv);
	(*data)->matrix = malloc (((*data)->height + 1) * sizeof(char **));
	if ((*data)->matrix == NULL)
		exit(1);
	(*data)->fd = open(argv, O_RDONLY);
	if (fd < 0)
		error();
	i = 0;
	line = get_next_line((*data)->fd);
	if (!line)
		error();
	(*data)->width = (get_width(line));
	while (line)
		process_line(data, &line, &line_int, &i);
	(*data)->matrix[i] = NULL;
	close ((*data)->fd);
}
