/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotaion_contunu_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:10:45 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/17 15:14:59 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	rotate_object_z(t_fdf **data)
{
	if ((*data)->key == 1)
	{
		mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
		mlx_destroy_image((*data)->mlx_ptr, (*data)->img);
		(*data)->angel_z += 0.02;
		draw_3d(data);
		draw_3d_inverce(data); 
		print_menu(data);
	}
	return (0);
}

int	rotate_object_y(t_fdf **data)
{
	if ((*data)->key == 1)
	{
		mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
		mlx_destroy_image((*data)->mlx_ptr, (*data)->img);
		(*data)->angel_y += 0.02;
		draw_3d(data);
		draw_3d_inverce(data); 
		print_menu(data);
	}
	return (0);
}

int	rotate_object_x(t_fdf **data)
{
	if ((*data)->key == 1)
	{
		mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
		mlx_destroy_image((*data)->mlx_ptr, (*data)->img);
		(*data)->angel_x += 0.02;
		draw_3d(data);
		draw_3d_inverce(data);
		print_menu(data);
	}
	return (0);
}

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

void	chek_line(char *line, t_fdf **data)
{
	int		i;
	char	**str;

	if (!line)
		error();
	str = ft_split(line);
	i = 0;
	if (!*str)
	{
		free_2d_erray(str);
		free(data);
		error();
	}
	free_2d_erray(str);
}
