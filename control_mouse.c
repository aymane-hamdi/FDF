/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:27:59 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/19 18:37:30 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
void draw_background(void *mlx, void *win, int start_x, int start_y, int end_x, int end_y, int color)
{
    int x;
    int y;

    y = start_y;
    while (y < end_y)
    {
        x = start_x;
        while (x < end_x)
        {
            mlx_pixel_put(mlx, win, x, y, color);
            x++;
        }
        y++;
    }
}
void	print_menu3D(fdf **data)
{
	int		y;
	void	*mlx;
	void	*win;
	char *zom;
	char *z;
    zom = ft_itoa((*data)->zoom);
    zom = ft_strjoin("Zoom : ",zom);
	z = ft_itoa((*data)->z);
	z = ft_strjoin("Z-Axis : ",z);
    char *x_str = ft_itoa((*data)->x);
    x_str = ft_strjoin("X-Axis : ",x_str);
    char *y_str = ft_itoa((*data)->y);
    y_str = ft_strjoin("Y-Axis : ",y_str);
    int img_width;
    int img_height;

	y = 0;
	mlx = (*data)->mlx_ptr;
	win = (*data)->win_ptr;
	draw_background(mlx, win, 13, 18, 400,420, MENU_BACKGROUND);	
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 20, y += 20, 0xFF0000, "pess to 2  for convert  3D map to 2D");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, zom);
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Flatten: </>");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, x_str);
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, y_str);
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, z);
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");

	
}
/***********************le menu de2D ***********************************************/
void	print_menu2D(fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;
	char *zom;
	char *z;
    zom = ft_itoa(data->zoom);
    zom = ft_strjoin("Zoom : ",zom);
	z = ft_itoa(data->z);
	z = ft_strjoin("Z-Axis : ",z);
    char *x_str = ft_itoa(data->x);
    x_str = ft_strjoin("X-Axis : ",x_str);
    char *y_str = ft_itoa(data->y);
    y_str = ft_strjoin("Y-Axis : ",y_str);
    
	y = 0;
	 mlx = data->mlx_ptr;
    win = data->win_ptr;	
    draw_background(mlx, win, 13, 18, 400,420,MENU_BACKGROUND); // Ajoutez l'arrière-plan avant le texte
    mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
    mlx_string_put(mlx, win, 20, y += 20, 0xFF0000, "pess to 3  for convert  2D map to 3D");
    mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
    mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, zom);
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Flatten: </>");
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
    mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, x_str);
    mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, y_str);
    mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, z);
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
    mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
    mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
	
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