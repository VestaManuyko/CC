# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 17:13:00 by vmanuyko          #+#    #+#              #
#    Updated: 2025/05/03 16:22:10 by vmanuyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft.a
CC = cc -Wall -Wextra -Werror
#everything needed for libft.a
LIBFTSRC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c \
libft/ft_memmove.c libft/ft_memset.c libft/ft_putendl_fd.c \
libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c \
libft/ft_get_next_line_utils.c libft/ft_strjoin.c libft/ft_strchr.c \
libft/ft_strdup.c libft/ft_striteri.c libft/ft_strlcat.c \
libft/ft_strlcpy.c libft/ft_strmapi.c libft/ft_strncmp.c \
libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strlen.c \
libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c \
libft/ft_toupper.c libft/ft_help.c libft/ft_printf.c \
libft/ft_get_next_line.c libft/ft_lstnew_bonus.c \
libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c \
libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c \
libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c \
libft/ft_putchar_fd.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c
OBJ = $(patsubst %.c, %.o, $(LIBFTSRC))
#project program sources and object files
PSRC = main.c free.c valid_map.c valid_map_helpers.c grid_handling.c valid_path.c
POBJ = $(patsubst %.c, %.o, $(PSRC))

all : $(NAME)

$(NAME) : $(LIBFT) $(POBJ)
	$(CC) $(POBJ) $(LIBFT) -o $(NAME)

$(LIBFT) : $(OBJ)
	ar -rsc $(LIBFT) $(OBJ)

clean :
	rm -f $(OBJ) $(POBJ)

fclean : clean
	rm -f $(LIBFT) 

re : fclean $(LIBFT) $(NAME)

.PHONY : all clean fclean re
