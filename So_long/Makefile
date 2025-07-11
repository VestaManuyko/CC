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
BNS_NAME = so_long_bonus
LIBFT = libft.a
CC = cc -Wall -Wextra -Werror -g
#everything needed for libft.a
LIBFTSRC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c \
libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
libft/ft_isprint.c libft/ft_itoa.c libft/ft_memcmp.c libft/ft_memcpy.c \
libft/ft_memmove.c libft/ft_memset.c libft/ft_putendl_fd.c \
libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c \
libft/ft_get_next_line_utils.c libft/ft_strjoin.c libft/ft_strchr.c \
libft/ft_strdup.c libft/ft_striteri.c libft/ft_strlcat.c \
libft/ft_strlcpy.c libft/ft_strmapi.c libft/ft_strncmp.c \
libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strlen.c \
libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c \
libft/ft_toupper.c libft/ft_help.c libft/ft_printf.c \
libft/ft_get_next_line.c libft/ft_lstnew_bonus.c libft/ft_memchr.c \
libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c \
libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c \
libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c \
libft/ft_putchar_fd.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c
#project program sources
PSRC = main.c free.c valid_map.c valid_map_helpers.c grid_handling.c \
valid_path.c init.c hooks.c draw.c move.c move_helpers.c line.c
BSRC = bonus/main_bonus.c bonus/free_bonus.c bonus/valid_map_bonus.c \
bonus/valid_map_helpers_bonus.c bonus/grid_handling_bonus.c \
bonus/valid_path_bonus.c bonus/init_bonus.c bonus/hooks_bonus.c \
bonus/draw_bonus.c bonus/move_bonus.c bonus/move_helpers_bonus.c \
bonus/line_bonus.c bonus/free_helpers_bonus.c
#object files
OBJ = $(LIBFTSRC:.c=.o)
POBJ = $(PSRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(POBJ)
	@$(CC) -lmlx -lXext -lX11 $(POBJ) $(LIBFT) -o $(NAME)
	@echo "So_long compiled successfully."

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) : $(OBJ)
	@ar -rsc $(LIBFT) $(OBJ)

clean :
	@rm -f $(OBJ) $(POBJ) $(BOBJ)
	@echo "Cleaned."
fclean : clean
	@rm -f $(LIBFT) $(NAME) $(BNS_NAME)

re : fclean $(LIBFT) $(NAME) $(BNS_NAME)

bonus : $(BNS_NAME)

$(BNS_NAME) : $(LIBFT) $(BOBJ)
	@$(CC) -lmlx -lXext -lX11 $(BOBJ) $(LIBFT) -o $(BNS_NAME)
	@echo "So_long bonus compiled successfully."

.PHONY : all clean fclean re bonus
