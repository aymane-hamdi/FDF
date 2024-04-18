/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:27:59 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/18 16:56:02 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	print_menu3D(fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;
	char *zom;
	char *z;
    zom = ft_itoa(data->zoom);
    zom = ft_strjoin("Zoom : ",zom);
	z = ft_itoa(data->z);
	z = ft_strjoin("Z-Axis : ",z);
    char *x_str = ft_itoa(data->x);
    x_str = ft_strjoin("X-Axis : ",x_str);
    char *y_str = ft_itoa(data->y);
    y_str = ft_strjoin("Y-Axis : ",y_str);
    
	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 20, y += 20, 0xFF0000, "pess to 2  for convert  3D map to 2D");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, zom);
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Flatten: </>");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, x_str);
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, y_str);
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, z);
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
	
}
/***********************le menu de2D ***********************************************/
void	print_menu2D(fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;
	char *zom;
	char *z;
    zom = ft_itoa(data->zoom);
    zom = ft_strjoin("Zoom : ",zom);
	z = ft_itoa(data->z);
	z = ft_strjoin("Z-Axis : ",z);
    char *x_str = ft_itoa(data->x);
    x_str = ft_strjoin("X-Axis : ",x_str);
    char *y_str = ft_itoa(data->y);
    y_str = ft_strjoin("Y-Axis : ",y_str);
    
	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 20, y += 20, 0xFF0000, "pess to 3  for convert  2D map to 3D");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, zom);
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Flatten: </>");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, x_str);
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, y_str);
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, z);
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
}