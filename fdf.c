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
int main (int argc,char **argv)
{
    // char ***matrix;
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 5000, "FDF project");
    mlx_loop(mlx_ptr);
}