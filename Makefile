src = fdf.c  red_file.c  get_next_line/get_next_line_utils.c get_next_line/get_next_line.c drawin_line.c
obj = $(src:.c=.o)
NAME =	fdf
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(obj)
	$(MAKE) -C libft 
	gcc -o $(NAME) $(obj) $(LIBFT) minilibx-linux/libmlx_Linux.a  -lX11 -lXext -lm

%.o: %.c fdf.h get_next_line/get_next_line.h
	gcc -c $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(obj) 

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re