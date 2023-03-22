/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:54:50 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/03/22 22:57:47 by mdo-carm         ###   ########.fr       */
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

# define ESC 65307

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
}	t_img;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct player
{
	int	x_player;
	int	y_player;
}		t_player;

char	*get_next_line(int fd);
void	map_size(t_map *map, int fd);
int		map_create(t_map *map, char *argv);
void	player_position(t_player *player, t_map *map);
void	start_game(t_map *map, t_player *player);
t_win	new_program(int width, int height, char *str);
int		close_x(t_win *win);
int		close_esc(int keycode, t_win *win);
void	win_hooks(t_win *win);
void	free_map(t_map *map);

#endif