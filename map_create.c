/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:22:52 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/27 21:50:24 by mdo-carm         ###   ########.fr       */
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
	if (cmp_map_to_wall(map()->map[0]) != 0 \
	|| cmp_map_to_wall(map()->map[map()->y_map - 1]) != 0)
	{
		free_map();
		exit(ft_printf("Error\nWalls don't surround map1\n"));
	}
	i = 1;
	while (i < map()->y_map && \
	map()->map[i][0] == '1' && map()->map[i][map()->x_map - 1] == '1')
		i++;
	if (i == map()->y_map)
		return (0);
	free_map();
	exit(ft_printf("Error\nWalls don't surround map2\n"));
}

void	check_map(unsigned int i)
{
	i = 0;
	while (i < map()->y_map - 1)
	{
		if (ft_strlen(map()->map[i]) != map()->x_map)
		{
			free_map();
			exit(ft_printf("Error\nWrong map dimensions1\n"));
		}
		i++;
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
		if (temp && temp[0] == '1')
			map()->y_map += 1;
		else if (temp && (temp[0] != '\n' || ft_strlen(temp) != 1))
			map()->x_map = 0;
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	if ((map()->x_map < 5 && map()->y_map < 3) \
	|| (map()->x_map < 3 && map()->y_map < 5))
		exit(ft_printf("Error\nWrong map dimensions3\n"));
}

int	map_create(char *argv)
{
	int				fd;
	int				fd2;
	unsigned int	i;
	char			*clear_nl;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nMap doesnt exist\n"));
	fd2 = open(argv, O_RDONLY);
	map_size(fd);
	(map()->map) = (char **)ft_calloc((map()->y_map + 1), sizeof(char *));
	i = 0;
	while (i < map()->y_map && !map()->map[i])
	{
		clear_nl = get_next_line(fd2);
		(map())->map[i] = ft_substr(clear_nl, 0, map()->x_map);
		free(clear_nl);
		i++;
	}
	check_map(i);
	return (0);
}
