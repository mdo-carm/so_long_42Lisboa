/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:54:50 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/03/01 21:42:15 by mdo-carm         ###   ########.fr       */
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

// typedef struct s_win
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	int		height;
// 	int		width;
// }		t_win;

typedef struct map
{
	char	**map;
	int		x_map;
	int		y_map;
}		t_map;

typedef struct player
{
	int	x_player;
	int	y_player;
}		t_player;

// t_win new_program(int width, int height, char *str)
// {
// 	void	*mlx_ptr;

// 	mlx_ptr = mlx_init();
// 	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, width, height, str), width, height});
// }

char	*get_next_line(int fd);
void	map_size(t_map *map, int fd);
void	map_create(t_map *map, char *argv);
void	player_position(t_player *player, t_map *map);

#endif