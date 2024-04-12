#include"fdf.h"
static int	ft_count_words(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == sep)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (count);
}

int get_width(char *argv)
{
	char *line;
	int width;
  
	int fd = open(argv,O_RDONLY);
	if(fd == -1)
	{
		ft_putstr_fd("erreure in open file",2);
		exit(3);
	}
	line = get_next_line(fd);
	width = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return(width);
}

int get_height(char *argv)
{
	char *line;
	int fd = open(argv,O_RDONLY);
	int i = 0;
	line = get_next_line(fd);
	while(line)
	{
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return(i);
	
}

char ***red_file(char *argv)
{
	int width;
	int height;
	int i = 0;
	int y = 0;
	char *line;
	char **line_int;
	char ***matrix;
	int  fd;
   
	width = get_width(argv);
	height = get_height(argv);
	matrix = malloc ((height + 1)*sizeof(char **));
	while(i <  height)
	{
		matrix[y] = malloc ((width + 1) * sizeof(char* ));
		y++;
		i++;
	}
	fd = open(argv,O_RDONLY);
	i = 0;
	while(line = get_next_line(fd))
	{
		line_int = ft_split(line,' ');
		y = 0;
		while(line_int[y])
		{
			
			if(ft_strchr(line_int[y],'\n') != NULL)
				line_int[y][ft_strlen(line_int[y]) - 1] = '\0';
			matrix[i][y]= ft_strdup(line_int[y]);
			y++;
		}
		i++;
	}
	matrix[i] = NULL;
	i = 0;
	while(line_int[i])
	{
		free(line_int[i]);
		i++;
	}
	free(line_int);
	free(line);
	return(matrix);
}

