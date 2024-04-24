/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:27:04 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/24 19:06:56 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void rotate_z(double *x, double *y, double angle)
{
    double x_temp;
    
    x_temp = *x;
    *x = (*x * cos(angle)) - (*y * sin(angle));
    *y = x_temp * sin(angle) + *y * cos(angle);
}
void rotate_y(double *x1, fdf **data, double *x2)
{
    double x1_temp;
    double x2_temp;
    
    x1_temp = *x1;
    *x1 = *x1 * cos((*data)->angel_y) + (*data)->z1 * sin((*data)->angel_y);
   (*data)->z1 = (-x1_temp)* sin((*data)->angel_y) + (*data)->z1 * cos((*data)->angel_y);
   
    x2_temp = *x2;
    *x2 = *x2 * cos((*data)->angel_y) + (*data)->z2 * sin((*data)->angel_y);
    (*data)->z2 = (-x2_temp) * sin((*data)->angel_y) + (*data)->z2 * cos((*data)->angel_y);
}
void rotate_x(double *y1,fdf **data,double *y2)
{
   double y1_temp;
    double y2_temp;
    
    y1_temp = *y1;
    *y1 = (*y1 * cos((*data)->angel_x)) - ((*data)->z1 * sin((*data)->angel_x));
    (*data)->z1 = y1_temp * sin((*data)->angel_x) + (*data)->z1 * cos((*data)->angel_x);
    
    y2_temp = * y2;
    * y2 = (* y2 * cos((*data)->angel_x)) - ((*data)->z2 * sin((*data)->angel_x));
    (*data)->z2 =  y2_temp * sin((*data)->angel_x) + (*data)->z2 * cos((*data)->angel_x);
}

int len_str(char **str)
{
    int i;

    i = 0;
    while (str[i]!= NULL)
        i++;
    return i;
}