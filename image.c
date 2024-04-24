/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:20:37 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/24 12:39:09 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
void draw_pixel_to_image(void *img, int x, int y, int color)
{
    char    *data;
    int     bpp;
    int     size_line;
    int     endian;

    data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
    *(int *)(data + ((x + y * size_line / 4) * bpp / 8)) = color;
}

void draw_image(fdf **data)
{
    void    *img;
    int     x;
    int     y;

    img = mlx_new_image((*data)->mlx_ptr, (*data)->width, (*data)->height);
    x = 0;
    while (x < (*data)->width)
    {
        y = 0;
        while (y < (*data)->height)
        {
            if((*data)->matrix[y][x] != 0)
                draw_pixel_to_image(img, x*20, y*20, 16711680);
            else
                draw_pixel_to_image(img, x*20, y*20,16777215 );
            y++;
        }
        x++;
    }
    mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr, img, 500, 500);
    mlx_destroy_image((*data)->mlx_ptr, img);
}