/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:12:43 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/15 16:35:34 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (is_sep(str[i]))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && !is_sep(str[i]))
			i++;
	}
	return (count);
}

int	get_width(char *line)
{
	int	width;

	width = ft_count_words(line);
	return (width);
}

int	get_height(char *argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		erre_fd();
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

void	invalid_argument(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <filename>\n", 2);
		exit(1);
	}
}

void	red_map(char *argv, t_fdf **data)
{
	int		i;
	char	*line;
	char	**line_int;

	cheke_map(argv, data);
	(*data)->height = get_height(argv);
	(*data)->matrix = malloc (((*data)->height + 1) * sizeof(char **));
	if ((*data)->matrix == NULL)
		exit(1);
	(*data)->fd = open(argv, O_RDONLY);
	if ((*data)->fd < 0)
		erre_fd();
	i = 0;
	line = get_next_line((*data)->fd);
	if (!line)
		error();
	line_int = ft_split(line);
	if (!*line_int)
		error();
	(*data)->width = (get_width(line));
	(*data)->min_with = (*data)->width;
	while (line)
		process_line(data, &line, &line_int, &i);
	(*data)->matrix[i] = NULL;
	close ((*data)->fd);
}
