/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:11:36 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/03/01 21:40:09 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_player *player, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y_map && (ft_strchr(map->map[i], 'P') == NULL))
	{
		player->y_player += 1;
		i++;
	}
	player->x_player = ft_strlen(map->map[i]) \
	- ft_strlen(ft_strchr(map->map[i], 'P'));
}
