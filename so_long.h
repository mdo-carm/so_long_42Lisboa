/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:54:50 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/04 21:56:06 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "library/libft/libft.h"
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

typedef struct s_player
{
	int	x_player;
	int	y_player;
	int	collect;
	int	exit;
}		t_player;

char	*get_next_line(int fd);
void	map_size(t_map *map, int fd);
int		map_create(t_map *map, char *argv);
int		player_position(t_player *player, t_map *map);
void	start_game(t_map *map, t_player *player);
t_win	new_program(int width, int height, char *str);
int		close_x(t_win *win);
int		close_esc(int keycode, t_win *win);
void	win_hooks(t_win *win, t_img *img);
void	free_map(t_map *map);
int		check_walls(t_map *map, unsigned int i);
int		cmp_map_to_wall(char *s1);
void	components_map(t_map *map, t_player *player);

#endif