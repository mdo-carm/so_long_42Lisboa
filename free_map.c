/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:22:35 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/26 21:12:22 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map2(char **map_arr)
{
	unsigned int	i;

	i = 0;
	while (i <= map()->y_map)
	{
		free(map_arr[i]);
		i++;
	}
	free(map_arr);
}

void	free_map(void)
{
	unsigned int	i;

	i = 0;
	while (i <= map()->y_map)
	{
		free(map()->map[i]);
		i++;
	}
	free(map()->map);
}
