/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:12 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/13 12:22:22 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include "mlx.h"
# include <math.h>

typedef struct s_fdf
{
	int		fd;
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
	void	*img;
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

void			free_data(t_fdf **data);
void			error(t_fdf **data);
void			cheke_map(char *argv, t_fdf **data);
void			process_word(t_fdf **data, char ***line_int, int *i, int *y);
void			process_line(t_fdf **data, char **line, 
					char ***line_int, int *i);
int				ft_count_words(char const *str, char sep);
int				rotate_object_z(t_fdf **data);
int				reset(int key, t_fdf **data);
int				rotate_object_y(t_fdf **data);
void			draw(t_fdf **data, int key);
int				rotate_object_x(t_fdf **data);
void			my_mlx_pixel_put(t_fdf **data, int x, int y, int color);
void			draw_dda(t_fdf **data);
int				hexto_int(const char *hex);
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
int				autour_pres(int key, t_fdf **data);
int				key_press(int key, t_fdf **data);
int				close_window(t_fdf **data);
int				get_color_3d(t_fdf **data);
void			mouve_haute(int key, t_fdf **data);
void			rotate_x(t_fdf **data, double angle);
void			rotate_y(t_fdf **data, double angle);
void			rotate_z(t_fdf **data, double angle);
void			set_zoom(t_fdf **data);
int				mouse_press(int key, int x, int y, t_fdf **data);
void			free_3d_char_array(t_fdf **data);
int				rgb_to_number(int r, int g, int b);
void			draw_3d_inverce(t_fdf **data);
void			draw_2d_inverce(t_fdf **data);
void			my_mlx_pixel_put(t_fdf **data, int x, int y, int color);
void			free_data(t_fdf **data);
#endif