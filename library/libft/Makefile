# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 00:00:15 by mdo-carm          #+#    #+#              #
#    Updated: 2023/02/28 19:37:42 by mdo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_SOURCE = ft_memset.c   ft_strlcat.c     \
           ft_bzero.c    ft_strnstr.c     \
           ft_memcpy.c   ft_atoi.c        \
           ft_memmove.c  ft_calloc.c      \
           ft_memchr.c   ft_strdup.c      \
           ft_memcmp.c   ft_substr.c      \
           ft_strlen.c   ft_strjoin.c     \
           ft_isalpha.c  ft_strtrim.c     \
           ft_isdigit.c  ft_split.c       \
           ft_isalnum.c  ft_itoa.c        \
           ft_isascii.c  ft_strmapi.c     \
           ft_isprint.c  ft_putchar_fd.c  \
           ft_toupper.c  ft_putstr_fd.c   \
           ft_tolower.c  ft_putendl_fd.c  \
           ft_strchr.c   ft_putnbr_fd.c   \
           ft_strrchr.c  ft_strncmp.c     \
           ft_striteri.c ft_strlcpy.c     \

OBJ = $(C_SOURCE:.c=.o)

CC = gcc

CFLAGS = -Wall    \
         -Wextra  \
         -Werror  \

all: $(NAME)

$(NAME): $(OBJ)
		@ar -rcs $(NAME) $(OBJ)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean: 
		@rm -rf $(OBJ)
		@echo "Libft cleaned"

fclean:	clean
		@rm -rf $(NAME)
		@echo "Libft full cleaned"

re: fclean all

.PHONY: all clean fclean re
