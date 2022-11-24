# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 00:06:37 by mdo-carm          #+#    #+#              #
#    Updated: 2022/11/23 21:32:51 by mdo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

CC = gcc
RM = rm -rf

SOURCE_C = test.c \

CFLAGS = -Wall  \
         -Wextra \
         -Werror  \

all: $(NAME)

$(NAME): mlx_lib $(SOURCE_C)
		@$(CC) $(CFLAGS) $(SOURCE_C) mlx/libmlx.a -lXext -lX11 -o $@

mlx_lib:
		@$(MAKE) -C ./mlx --no-print-directory

clean: 
		@rm -rf $(OBJ)

fclean:	clean
		@$(RM) $(NAME) *.o
		@$(MAKE) clean -C ./mlx

re: fclean all

.PHONY: all clean fclean re

# gcc test.c mlx/libmlx.a -L/usr/lib -c test.o
# ar -rcs test.a mlx/libmlx.a test.o
# gcc test.c test.a -o test