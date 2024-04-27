# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 17:58:05 by ahamdi            #+#    #+#              #
#    Updated: 2024/04/27 11:44:21 by ahamdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


src = fdf.c  red_map.c  get_next_line/get_next_line_utils.c get_next_line/get_next_line.c drawin_3D.c control_mouse.c driwn_2D.c control_keybord.c projection.c graden_colore.c 
obj = $(src:.c=.o)
NAME =	fdf
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(obj)
	@$(MAKE) -C libft 
	@gcc -o $(NAME) $(obj) $(LIBFT) miniliblx/minilibx_macos/libmlx.a -framework OpenGL -framework AppKit  -O3
	@echo "\033[0;32mcompilation and created fdf programme\033[0m"

%.o: %.c fdf.h get_next_line/get_next_line.h 
	@gcc -c $< -o $@

clean:
	@$(MAKE) -C libft clean
	@rm -f $(obj)
	@echo "\033[0;32mdelete all object files of the fdf\033[0m"
	 

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)
	@echo "\033[0;32mdelete fdf programme\033[0m"

re: fclean all

.PHONY: all clean fclean re