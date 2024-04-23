/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawin_3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:58:42 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/23 23:28:34 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void  isometric(double *x1, double *y1,fdf *data,double *x2, double *y2)
{
	int tmp_x1;
	int tmp_x2;
	double angle;
	
	angle = 30 * M_PI / 180;
	tmp_x1 = *x1;
	*x1 = (tmp_x1 - *y1) * cos(angle);
	*y1 = (tmp_x1 + *y1) * sin(angle) - data->z1;
	tmp_x2 = *x2;
	*x2 = (tmp_x2 - *y2) * cos(angle);
	*y2 = (tmp_x2 + *y2) * sin(angle) - data->z2;
}

void trasformation(double *x1, double *y1, double *x2, double *y2, fdf **data)
{
	rotate_x(y1,data,y2);
	rotate_y(x1, data,x2);
	rotate_z(x1, y1,(*data)->angel_z);
	rotate_z(x2,y2,(*data)->angel_z);
	isometric(x1, y1,*data,x2, y2);
}
void draw_bresenham(double x1, double y1, double x2, double y2, fdf **data)
{
	(*data)->z1 = ft_atoi((*data)->matrix[(int)y1][(int)x1]);
	(*data)->z2 = ft_atoi((*data)->matrix[(int)y2][(int)x2]); 
	(*data)->color_start_x=x1;
	(*data)->color_start_y=y1;
	(*data)->color_end_x=x2;
	(*data)->color_end_y=y2;
}
void bresenham(double x1, double y1, double x2, double y2, fdf **data)
{
    double x_step;
	double y_step;
	double MAX;
	int color;
	draw_bresenham(x1,  y1, x2,  y2, data);
	center_and_zoom(data, &x1, &y1, &x2, &y2);
	trasformation(&x1, &y1,&x2, &y2,data);
	x_step = x2 - x1;
	y_step = y2 - y1;
	MAX = fmaxf(fabs(x_step), fabs(y_step));
	x_step /= MAX;
	y_step /= MAX;
	(*data)->x2 = x2;
	(*data)->y2 =y2;
	(*data)->start_x= x1;
	(*data)->start_y= y1;
	while ((int)(x2 - x1) != 0 || (int)(y2 - y1) != 0)
	{
		(*data)->x1 = x1;
		(*data)->y1 =y1;
		mlx_pixel_put((*data)->mlx_ptr,(*data)->win_ptr, x1+(*data)->mov_cote+230, y1+(*data)->mouv_haut ,get_color_3d(data)); 
		x1 += x_step;
		y1 += y_step;
	}  
}

void draw_3D(fdf **data)
{
    int x;
    int y;
    int x1;
    int y1;
    
    y = 0;
    while(y < (*data)->height)
    {
        x = 0;
        while(x < len_str((*data)->matrix[y]))
        { 
            if( (*data)->matrix[y][x + 1])
                bresenham(x , y , x + 1, y ,data);
            if((*data)->matrix[y + 1])
                bresenham(x , y , x, y+1 ,data);
            x++;
        }
        y++;
    }
}
