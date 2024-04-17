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
void  isometric(float *x, float *y, int z)
{
 int tmp;

    tmp = *x;
 *x = (tmp - *y) * cos(0.523599);
 *y = (tmp + *y) * sin(0.523599) - z;
}
void bresenham(float x1, float y1, float x2, float y2, fdf *data)
{
	int zomm ;
    float x_step;
    float y_step;
    float MAX;
	int z1;
    char **color_split;
    int color;
    int z2;
    if(data->height >= 500)
        zomm = 1;
    else if(data->height >= 200)
        zomm = 2;
    else if(data->height >= 100)
        zomm = 5;
    else if(data->height >= 50)
        zomm = 8;
    else if(data->height >= 20)
        zomm = 5;
    else
        zomm = 20;
    z1 = ft_atoi(data->matrix[(int)y1][(int)x1]);
    color_split = ft_split(data->matrix[(int)y1][(int)x1], ',');
    if(color_split[1] == NULL)
    {
        if(ft_atoi(data->matrix[(int)y1][(int)x1]) != 0)
        {
            if(ft_atoi(data->matrix[(int)y2][(int)x2]) != 0)
                color = 0x0000FF;
            else
            color =0xFF0000;
        }
           
        else
            color = 0xFFFFFF;
    }
        
    else
        color = hexToInt(color_split[1]) ;
    z2 = ft_atoi(data->matrix[(int)y2][(int)x2]);
    isometric(&x1,&y1,z1);
    isometric(&x2,&y2,z2);
    x1*=zomm;
    y1*=zomm;
    x2*=zomm;
    y2*=zomm;
    x_step = x2 - x1;
    y_step = y2 - y1;

    MAX = fmaxf(fabsf(x_step), fabsf(y_step)); // Utilisation de fmaxf pour trouver le maximum absolu

    x_step /= MAX;
    y_step /= MAX; // Correction de la division par MAX

    while ((int)(x2 - x1) != 0 || (int)(y2 - y1) != 0) {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x1+400, (int)y1+500, color); // Arrondissement à la valeur entière la plus proche
        x1 += x_step;
        y1 += y_step;
    }
}

void draw (char **argv,fdf **data)
{
    int x;
    int y;
    int x1;
    int y1;
    char *line;
    int fd;
    red_file(argv[1],data);
    y = 0;
    fd = open(argv[1],O_RDONLY);
    while(y < (*data)->height)
    {
        x = 0;
        line = get_next_line(fd);
       (*data)->width = get_width(line) -1 ;
        while(x < (*data)->width)
        { 
            x1= (x + 1);
            y1 = y;
            if(x + 1 <(*data)->width && (*data)->matrix[y][x + 1])
            {
                x1= (x + 1);
                y1 = y;
                if(ft_atoi((*data)->matrix[y][x + 1]) != 0)
                {
                    bresenham(x , y , x1 , y1 ,*data);
                }
                else
                {
                   bresenham(x , y , x1 , y1 ,*data);
                }
            }
            if(y + 1 <(*data)->height && (*data)->matrix[y + 1])
            {
                x1= x;
                y1 = y+1;
                if(ft_atoi((*data)->matrix[y + 1][x]) != 0)
                {
                    bresenham(x, y , x1, y1,*data);
                }
                else
                {
                    bresenham(x , y , x1 , y1 ,*data);
                }
                    
            }
            x++;
        }
        free(line);
        y++;
    }
    close(fd);
}