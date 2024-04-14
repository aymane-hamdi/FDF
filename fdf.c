#include"fdf.h"

void printf_matrix(char **argv,char ***matrix)
{
    int i = 0;
    int y;
    int len;
    int LEN;

    matrix = red_file(argv[1]);
    LEN = get_height(argv[1]);
    len = get_width(argv[1]);
    i = 0;
    while(i < LEN)
    {
        y = 0;
        while(y < len)
        {
            if(matrix[i][y] != NULL)
                printf("%s",matrix[i][y]);
            y++;
            if(ft_strlen(matrix[i][y]) > 1)
                printf(" ");
            else
                printf("  ");
        }
        printf("\n");
        i++;
    }
}

int close_window(char *param)
{
    ft_putstr_fd(param,1);
    exit(0); // Quitte le programme proprement
}

int main(int argc, char **argv)
{
     int color =0xFF;
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int width = 800, height = 600;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
    {
        printf("Failed to initialize mlx.\n");
        exit (1);
    }
    win_ptr = mlx_new_window(mlx_ptr, width, height, "FDF project");
    if (win_ptr == NULL)
    {
        printf("Failed to create a new window.\n");
        return 1;
    }
    draw_line(mlx_ptr, win_ptr,150,100,150,500, color);
    draw_line(mlx_ptr, win_ptr,150,100,240,100, color);
    draw_line(mlx_ptr, win_ptr,240,100,240,260, color);
    draw_line(mlx_ptr, win_ptr,240,350,240,500, color);
    draw_line(mlx_ptr, win_ptr,150,500,240,500, color);
//************************************************************//
    draw_line(mlx_ptr, win_ptr,500,100,500,260, color);
     draw_line(mlx_ptr, win_ptr,500,350,500,500, color);
    draw_line(mlx_ptr, win_ptr,500,100,590,100, color);
    draw_line(mlx_ptr, win_ptr,590,100,590,500, color);
    draw_line(mlx_ptr, win_ptr,500,500,590,500, color);
//************************************************************//
    draw_line(mlx_ptr, win_ptr,240,350,500,350, color);
    draw_line(mlx_ptr, win_ptr,240,260,500,260, color);

    mlx_hook(win_ptr, 17, 0, close_window, "Close window\n"); 
    mlx_loop(mlx_ptr);
    return(0);
}