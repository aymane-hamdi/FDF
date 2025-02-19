/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:50:07 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/20 15:19:22 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	get_width(char *line, t_fdf **data)
{
	int	width;

	if (!line)
	{
		free((*data)->matrix);
		close((*data)->fd);
		free(*data);
		ft_putstr_fd("invalid map\n", 2);
		exit(1);
	}
	width = ft_count_words(line);
	return (width);
}

int	get_height(char *argv, t_fdf **data)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit_err_fd(data);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		free(*data);
		ft_putstr_fd("invalid map\n", 2);
		exit(1);
	}
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
	(*data)->height = get_height(argv, data);
	(*data)->fd = open(argv, O_RDONLY);
	if ((*data)->fd < 0)
		exit_err_fd(data);
	(*data)->matrix = malloc (((*data)->height + 1) * sizeof(char **));
	if ((*data)->matrix == NULL)
		error(data);
	i = 0;
	line = get_next_line((*data)->fd);
	(*data)->width = (get_width(line, data));
	(*data)->min_with = (*data)->width;
	while (line)
	{
		chek_line(line, data, &i);
		process_line(data, &line, &line_int, &i);
	}
	(*data)->matrix[i] = NULL;
	close ((*data)->fd);
}
