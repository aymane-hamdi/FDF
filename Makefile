# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 17:58:05 by ahamdi            #+#    #+#              #
#    Updated: 2024/05/05 13:15:02 by ahamdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


src = mandatory/fdf.c  mandatory/red_map.c  get_next_line/get_next_line_utils.c get_next_line/get_next_line.c mandatory/drawin_3D.c   mandatory/control_keybord.c  mandatory/graden_colore.c  mandatory/red_map_con.c
srcb = bonus/control_keybord_bonus.c  bonus/control_mouse_bonus.c  bonus/drawin_3D_bonus.c  bonus/mouv_keybord.c bonus/driwn_2D_bonus.c  bonus/fdf_bonus.c  bonus/graden_colore_bonus.c  bonus/red_map_bonus.c bonus/rotaion_contunu_bonus.c bonus/projection_bonus.c  get_next_line/get_next_line_utils.c get_next_line/get_next_line.c bonus/red_map_con_bonus.c
obj = $(src:.c=.o)
objb = $(srcb:.c=.o)
NAME =	fdf
BONUS = fdf_bonus
LIBFT = libft/libft.a
Header_mandatory =  mandatory/fdf.h
Header_bonus = bonus/fdf_bonus.h
Header_gnl = get_next_line/get_next_line.h 
all: $(NAME)

$(NAME): $(obj)
	@$(MAKE) -C libft 
	@gcc -o $(NAME) $(obj) $(LIBFT) miniliblx/minilibx_macos/libmlx.a -framework OpenGL -framework AppKit 
	@echo "\033[0;32mcompilation and created fdf programme\033[0m"

bonus: $(BONUS)

$(BONUS): $(objb)
	@$(MAKE) -C libft 
	@gcc -o $(BONUS) $(objb) $(LIBFT) miniliblx/minilibx_macos/libmlx.a -framework OpenGL -framework AppKit  
	@echo "\033[0;32mcompilation and created fdf bonus programme\033[0m"

%.o: %.c $(Header_mandatory) $(Header_gnl) $(Header_bonus)
	@gcc -c $< -o $@
    
clean:
	@$(MAKE) -C libft clean
	@rm -f $(obj) $(objb)
	@echo "\033[0;32mdelete all object files of the fdf\033[0m"
     

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME) $(BONUS)
	@echo "\033[0;32mdelete fdf programme\033[0m"

re: fclean all

.PHONY: all clean fclean re