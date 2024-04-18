/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:12 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/18 21:26:12 by ahamdi           ###   ########.fr       */
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

typedef struct
{
    float angel_x;
    float angel_y;
    float angel_z;
    int x;
    int y;
    int button;
    int z;
    int mov_cote;
    int mouv_haut;
    int zoom;
    int width;
    int height;
    char  ***matrix;
    void *mlx_ptr;
    void *win_ptr;
    char **argv;
    void *img;
    int form;
}fdf;

int hexToInt(const char *hex) ;
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
#endif