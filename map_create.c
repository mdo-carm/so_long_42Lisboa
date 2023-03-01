/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:22:52 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/03/01 21:18:21 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_map *map, int fd)
{
	char	*temp;

	temp = get_next_line(fd);
	map->x_map = ft_strlen(temp) - 1;
	map->y_map = 0;
	while (temp)
	{
		temp = get_next_line(fd);
		map->y_map += 1;
	}
}

void	map_create(t_map *map, char *argv)
{
	int	fd;
	int	fd2;
	int	i;

	fd = open(argv, O_RDONLY);
	fd2 = open(argv, O_RDONLY);
	map_size(map, fd);
	map->map = (char **)ft_calloc((map->y_map + 1), sizeof(char *));
	i = 0;
	while (i < map->y_map && !map->map[i])
	{
		map->map[i] = get_next_line(fd2);
		i++;
	}
}
