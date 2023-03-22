/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:22:52 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/03/22 22:58:03 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_map *map, unsigned int i)
{
	i = 0;
	while (i < map->y_map - 1)
	{
		if ((ft_strlen(map->map[i]) - 1) != map->x_map)
		{
						printf("\tWrong map width1\n");
			free_map(map);
			exit(EXIT_FAILURE); //function that deals with errors
		}
		i++;
	}
	if (ft_strlen(map->map[map->y_map - 1]) != map->x_map)
	{
						printf("\tWrong map width2\n");
		free_map(map);
		exit(EXIT_FAILURE); //function that deals with errors
	}
}

void	map_size(t_map *map, int fd)
{
	char	*temp;

	temp = get_next_line(fd);
	if (temp != NULL)
		map->x_map = ft_strlen(temp) - 1;
								// printf("x_map = %d\n", map->x_map); 
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		map->y_map += 1;
	}
	free(temp);
								// printf("y_map = %d\n", map->y_map);
	if((map->x_map < 5 && map->y_map < 3) \
	|| (map->x_map < 3 && map->y_map < 5))
	{
								printf("\tWrong map dimensions\n");
		exit(EXIT_FAILURE); //function that deals with errors
	}
}

int	map_create(t_map *map, char *argv)
{
	int				fd;
	int				fd2;
	unsigned int	i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return(printf("map doesnt exist\n"));
	fd2 = open(argv, O_RDONLY);
	map_size(map, fd);
	map->map = (char **)ft_calloc((map->y_map + 1), sizeof(char *));
	i = 0;
	while (i < map->y_map && !map->map[i])
	{
		map->map[i] = get_next_line(fd2);
		i++;
	}
	check_map(map, i);
}
