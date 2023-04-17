/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:22:52 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/15 18:59:15 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cmp_map_to_wall(char *s1)
{
	int		i;
	char	x;

	x = '1';
	i = 0;
	while (s1[i] == x && s1[i] != '\0')
		i++;
	if (s1[i] == 0 || s1[i] == 10)
		i = 0;
	x = (unsigned char)s1[i] - (unsigned char)x;
	return (x);
}

int	check_walls(unsigned int i)
{
	if (cmp_map_to_wall(map()->map[0]) != 0 || \
	cmp_map_to_wall(map()->map[map()->y_map - 1]) != 0)
	{
		free_map();
		exit(printf("\tWalls don't surround map1\n")); //function that deals with errors
	}
	i = 1;
	while (i < map()->y_map && \
	map()->map[i][0] == '1' && map()->map[i][map()->x_map - 1] == '1')
		i++;
	if (i == map()->y_map)
		return (0);
	free_map();
	exit(printf("\tWalls don't surround map2\n"));
}

void	check_map(unsigned int i)
{
	while (i < map()->y_map - 1)
	{
		if ((ft_strlen(map()->map[i]) - 1) != map()->x_map)
		{
			free_map();
			exit(printf("\tWrong map width1\n")); //function that deals with errors
		}
		i++;
	}
	if (ft_strlen(map()->map[map()->y_map - 1]) != map()->x_map)
	{
		free_map();
		exit(printf("\tWrong map width2\n")); //function that deals with errors
	}
	check_walls(i);
}

void	map_size(int fd)
{
	char	*temp;

	temp = get_next_line(fd);
	if (temp != NULL)
		map()->x_map = ft_strlen(temp) - 1;
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		map()->y_map += 1;
	}
	free(temp);
	if((map()->x_map < 5 && map()->y_map < 3) \
	|| (map()->x_map < 3 && map()->y_map < 5))
		exit(printf("\tWrong map dimensions\n")); //function that deals with errors
	printf("x_map = %d\ny_map = %d\n", map()->x_map, map()->y_map);
}

int	map_create(char *argv)
{
	int				fd;
	int				fd2;
	unsigned int	i;
 
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return(printf("Map doesnt exist\n"));
	fd2 = open(argv, O_RDONLY);
	map_size(fd);
	map()->map = (char **)ft_calloc((map()->y_map + 1), sizeof(char *));
	i = 0;
	while (i < map()->y_map && !map()->map[i])
	{
		map()->map[i] = get_next_line(fd2);
		i++;
	}
	i = 0;
	check_map(i);
	return (0);
}
