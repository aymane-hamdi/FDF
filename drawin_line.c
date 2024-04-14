#include"fdf.h"

void draw_line(void *mlx_ptr, void *win_ptr, int x1, int y1,int x2,int y2, int color)
{
    int i = x1;
    int y = y1;
   while(1)
   {
        mlx_pixel_put(mlx_ptr, win_ptr,i, y, color);
        if(i == x2 && y == y2)
            return ;
        if(i != x2)
            i++;
        if(y != y2)
            y++;
   }
}
void draw_line_for_algorithme(void *mlx_ptr, void *win_ptr, int x1, int y1,int x2,int y2, int color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;
    int p = 2 * (dy - dx);
    while(x <= x2)
    {
        if(p >= 0)
        {
            mlx_pixel_put(mlx_ptr, win_ptr,x, y, color);
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            mlx_pixel_put(mlx_ptr, win_ptr,x, y, color);
            p = p + 2 * dy;
        }
        x++;
    }
}
void draw_circle(void *mlx_ptr, void *win_ptr, int xc, int yc, int radius, int color) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (x <= y) {
         mlx_pixel_put(mlx_ptr, win_ptr, xc + x, yc + y, color);
         mlx_pixel_put(mlx_ptr, win_ptr, xc - x, yc + y, color);
         mlx_pixel_put(mlx_ptr, win_ptr, xc + x, yc - y, color);
         mlx_pixel_put(mlx_ptr, win_ptr, xc - x, yc - y, color);
         mlx_pixel_put(mlx_ptr, win_ptr, xc + y, yc + x, color);
         mlx_pixel_put(mlx_ptr, win_ptr, xc - y, yc + x, color);
         mlx_pixel_put(mlx_ptr, win_ptr, xc + y, yc - x, color);
         mlx_pixel_put(mlx_ptr, win_ptr, xc - y, yc - x, color);

        if (d < 0)
            d = d + 4 * x + 6;
        else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}
