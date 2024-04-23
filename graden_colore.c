/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graden_colore.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:32:16 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/23 18:18:25 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
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