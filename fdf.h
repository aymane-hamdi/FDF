#ifndef FDF_H
#define FDF_H
#include"libft/libft.h"
#include"get_next_line/get_next_line.h"
#include<stdio.h>
#include<fcntl.h>
#include"minilibx-linux/mlx.h"
#include "minilibx_mms_20191025_beta/mlx.h"

char ***red_file(char *argv);
int get_height(char *argv);
int get_width(char *argv);
void draw_line(void *mlx_ptr, void *win_ptr, int x1, int y1,int x2,int y2, int color);
void draw_line_for_algorithme(void *mlx_ptr, void *win_ptr, int x1, int y1,int x2,int y2, int color);
void draw_circle(void *mlx_ptr, void *win_ptr, int xc, int yc, int radius, int color);
#endif