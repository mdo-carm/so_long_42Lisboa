/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:27:16 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/03/05 22:12:18 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win	new_program(int width, int height, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, width, height, str), width, height});
}

void	start_game(t_map *map, t_player *player)
{
	t_win win;

	if (!player)
		exit(EXIT_FAILURE);
	win = new_program(960, 640, "so_long");
	win_hooks(&win);
	mlx_loop(win.mlx_ptr);
}
