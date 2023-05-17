/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:58:24 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/05/17 23:06:15 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(int x, int y, int *player, int flag)
{
	if (map()->map[comp()->y_player + y][comp()->x_player + x] != '1')
	{
		*player += x + y;
		flag = 1;
	}
	if (map()->map[comp()->y_player][comp()->x_player] == 'C')
	{
		comp()->collect--;
		map()->map[comp()->y_player][comp()->x_player] = '0';
	}
	if (flag == 1)
	{
		comp()->move_nbr += 1;
		ft_printf("Number of movements: %d\n", comp()->move_nbr);
	}
	if (map()->map[comp()->y_player][comp()->x_player] == \
	'E' && comp()->collect == 0)
		close_program();
}

void	move_player(int keycode)
{
	int	flag;

	flag = 0;
	if (keycode == LEFT)
		move(-1, 0, &comp()->x_player, flag);
	if (keycode == RIGHT)
		move(1, 0, &comp()->x_player, flag);
	if (keycode == UP)
		move(0, -1, &comp()->y_player, flag);
	if (keycode == DOWN)
		move(0, 1, &comp()->y_player, flag);
}
