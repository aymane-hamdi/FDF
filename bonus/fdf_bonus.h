/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:12 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/28 20:46:42 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_BONUS_H
#define FDF_BONUS_H
#include"../libft/libft.h"
#include"../get_next_line/get_next_line.h"
#include<stdio.h>
#include<fcntl.h>
#include "../miniliblx/minilibx_macos/mlx.h"
#include<math.h>
#include<stdio.h>

typedef struct
{
    int h;
    int x1;
    int x2;
    int y1;
    int key;
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
    double z1;
    double z2;
    int color;
    int mov_cote;
    int mouv_haut;
    int zoom;
    int width;
    int height;
    int    rotating;
    int width_window;
    int height_window;
    float start_x;
    float start_y;
    char  ***matrix;
    void *mlx_ptr;
    void *win_ptr;
    char **argv;
    int form;
    int z_max;
    int r;
    int g;
    int b;
    int color1;
    int color2;
    void	*img;
    void    *img_print;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}fdf;

typedef struct
{
    int r;
    int g;
    int b;
} Color;
int rotate_object_z(fdf **data);
int rotate_object_y(fdf **data);
int rotate_object_x(fdf **data);
void	my_mlx_pixel_put(fdf **data, int x, int y, int color);
int len_str(char **str);
void draw_bresenham(double x1, double y1, double x2, double y2, fdf **data);
int hexToInt(const char *hex) ;
void center_and_zoom(fdf **data, double *x1, double *y1, double *x2, double *y2);
unsigned int get_gradient(unsigned int start_int, unsigned int end_int, double ratio);
void red_map(char *argv,fdf **data);
int get_height(char *argv);
int get_width(char *argv);
void draw_3D(fdf **data);
void draw_2D(fdf **data);
void	print_menu(fdf **data);
int change_colore(fdf **data);
int autour_pres(int key, fdf **data);
int key_press(int key, fdf **data);
int close_window(fdf **data);
int get_color_3d(fdf **data);
void rotate_z(double *x, double *y, double angle);
void rotate_y(double *x1, fdf **data, double *x2);
void rotate_x(double *y1,fdf **data,double *y2);
void set_zoom(fdf **data);
int  mouse_press(int key,int x,int y,fdf **data);
int rgb_to_number(int r, int g, int b);
void draw_3D_inverce(fdf **data);
#endif