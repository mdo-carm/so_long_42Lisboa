/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:27:16 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/03/15 23:16:54 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win	new_program(int width, int height, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		exit (EXIT_FAILURE); //change to fuction that deals with errors
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, width, height, str), width, height});
}

void	start_game(t_map *map, t_player *player)
{
	t_win win;

	if (!player && !map)
		exit(EXIT_FAILURE);
	win = new_program(960, 640, "so_long");
	if (win.win_ptr == NULL)
	{
		free(win.win_ptr);
		exit (EXIT_FAILURE); //change to fuction that deals with errors
	}
	win_hooks(&win);
	mlx_loop(win.mlx_ptr);
	mlx_destroy_display(win.mlx_ptr);
	free(win.mlx_ptr);
}
