# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 22:12:45 by ahamdi            #+#    #+#              #
#    Updated: 2024/05/14 11:05:16 by ahamdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c  ft_is_sep.c \
	   ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	   ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	   ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
	   ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	   ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
	   ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	   ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	   ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJS = ${SRCS:.c=.o}
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@echo "\033[0;32mlibft.a created\033[0m"     

%.o: %.c libft.h
	@${CC} ${CFLAGS} -c $< -o$@
clean:
	@rm -f ${OBJS}
	@echo "\033[0;32mdelete all object files the libft \033[0m"

fclean: clean
	@rm -f ${NAME}
	@echo "\033[0;32mdelete libft.a\033[0m"

re: fclean all

.PHONY : all  clean fclean re
