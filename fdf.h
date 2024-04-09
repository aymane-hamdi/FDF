#ifndef FDF_H
#define FDF_H
#include"libft/libft.h"
#include"get_next_line/get_next_line.h"
#include<stdio.h>
#include<fcntl.h>

int **red_file(char *argv);
int get_height(char *argv);
int get_width(char *argv);
int	ft_len(int nb);
#endif