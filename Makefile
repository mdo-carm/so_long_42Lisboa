# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 00:06:37 by mdo-carm          #+#    #+#              #
#    Updated: 2023/04/28 21:40:23 by mdo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

CC = gcc
RM = rm -rf

SOURCE_C = so_long.c map_create.c        \
           player_position.c start_game.c \
           hook_events.c free_map.c        \
           components_map.c init_struct.c   \
           put_img.c create_img.c            \
           move_player.c can_win.c            \

 CFLAGS = -Wall  \
          -Wextra \
          -Werror  \

all: $(NAME)

$(NAME): mlx_lib libft_lib ft_printf_lib $(SOURCE_C)
		@$(CC) $(CFLAGS) $(SOURCE_C) library/get_next_line/get_next_line.c library/libft/libft.a library/ft_printf/libftprintf.a library/mlx/libmlx.a -lXext -lX11 -o $@

mlx_lib:
		@$(MAKE) -C ./library/mlx --no-print-directory

libft_lib:
		@$(MAKE) -C ./library/libft --no-print-directory

ft_printf_lib:
		@$(MAKE) -C ./library/ft_printf --no-print-directory

clean: 
		@rm -rf $(OBJ)

fclean:	clean
		@$(RM) $(NAME) *.o
		@$(MAKE) clean -C ./library/mlx
		@$(MAKE) fclean -C ./library/libft
		@$(MAKE) fclean -C ./library/ft_printf

re: fclean all

.PHONY: all clean fclean re
