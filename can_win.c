/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:27:24 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/27 21:07:51 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **arr, int curr_x, int curr_y, char to_fill)
{
	if (curr_y < 0 || curr_y >= (int)map()->y_map || curr_x < 0 \
	|| curr_x >= (int)map()->x_map || \
	(arr[curr_y][curr_x] != '0' && arr[curr_y][curr_x] != 'C' \
	&& arr[curr_y][curr_x] != 'E' && arr[curr_y][curr_x] != 'P'))
		return ;
	if (arr[curr_y][curr_x] == 'E')
		comp()->can_win = 0;
	arr[curr_y][curr_x] = 'F';
	fill(arr, curr_x - 1, curr_y, to_fill);
	fill(arr, curr_x + 1, curr_y, to_fill);
	fill(arr, curr_x, curr_y - 1, to_fill);
	fill(arr, curr_x, curr_y + 1, to_fill);
}

void	can_win(void)
{
	unsigned int	i;
	char			**map2;

	comp()->can_win = 1;
	map2 = (char **)ft_calloc((map()->y_map + 1), sizeof(char *));
	i = 0;
	while (i < map()->y_map)
	{
		map2[i] = ft_strdup(map()->map[i]);
		i++;
	}
	fill(map2, comp()->x_player, comp()->y_player, \
	map2[comp()->y_player][comp()->x_player]);
	if (comp()->can_win != 0)
	{
		free_map();
		free_map2(map2);
		exit(ft_printf("Error\nNo path to victory!\n"));
	}
	free_map2(map2);
}
