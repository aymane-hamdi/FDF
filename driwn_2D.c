/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driwn_2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:37:31 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/24 19:08:28 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void center_and_zoom(fdf **data, double *x1, double *y1, double *x2, double *y2)
{
	double new_with = (*data)->width / 2;
	double new_height =(*data)->height / 2;
	
	*x1 =(*x1 -  new_with) * (*data)->zoom;
	*y1=(*y1 - new_height) * (*data)->zoom;
	*x2=(*x2 -  new_with) * (*data)->zoom;
	*y2=(*y2 - new_height) * (*data)->zoom;
	if((*data)->z_max <= 50)
	{
		(*data)->z1*= (*data)->zoom;
		(*data)->z2*= (*data)->zoom;
	}
}

void bresenham_2D(double x1, double y1, double x2, double y2, fdf **data)
{
    double x_step;
	double y_step;
	double MAX;
	int color;
	draw_bresenham(x1,  y1, x2,  y2, data);
	center_and_zoom(data,&x1, &y1, &x2, &y2);
	x_step = x2 - x1;
	y_step = y2 - y1;
	double abs_x_step = fabs(x_step);
    double abs_y_step = fabs(y_step);
	MAX = fmaxf(abs_x_step, abs_y_step);
	x_step /= MAX;
	y_step /= MAX;
	(*data)->x2 = x2;
	(*data)->y2 =y2;
	(*data)->start_x= x1;
	(*data)->start_y= y1;
   	while ((int)(x2 - x1) != 0 || (int)(y2 - y1) != 0)
    {
		if(ft_strchr((*data)->matrix[(*data)->color_start_y][(*data)->color_start_x],',') != NULL)
		{
			color = hexToInt(ft_strchr((*data)->matrix[(*data)->color_start_y][(*data)->color_start_x],',')+1);
			my_mlx_pixel_put(data, x1+(*data)->mov_cote, y1+(*data)->mouv_haut, color);
		}
		else
		{
			(*data)->x1 = x1;
        	(*data)->y1 = y1;
        	color = get_color_3d(data);
			my_mlx_pixel_put(data, x1+(*data)->mov_cote, y1+(*data)->mouv_haut, color);
		}
        x1 += x_step;
        y1 += y_step;
    }  
}

void draw_2D(fdf **data)
{
    int x;
    int y;
    int x1;
    int y1;
    
    y = 0;
	(*data)->img = mlx_new_image((*data)->mlx_ptr,2000, 2000);
   while (y < (*data)->height )
    {
       x = 0;
        while (x < (*data)->width)
        {
              if( (*data)->matrix[y][x + 1])
				bresenham_2D(x,(y), (x+1),y,data);
			
            if((*data)->matrix[y + 1])
				bresenham_2D(x,(y), x, (y+1), data);
            x++;
        }
        y++;
    }
	mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr, (*data)->img, 0, 0);
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

