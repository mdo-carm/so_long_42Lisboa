/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:11:36 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/15 23:51:33 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_position(void)
{
	unsigned int	y;
	unsigned int	p_count;

	p_count = 0;
	y = 0;
	while (y < map()->y_map)
	{
		if (ft_strchr(map()->map[y], 'P') != NULL)
		{
			comp()->x_player = ft_strlen(map()->map[y]) \
			- ft_strlen(ft_strchr(map()->map[y], 'P'));
			comp()->y_player = y;
			p_count += 1;
		}
		y++;
	}
	if (p_count != 1)
		exit(printf("\tIncorrect amount of players\n")); //
	return(0);
}
