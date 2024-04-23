/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:27:59 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/23 22:58:43 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	print_menu(fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;
	char *zom;
    char *itoi;
    
    itoi = ft_itoa(data->zoom);
    zom = ft_strjoin("zomm  : ",itoi);
	mlx = data->mlx_ptr;
    win = data->win_ptr;
    mlx_string_put(mlx, win, 65, y += 20,  16777215, "How to Use");
    mlx_string_put(mlx, win, 15, y += 35,  16777215, "Zoom: Scroll or +/-");
    mlx_string_put(mlx, win, 15, y += 35,  16777215, zom);
    mlx_string_put(mlx, win, 15, y += 30,  16777215, "Move: Arrows");
    mlx_string_put(mlx, win, 15, y += 30,  16777215, "Flatten: </>");
    mlx_string_put(mlx, win, 15, y += 30,  16777215, "Rotate: Press & Move");
    mlx_string_put(mlx, win, 15, y += 30,  16777215, "x/d: Rotate X axis");
    mlx_string_put(mlx, win, 15, y += 30,  16777215, "Y/U: Rotate Y axis");
    mlx_string_put(mlx, win, 15, y += 30,  16777215, "Rotate Z axis :");
     mlx_string_put(mlx, win, 30, y += 30,  16777215, "SHIFT/z");
    mlx_string_put(mlx, win, 15, y += 30,  16777215, "Projection");
    mlx_string_put(mlx, win, 57, y += 25,  16777215, "ISO: 3 Key");
    mlx_string_put(mlx, win, 57, y += 25,  16777215, "Parallel: 2 Key");
    free(itoi);
    free(zom);
}
void intianl(fdf *data,int *min ,int *max,int *value)
{
    if ((data->x2 - data->start_x) > (data->y2 - data->start_y))
    {
        *value = data->x1;
        *min = data->start_x;
        *max = data->x2;
    }
    else
    {
        *value = data->y1;
        *min = data->start_y;
        *max = data->y2;
    }
}
int get_color_3d(fdf **data)
{
    int color;
    int color1;
    int color2; 
    int value;
    int min;
    int max;
    int start_color;
    int end_color;
    float ratio;
    intianl(*data,&min ,&max,&value);
    ratio = (value - min) / (float)(max - min);
    start_color = ft_atoi((*data)->matrix[(*data)->color_start_y][(*data)->color_start_x]);
    end_color = ft_atoi((*data)->matrix[(*data)->color_end_y][(*data)->color_end_x]);
    if (start_color != 0)
        color1 =16711680; // Rouge 16711680
    else
        color1 = 65289; //(*data)->color_change; // Blanc 16777215
    if (end_color != 0)
        color2 = 16711680; // Rouge 16711680
    else
        color2 = 65289;//(*data)->color_change; // Blanc
    color = get_gradient(color1, color2, ratio);
    if(ft_strchr((*data)->matrix[(*data)->color_start_y][(*data)->color_start_x],',') != NULL)
        color = hexToInt(ft_strchr((*data)->matrix[(*data)->color_start_y][(*data)->color_start_x],',')+1);
    return (color);
}
