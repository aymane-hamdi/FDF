/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:27:59 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/23 16:09:36 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void set_background_image(fdf *data, char *filename)
{
    int width, height;
    void *image;

    image = mlx_xpm_file_to_image(data->mlx_ptr, filename, &width, &height);
    if (image == NULL)
        return;
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image, 0, 0);
}
void	print_menu(fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;
	char *zom;
    char *itoi;
    itoi =ft_itoa(data->zoom);
    zom = ft_strjoin("zomm  : ",itoi);
	mlx = data->mlx_ptr;
    win = data->win_ptr;
    set_background_image(data, "fond-texture-abstrait-_1_.xpm");
    mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
    mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
    mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, zom);
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Flatten: </>");
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "x/d: Rotate X axis");
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Y/U: Rotate Y axis");
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Q/W: Rotate Z axis");
    mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
    mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: 3 Key");
    mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: 2 Key");
    free(itoi);
    free(zom);
}
void clear_area(fdf *data, int x_start, int y_start, int width, int height, int color)
{
    int x, y;

    y = y_start;
    while (y < y_start + height)
    {
        x = x_start;
        while (x < x_start + width)
        {
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
            x++;
        }
        y++;
    }
}
// int	mouse_press(int button, int x, int y, fdf **data)
// {
//     printf("button = %d\n",button);
// 	if ( button == 4)
//     {
//         printf("zoom in\n");
//         mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
       
//         (*data)->zoom +=1;
//          (*data)->zoom *=2;
//         if((*data)->form == 2)
//         {
//             draw_2D(data); 
//             print_menu2D(*data);
//         }
//         else
//         {
//             draw_3D(data); 
//             print_menu3D(data);
//         }
//     }
//     else if (button == 5 )
//     {
       
//         printf("zoom out\n");
       
//         mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
//         (*data)->zoom /= 2;
//         if((*data)->zoom < 2)
//             (*data)->zoom = 1;
//         if((*data)->form == 2)
//         {
//             draw_2D(data); 
//             print_menu2D(*data);
//         }
//         else
//         {
//             draw_3D(data); 
//             print_menu3D(data);
//         }
//         // Zoom arrière lorsque la touche '-' est pressée
//     }
//      else if(button == 2)
//     {
//          printf("mouv RIGHT\n");
//         mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
//         (*data)->mov_cote += 200;
//         if((*data)->form == 2)
//         {
//             draw_2D(data); 
//             print_menu2D(*data);
//         }
//         else
//         {
//             draw_3D(data); 
//             print_menu3D(data);
//         }
//         // Zoom arrière lorsque la touche '-' est pressée
//     }
//     else if(button == 1)
//     {
//         printf("mouv LEFT\n");
//         mlx_clear_window((*data)->mlx_ptr, (*data)->win_ptr);
//         (*data)->mov_cote -= 200;
//         if((*data)->form == 2)
//         {
//             draw_2D(data); 
//             print_menu2D(*data);
//         }
//         else
//         {
//             draw_3D(data); 
//             print_menu3D(data);
//         };
//         // Zoom arrière lorsque la touche '-' est pressée
//     }
    
//     return(0);
// }
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
        max = (*data)->x2;
    }
    else
    {
        value = (*data)->y1;
        min = (*data)->start_y;
        max = (*data)->y2;
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
    return (color);
}
