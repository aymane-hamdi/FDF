/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:12 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/23 15:16:01 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
#define FDF_H
#include"libft/libft.h"
#include"get_next_line/get_next_line.h"
#include<stdio.h>
#include<fcntl.h>
#include "miniliblx/minilibx_macos/mlx.h"
#include<math.h>
#include "key_macro.h"
#include "color.h"
#include<stdio.h>

typedef struct
{
    int x1;
    int x2;
    int y1;
    int y2;
    float angel_x;
    float angel_y;
    float angel_z;
    int x;
    int y;
    int color_change;
    int color_start_x;
    int color_start_y;
    int color_end_x;
    int color_end_y;
    float z1;
    float z2;
    int color;
    int button;
    int haut;
    int mov_cote;
    int mouv_haut;
    int zoom;
    int width;
    int height;
    int width_window;
    int height_window;
    float start_x;
    float start_y;
    char  ***matrix;
    void *mlx_ptr;
    void *win_ptr;
    char **argv;
    int form;
     int min_x ;
    int max_x;
    int min_y ;
    int max_y ;
    int min_z ;
    int max_z ;
}fdf;
typedef struct
{
    int r;
    int g;
    int b;
} Color;
void clear_area(fdf *data, int x_start, int y_start, int width, int height, int color);
int hexToInt(const char *hex) ;
void draw_background(int x,int y, int color,fdf *data);
void center_and_zoom(fdf **data, float *x1, float *y1, float *x2, float *y2, float *z1, float *z2);
unsigned int get_gradient(unsigned int start_int, unsigned int end_int, float ratio);
void red_file(char *argv,fdf **data);
int get_height(char *argv);
int get_width(char *argv);
void draw_3D(fdf **data);
void draw_2D(fdf **data);
void	print_menu(fdf *data);
int	mouse_press(int button, int x, int y, fdf **data);
int autour_pres(int key, fdf **data);
int key_press(int key, fdf **data);
int close_window(fdf *data);
int get_color_3d(fdf **data);
void rotate_z(float *x, float *y, float angle);
void rotate_y(float *x, float *z, float angle);
void rotate_x(float *x, float *z, float angle);

#endif