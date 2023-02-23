/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:22:52 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/02/23 02:20:24 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(int fd)
{
	t_map	map;
	char	*temp;

	temp = get_next_line(fd);
	map.x_map = ft_strlen(temp) - 1;
	map.y_map = 0;
	while (temp)
	{
		temp = get_next_line(fd);
		// if (map.x_map == ft_strlen(temp) - 1)
		// 	error_message("\tMap must be rectangular\n", 2);
		map.y_map += 1;
	}
	// if (map.y_map < 3)
	// error_message("\tMap must be rectangular\n", 2);
}

void	map_create(int argc, char **argv)
{
	t_map	map;
	int	fd;
	int	i;

	fd = open(argv[1], O_RDONLY);
	map_size(fd);
	map.map = (char **)ft_calloc((map.y_map + 1), sizeof(char *));
	i = 0;
	while (i < map.y_map)
	{
		map.map[i] = get_next_line(fd);
		i++;
	}
	i = 0;
	while (i < map.y_map)
	{
		ft_printf("%s\n", map.map[i]);
		i++;
	}
}