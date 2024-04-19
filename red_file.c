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

int get_width(char *line)
{
	int width;

	width = ft_count_words(line, ' ');
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

void red_file(char *argv,fdf **data)
{
	int i = 0;
	int y = 0;
	char *line;
	char **line_int;
	int  fd;

	(*data)->height = get_height(argv);
	(*data)->matrix = malloc (((*data)->height + 1)*sizeof(char **));
	fd = open(argv,O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	(*data)->width= get_width(line)-1;
	while(line)
	{
		(*data)->matrix[i] = malloc (((*data)->width + 1) * sizeof(char* ));
		line_int = ft_split(line,' ');
		y = 0;
		while(line_int[y])
		{
			if(ft_strchr(line_int[y],'\n') != NULL)
				line_int[y][ft_strlen(line_int[y]) - 1] = '\0';
			(*data)->matrix[i][y]= ft_strdup(line_int[y]);
			y++;
		}
		i++;
		line = get_next_line(fd);
	}
	(*data)->matrix[i] = NULL;
	i = 0;
	while(line_int[i])
	{
		free(line_int[i]);
		i++;
	}
	free(line_int);
	free(line);
	close (fd);
}

int hexToInt(const char *hex) {
    return (int)strtol(hex, NULL, 16);
}
