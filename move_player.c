/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:58:24 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/21 23:10:25 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move(int x, int y, int *player)
{
	if (map()->map[comp()->y_player + y][comp()->x_player + x] != '1')
		*player += x + y;
	if (comp()->collect > 0 && map()->map[comp()->y_player][comp()->x_player] == 'E')
		*player = *player - x - y;  
	if (map()->map[comp()->y_player][comp()->x_player] == 'C')
	{
		comp()->collect--;
		map()->map[comp()->y_player][comp()->x_player] = '0';
	}
	if (map()->map[comp()->y_player][comp()->x_player] == 'E' && comp()->collect == 0)
		close_program();
}

void	move_player(int keycode)
{
	if (keycode == LEFT)
		move(-1,0, &comp()->x_player);
	if (keycode == RIGHT)
		move(1,0, &comp()->x_player);
	if (keycode == UP)
		move(0,-1, &comp()->y_player);
	if (keycode == DOWN)
		move(0,1, &comp()->y_player);
	if (keycode == DOWN || keycode == UP || keycode == LEFT || keycode == RIGHT)
	{
		comp()->move_nbr += 1;
		ft_printf("%d\n", comp()->move_nbr);
	}
}

