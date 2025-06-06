# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 11:10:25 by vmanuyko          #+#    #+#              #
#    Updated: 2025/05/09 15:18:23 by vmanuyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc -Wall -Wextra -Werror
SRC = ft_printf.c ft_help.c ft_strchr.c
OBJ = $(patsubst ft_%.c, ft_%.o, $(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $@ $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
