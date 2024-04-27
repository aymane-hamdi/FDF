/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:27:59 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/27 22:39:40 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf_bonus.h"

void	print_menu(fdf *data)
{
	
    int img_width, img_height;
    void *img_ptr;

    img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "bonus/X-Axis-rotation-_1_.xpm", &img_width, &img_height);
    if (img_ptr == NULL)
    {
        ft_putstr_fd("Failed to load background image.\n", 2);
        return;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, 0, 0);
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
int  mouse_press(int key,int x,int y,fdf **data)
{
	if(key == 4)
    {
        (*data)->zoom -= 1;
         if( (*data)->zoom < 2)
             (*data)->zoom = 1;
    }
    else if(key == 5)
        (*data)->zoom += 1;
    mlx_clear_window( (*data)->mlx_ptr,  (*data)->win_ptr);
    if((*data)->form == 2)
        draw_2D(data); 
    else
        draw_3D(data); 
    print_menu(*data);
	return(0);
}