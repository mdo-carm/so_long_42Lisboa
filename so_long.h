/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:54:50 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/21 22:57:18 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "library/libft/libft.h"
# include "library/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 640
# define ESC 65307
# define UP 119
# define LEFT 97
# define RIGHT 100
# define DOWN 115

typedef struct s_map
{
	char			**map;
	unsigned int	x_map;
	unsigned int	y_map;
}		t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		img_x;
	int		img_y;
}	t_img;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	t_img	img;
}		t_win;

typedef struct s_comp
{
	int	x_player;
	int	y_player;
	int	move_nbr;
	int	collect;
	int	exit;
}		t_comp;

typedef struct s_pic
{
	t_img	coin;
	t_img	player;
	t_img	tree;
	t_img	wall;
	t_img	water;
}	t_pic;

char			*get_next_line(int fd);
void			map_size(int fd);
int				map_create(char *argv);
int				player_position(void);
void			start_game(void);
void			new_program(int width, int height, char *str);
int				close_program(void);
void			win_hooks(void);
void			free_map(void);
int				check_walls(unsigned int i);
int				cmp_map_to_wall(char *s1);
void			components_map(void);
unsigned int	my_mlx_pixel_get(t_img *data, int x, int y);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_map			*map(void);
t_win			*win(void);
t_img			*img(void);
t_comp			*comp(void);
t_pic			*pic(void);
void			put_img(void);
void			put_img2(t_img *img, int x, int y);
void			create_img(void);
t_img			create_img2(char *img_path);
void			put_img_player(void);
int				walk_player(int keycode);
void			move_player(int keycode);
void			move(int x, int y, int *player);

#endif