/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:29:47 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/27 21:29:50 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit(ft_printf("ERROR\nNOT ENOUGH PARAMETERS!!!\n"));
	if (map_create(argv[1]))
	{
		free_map();
		exit (ft_printf("Error\nProblems creating map\n"));
	}
	if (player_position())
	{
		free_map();
		exit (ft_printf("Error\nProblems with player\n"));
	}
	components_map();
	can_win();
	start_game();
	free_map();
	return (0);
}
