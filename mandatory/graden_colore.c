/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graden_colore.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:32:16 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/03 15:53:03 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

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
        color1 = 16711680; // Rouge 0x432371
    else
        color1 =  0x9F6976; //(*data)->color_change; // Blanc 0x9F6976
    if (end_color != 0)
        color2 =  16711680; // Rouge 16711680
    else
        color2 =  0x9F6976;//(*data)->color_change; // Blanc
    color = get_gradient(color1, color2, ratio);
    return (color);
}

Color int_to_color(unsigned int rgb)
{
    Color color;
    color.r = (rgb >> 16) & 0xFF;
    color.g = (rgb >> 8) & 0xFF;
    color.b = rgb & 0xFF;
    return color;
}

unsigned int get_gradient(unsigned int start_int, unsigned int end_int, double ratio)
{
    Color start = int_to_color(start_int);
    Color end = int_to_color(end_int);

    int r = (int)(start.r + ratio * (end.r - start.r));
    int g = (int)(start.g + ratio * (end.g - start.g));
    int b = (int)(start.b + ratio * (end.b - start.b));
    unsigned int rgb = (r << 16) | (g << 8) | b;
    return rgb;
}
void	my_mlx_pixel_put(fdf **data, int x, int y, int color)
{
	char	*dst;
	if(x < 0 || y < 0 || x >= 2000 || y >= 2000)
		return ;
	(*data)->addr = mlx_get_data_addr((*data)->img, &(*data)->bits_per_pixel, &(*data)->line_length,&(*data)->endian);
	dst = (*data)->addr + (y * (*data)->line_length + x * ((*data)->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	free_3d_char_array(fdf **data)
{
    int	i;
    int	j;

    i = 0;
    while ((*data)->matrix[i])
    {
        j = 0;
        while ((*data)->matrix[i][j])
        {
            free((*data)->matrix[i][j]);
            j++; 
        }
        free((*data)->matrix[i]);
        i++;
    }
    free((*data)->matrix);
}

void free_data(fdf **data)
{
    free_3d_char_array(data);
    free(*data);
}
void chek_leaks(void)
{
	system("leaks fdf");
}