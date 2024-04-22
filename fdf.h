/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:12 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/22 15:25:20 by ahamdi           ###   ########.fr       */
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
    float end_x;
    float start_y;
    float end_y;
    char  ***matrix;
    void *mlx_ptr;
    void *win_ptr;
    char **argv;
    int form;
    
}fdf;
typedef struct
{
    int r;
    int g;
    int b;
} Color;
int hexToInt(const char *hex) ;
unsigned int get_gradient(unsigned int start_int, unsigned int end_int, float ratio);
// void draw_3D_sans_bas(fdf **data);
void red_file(char *argv,fdf **data);
int get_height(char *argv);
int get_width(char *argv);
void draw_3D(fdf **data);
void draw_2D(fdf **data);
void	print_menu2D(fdf *data);
void	print_menu3D(fdf **data);
int	mouse_press(int button, int x, int y, fdf **data);
int autour_pres(int key, fdf **data);
int key_press(int key, fdf **data);
int close_window(fdf *data);
int get_color_3d(fdf **data);
void rotate_z(float *x, float *y, float angle);
void rotate_y(float *x, float *z, float angle);
void rotate_x(float *x, float *z, float angle);

#endif