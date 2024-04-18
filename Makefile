# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 17:58:05 by ahamdi            #+#    #+#              #
#    Updated: 2024/04/18 21:12:15 by ahamdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


src = fdf.c  red_file.c  get_next_line/get_next_line_utils.c get_next_line/get_next_line.c drawin_3D.c control_mouse.c driwn_2D.c control_keybord.c
obj = $(src:.c=.o)
NAME =	fdf
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(obj)
	$(MAKE) -C libft 
	gcc -o $(NAME) $(obj) $(LIBFT) miniliblx/minilibx_macos/libmlx.a -framework OpenGL -framework AppKit  

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