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

int close_window(void *param)
{
    ft_putstr_fd("windows close\n",1);
    exit(0); // Quitte le programme proprement
}

int main(int argc, char **argv)
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int width = 200, height = 200;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
    {
        printf("Failed to initialize mlx.\n");
        return 1;
    }
    win_ptr = mlx_new_window(mlx_ptr, width, height, "FDF project");
    if (win_ptr == NULL)
    {
        printf("Failed to create a new window.\n");
        return 1;
    }

    img_ptr = mlx_xpm_file_to_image(mlx_ptr, argv[1], &width, &height);
    if (img_ptr == NULL)
    {
        printf("Failed to load the image.\n");
        return 1;
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 40, 40);
    mlx_hook(win_ptr, 17, 0, close_window, NULL); 
    mlx_loop(mlx_ptr);
    return(0);
}