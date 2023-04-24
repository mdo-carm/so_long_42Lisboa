/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:51:09 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/23 20:55:55 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	components_map(void)
{
	unsigned int	i;
	unsigned int	exit_count;
	unsigned int	collect_count;
	char			*x;

	exit_count = 0;
	collect_count = 0;
	i = 0;
	while (i < map()->y_map)
	{
		x = map()->map[i];
		if (ft_strchr(map()->map[i], 'E') != NULL)
			exit_count += 1;
		while (ft_strchr(x, 'C') != NULL)
		{
			collect_count += 1;
			x = ft_strchr(x, 'C');
			x++;
		}
		i++;
	}
	comp()->collect = collect_count;
	if (collect_count < 1 || exit_count != 1)
		exit(ft_printf("Error\nIncorrect amount of components!\n"));
}
