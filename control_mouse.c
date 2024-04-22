/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:27:59 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/22 23:04:17 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	print_menu3D(fdf **data)
{
	int		y;
	void	*mlx;
	void	*win;
	char *zom;
	char *z;
    zom = ft_itoa((*data)->zoom);
    zom = ft_strjoin("Zoom : ",zom);
    char *x_str = ft_itoa((*data)->x);
    x_str = ft_strjoin("X-Axis : ",x_str);
    char *y_str = ft_itoa((*data)->y);
    y_str = ft_strjoin("Y-Axis : ",y_str);
    int img_width;
    int img_height;

	y = 0;
	mlx = (*data)->mlx_ptr;
	win = (*data)->win_ptr;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, zom);
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Flatten: </>");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, x_str);
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, y_str);
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: 3 Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: 2 Key");

	
}
/***********************le menu de2D ***********************************************/
void	print_menu2D(fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;
	char *zom;
    zom = ft_itoa(data->zoom);
    zom = ft_strjoin("Zoom : ",zom);
    char *x_str = ft_itoa(data->x);
    x_str = ft_strjoin("X-Axis : ",x_str);
    char *y_str = ft_itoa(data->y);
    y_str = ft_strjoin("Y-Axis : ",y_str);
    
	y = 0;
	 mlx = data->mlx_ptr;
    win = data->win_ptr;	
    mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
    mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
    mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, zom);
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Flatten: </>");
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
    mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, x_str);
    mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, y_str);
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
    mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: 3 Key");
    mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: 2 Key");
	
}
int	mouse_press(int button, int x, int y, fdf **data)
{
    printf("button = %d\n",button);
	if ( button == 4)
    {
        printf("zoom in\n");
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
       
        (*data)->zoom +=1;
         (*data)->zoom *=2;
        if((*data)->form == 2)
        {
            draw_2D(data); 
            print_menu2D(*data);
        }
        else
        {
            draw_3D(data); 
            print_menu3D(data);
        }
    }
    else if (button == 5 )
    {
       
        printf("zoom out\n");
       
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->zoom /= 2;
        if((*data)->zoom < 2)
            (*data)->zoom = 1;
        if((*data)->form == 2)
        {
            draw_2D(data); 
            print_menu2D(*data);
        }
        else
        {
            draw_3D(data); 
            print_menu3D(data);
        }
        // Zoom arrière lorsque la touche '-' est pressée
    }
     else if(button == 2)
    {
         printf("mouv RIGHT\n");
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->mov_cote += 200;
        if((*data)->form == 2)
        {
            draw_2D(data); 
            print_menu2D(*data);
        }
        else
        {
            draw_3D(data); 
            print_menu3D(data);
        }
        // Zoom arrière lorsque la touche '-' est pressée
    }
    else if(button == 1)
    {
        printf("mouv LEFT\n");
        mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
        (*data)->mov_cote -= 200;
        if((*data)->form == 2)
        {
            draw_2D(data); 
            print_menu2D(*data);
        }
        else
        {
            draw_3D(data); 
            print_menu3D(data);
        };
        // Zoom arrière lorsque la touche '-' est pressée
    }
    
    return(0);
}
int get_color_3d(fdf **data)
{
    int color;
    int color1;
    int color2; // Initialisation par défaut de color2
    int value;
    int min;
    int max;
    int start_color;
    int end_color;
    float ratio;

    float dx = (*data)->x2 - (*data)->start_x;
    float dy = (*data)->y2 - (*data)->start_y;
    if (dx > dy)
    {
        value = (*data)->x1;
        min = (*data)->start_x;
        max = (*data)->end_x;
    }
    else
    {
        value = (*data)->y1;
        min = (*data)->start_y;
        max = (*data)->end_y;
    }
    ratio = (value - min) / (float)(max - min);
    start_color = ft_atoi((*data)->matrix[(*data)->color_start_y][(*data)->color_start_x]);
    end_color = ft_atoi((*data)->matrix[(*data)->color_end_y][(*data)->color_end_x]);
    if (start_color != 0)
        color1 = 65289; // Rouge
    else
        color1 = (*data)->color_change; // Blanc 16777215
    if (end_color != 0)
        color2 = 65289; // Rouge
    else
        color2 = (*data)->color_change; // Blanc
    color = get_gradient(color1, color2, ratio);
    if(ft_strchr((*data)->matrix[(*data)->color_start_y][(*data)->color_start_x],',') != NULL)
        color = hexToInt(ft_strchr((*data)->matrix[(*data)->color_start_y][(*data)->color_start_x],',')+1);
    return (color);
}
