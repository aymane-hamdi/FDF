#include"fdf.h"

void draw_line(float x1, float y1,int x2,int y2,fdf *data,int color)
{
    float i = x1;
    float y = y1;
   while(1)
   {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr,i, y, color);
        if(i == x2 && y == y2)
            return ;
        if(i != x2)
            i++;
        if(y != y2)
            y++;
   }
}
void ispmetric(float *x , float *y,int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}
void bresenham(float x1,  float y1, float x2, float y2, fdf *data,int color)
{
    int z1;
    int z2;
    int zomm = 30;
    z1 = ft_atoi(data->matrix[(int)y1][(int)x1]);
    printf("%d\n",z1);
    z2 = ft_atoi(data->matrix[(int)y2][(int)x2]);
    printf("%d\n",z2);
    x1*=zomm ;
    y1*=zomm ;
    x2*=zomm ;
    y2*=zomm ;
    ispmetric(&x1 , &y1,z1);
    ispmetric(&x2 , &y2,z2);
    
    int  dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;
    int p = 2 * (dy - dx);

    if(dy == 0 || dx == dy || dx == 0)
    {
       draw_line(x1, y1,x2, y2,data,color);
        return ;
    }
    while(x <= x2)
    { 
        if(p >= 0)
        {
            mlx_pixel_put(data->mlx_ptr, data->win_ptr,x, y, color);
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            mlx_pixel_put(data->mlx_ptr, data->win_ptr,x, y, color);
            p = p + 2 * dy;
        }
        x++;
    }
}

void draw (char **argv,fdf *data)
{
    int x;
    int y;
    int x1;
    int y1;
    char *line;
    int fd;
    int zomm = 1;
    red_file(argv[1],&data);
    y = 0;
    fd = open(argv[1],O_RDONLY);
    while(y < data->height)
    {
        x = 0;
        line = get_next_line(fd);
        data->width = get_width(line);
        while(x < data->width)
        { 
            x1= (x + 1);
            y1 = y;
            if(x + 1 < data->width && data->matrix[y][x + 1])
            {
                x1= (x + 1);
                y1 = y;
                if(ft_atoi(data->matrix[y][x + 1]) != 0)
                {
                    bresenham(x , y , x1 , y1 ,data, 0xFF);
                }
                else
                {
                   bresenham( x , y , x1 , y1 ,data, 0xffffff);
                }
            }
            if(y + 1 <data->height && data->matrix[y + 1])
            {
                x1= x;
                y1 = y+1;
                if(ft_atoi(data->matrix[y + 1][x]) != 0)
                {
                    bresenham(x, y , x1, y1,data, 0xFF);
                }
                else
                {
                    bresenham(x , y , x1 , y1 ,data, 0xffffff);
                }
                    
            }
            x++;
        }
        free(line);
        y++;
    }
    close(fd);
}