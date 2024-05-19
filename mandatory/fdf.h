/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:58:12 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/18 13:18:38 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include "mlx.h"
# include <math.h>

typedef struct s_fdf
{
	int			h;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	int			key;
	float		angel_x;
	float		angel_y;
	float		angel_z;
	int			x;
	int			y;
	int			color_change;
	int			color_start_x;
	int			color_start_y;
	int			color_end_x;
	int			color_end_y;
	float		z1;
	float		z2;
	int			color;
	int			mov_cote;
	int			mouv_haut;
	int			zoom;
	int			width;
	int			height;
	int			width_window;
	int			height_window;
	float		start_x;
	float		start_y;
	char		***matrix;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**argv;
	int			form;
	int			min_with;
	int			z_max;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			fd;
}t_fdf;

typedef struct s_Color
{
	int	r;
	int	g;
	int	b;
}t_Color;

void			set_zoom(t_fdf **data);
void			free_2d_erray(char **str);
void			invalid_argument(int argc);
void			exit_err_fd(t_fdf **data);
void			rotate_x(t_fdf **data, double angle);
void			rotate_y(t_fdf **data, double angle);
void			rotate_z(t_fdf **data, double angle);
int				ft_count_words(char *str);
void			cheke_map(char *argv, t_fdf **data);
void			process_word(t_fdf **data, char ***line_int, int *i, int *y);
void			process_line(t_fdf **data, char **line, 
					char ***line_int, int *i);
int				key_press(int key, t_fdf **data);
void			my_mlx_pixel_put(t_fdf **data, int x, int y, int color);
void			error_intalis(t_fdf **data);
int				hexto_int(const char *hex);
void			center_and_zoom(t_fdf **data);
void			free_line(int pos, t_fdf **data);
unsigned int	get_gradient(unsigned int start_int, 
					unsigned int end_int, double ratio);
void			center_and_zoom(t_fdf **data);
void			free_3d_char_array(t_fdf **data);
void			red_map(char *argv, t_fdf **data);
int				len_str(char **str);
int				get_width(char *argv);
void			draw_3d(t_fdf **data);
void			error(t_fdf **data);
int				close_window(t_fdf **data);
int				get_color_3d(t_fdf **data);
void			chek_line(char *line, t_fdf **data, int *j);
#endif