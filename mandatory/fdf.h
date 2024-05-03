/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:12 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/03 15:53:30 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
#define FDF_H
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
	float x1;
	float x2;
	float y1;
	float y2;
	int key;
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
	void	*img;
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

int				key_press(int key, fdf **data);
void			my_mlx_pixel_put(fdf **data, int x, int y, int color);
int				len_str(char **str);
void			draw_bresenham(fdf **data);
int				hexToInt(const char *hex);
void			center_and_zoom(fdf **data);
unsigned int	get_gradient(unsigned int start_int, unsigned int end_int, double ratio);
void	free_3d_char_array(fdf **data);
void			red_map(char *argv, fdf **data);
int				get_height(char *argv);
int				get_width(char *argv);
void			draw_3d(fdf **data);
void chek_leaks(void);
int				close_window(fdf **data);
int				get_color_3d(fdf **data);
#endif