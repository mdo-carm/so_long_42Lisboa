/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:22:35 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/23 22:54:20 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
