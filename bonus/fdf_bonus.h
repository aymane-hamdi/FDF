/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:12 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/03 15:00:23 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include "../miniliblx/minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_fdf
{
	int		h;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	int		key;
	float	angel_x;
	float	angel_y;
	float	angel_z;
	int		x;
	int		y;
	int		color_change;
	int		color_start_x;
	int		color_start_y;
	int		color_end_x;
	int		color_end_y;
	double	z1;
	double	z2;
	int		color;
	int		mov_cote;
	int		mouv_haut;
	int		zoom;
	int		width;
	int		height;
	int		rotating;
	int		width_window;
	int		height_window;
	float	start_x;
	float	start_y;
	char	***matrix;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**argv;
	int		form;
	int		z_max;
	int		r;
	int		g;
	int		b;
	int		color1;
	int		color2;
	void	*img;
	void	*img_print;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_fdf;

typedef struct s_Color
{
	int	r;
	int	g;
	int	b;
}t_Color;

int				rotate_object_z(t_fdf **data);
int				reset(int key, t_fdf **data);
int				rotate_object_y(t_fdf **data);
void			draw(t_fdf **data);
int				rotate_object_x(t_fdf **data);
void			my_mlx_pixel_put(t_fdf **data, int x, int y, int color);
int				len_str(char **str);
void			draw_bresenham(t_fdf **data);
int				hexToInt(const char *hex);
void			center_and_zoom(t_fdf **data);
unsigned int	get_gradient(unsigned int start_int, 
					unsigned int end_int, double ratio);
void			red_map(char *argv, t_fdf **data);
int				get_height(char *argv);
void			while_loop(t_fdf **data, double x_step, double y_step);
int				get_width(char *argv);
void			draw_3d(t_fdf **data);
void			draw_2d(t_fdf **data);
void			print_menu(t_fdf **data);
int				change_colore(t_fdf **data);
int				autour_pres(int key, t_fdf **data);
int				key_press(int key, t_fdf **data);
int				close_window(t_fdf **data);
int				get_color_3d(t_fdf **data);
void			mouve_haute(int key, t_fdf **data);
void			rotate_z(t_fdf **data);
void			rotate_y(t_fdf **data);
void			rotate_x(t_fdf **data);
void			chek_leaks(void);
void			set_zoom(t_fdf **data);
int				mouse_press(int key, int x, int y, t_fdf **data);
void			free_3d_char_array(t_fdf **data);
int				rgb_to_number(int r, int g, int b);
void			draw_3d_inverce(t_fdf **data);
void			draw_2d_inverce(t_fdf **data);
void			my_mlx_pixel_put(t_fdf **data, int x, int y, int color);
void			free_data(t_fdf **data);
#endif