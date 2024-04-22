/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graden_colore.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:32:16 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/21 11:31:39 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct {
    int r;
    int g;
    int b;
} Color;

Color int_to_color(unsigned int rgb)
{
    Color color;
    color.r = (rgb >> 16) & 0xFF;
    color.g = (rgb >> 8) & 0xFF;
    color.b = rgb & 0xFF;
    return color;
}

unsigned int get_gradient(unsigned int start_int, unsigned int end_int, float ratio)
{
    Color start = int_to_color(start_int);
    Color end = int_to_color(end_int);

    int r = (int)(start.r + ratio * (end.r - start.r));
    int g = (int)(start.g + ratio * (end.g - start.g));
    int b = (int)(start.b + ratio * (end.b - start.b));
    unsigned int rgb = (r << 16) | (g << 8) | b;
    return rgb;
}
// int main() {
//     Color red = {255, 0, 0};
//     Color green = {0, 255, 0};
//     Color blue = {0, 0, 255};

//     float ratio = 0.1; // Halfway

//    unsigned int gradient1 = get_gradient(16777215,  16711680, ratio);
//     unsigned int gradient2 = get_gradient(gradient1,  16711680, ratio);

//     printf("Gradient color 1: %d\n", (gradient1));
//     printf("Gradient color 2: %d\n", (gradient2));

//     return 0;
// }
