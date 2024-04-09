#include"fdf.h"

int main (int argc,char **argv)
{
    int **matrix;
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
            printf("%d",matrix[i][y]);
            y++;
            if(ft_len(matrix[i][y])== 2)
                printf(" ");
            else
                printf("  ");
        }
        printf("\n");
        i++;
    }
}