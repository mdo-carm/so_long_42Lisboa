# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 00:06:37 by mdo-carm          #+#    #+#              #
#    Updated: 2023/01/12 02:30:23 by mdo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

CC = gcc
RM = rm -rf

SOURCE_C = so_long.c \ library/get_next_line.c

#CFLAGS = -Wall  \
         -Wextra \
         -Werror  \

all: $(NAME)

$(NAME): mlx_lib libft_lib $(SOURCE_C)
		@$(CC) $(CFLAGS) $(SOURCE_C) library/libft/libft.a mlx/libmlx.a -lXext -lX11 -o $@

mlx_lib:
		@$(MAKE) -C ./mlx --no-print-directory

libft_lib:
		@$(MAKE) -C ./library/libft --no-print-directory

clean: 
		@rm -rf $(OBJ)

fclean:	clean
		@$(RM) $(NAME) *.o
		@$(MAKE) clean -C ./mlx
		@$(MAKE) fclean -C ./library/libft

re: fclean all

.PHONY: all clean fclean re

# gcc test.c mlx/libmlx.a -L/usr/lib -c test.o
# ar -rcs test.a mlx/libmlx.a test.o
# gcc test.c test.a -o test