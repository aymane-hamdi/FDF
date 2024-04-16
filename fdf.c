#include"fdf.h"

// void printf_matrix(char **argv,char ***matrix)
// {
//     int i = 0;
//     int y;
//     int len;
//     int LEN;

//     matrix = red_file(argv[1]);
//     LEN = get_height(argv[1]);
//     len = get_width(argv[1]);
//     i = 0;
//     while(i < LEN)
//     {
//         y = 0;
//         while(y < len)
//         {
//             if(matrix[i][y] != NULL)
//                 printf("%s",matrix[i][y]);
//             y++;
//             if(ft_strlen(matrix[i][y]) > 1)
//                 printf(" ");
//             else
//                 printf("  ");
//         }
//         printf("\n");
//         i++;
//     }
// }

int close_window(char *param)
{
    ft_putstr_fd(param,1);
    exit(0); // Quitte le programme proprement
}

int main(int argc, char **argv)
{
    fdf *data;
    int width = 1000, height = 1000;
    data = (fdf*)malloc(sizeof(fdf));
    data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
    {
        printf("Failed to initialize mlx.\n");
        exit (1);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "FDF project");
    if (data->win_ptr == NULL)
    {
        printf("Failed to create a new window.\n");
        return 1;
    } 
    draw (argv,data);
    mlx_hook(data->win_ptr, 17, 0, close_window, "Close window\n"); 
    mlx_loop(data->mlx_ptr);
    return(0);
}