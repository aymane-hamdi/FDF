/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:12 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/17 19:35:47 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
#define FDF_H
#include"libft/libft.h"
#include"get_next_line/get_next_line.h"
#include<stdio.h>
#include<fcntl.h>
#include "minilibx_macos/mlx.h"
#include<math.h>
typedef struct
{
    int width;
    int height;
    char  ***matrix;
    void *mlx_ptr;
    void *win_ptr;
}fdf;

int hexToInt(const char *hex) ;
void red_file(char *argv,fdf **data);
int get_height(char *argv);
int get_width(char *argv);
void draw_line(float x1, float y1,int x2,int y2,fdf *data,int color);
void draw (char **argv,fdf **data);
void printf_matrix(char **argv,char ***matrix);
#endif