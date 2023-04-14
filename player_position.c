/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:11:36 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/14 22:49:11 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_position(t_comp *comp, t_map *map)
{
	unsigned int	i;
	unsigned int	p_count;

	p_count = 0;
	i = 0;
	while (i < map->y_map)
	{
		if (ft_strchr(map->map[i], 'P') != NULL)
		{
			comp->x_player = ft_strlen(map->map[i]) \
			- ft_strlen(ft_strchr(map->map[i], 'P'));
			p_count += 1;
		}
		comp->y_player += 1;
		i++;
	}
	if (p_count != 1)
		exit(printf("\tIncorrect amount of players\n")); //
	return(0);
}
