/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:27:04 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/22 11:42:02 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void rotate_z(float *x, float *y, float angle)
{
    float x_temp;

    x_temp = *x;
    *x = (*x * cos(angle)) - (*y * sin(angle));
    *y = x_temp * sin(angle) + *y * cos(angle);
}
void rotate_y(float *x, float *z, float angle)
{
    float x_temp;

    x_temp = *x;
    *x = *x * cos(angle) + *z * sin(angle);
    *z = -x_temp * sin(angle) + *z * cos(angle);
}
void rotate_x(float *y, float *z,float angle)
{
   float y_temp;

    y_temp = *y;
    *y = (*y * cos(angle)) - (*z * sin(angle));
    *z = y_temp * sin(angle) + *z * cos(angle);
}