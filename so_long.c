/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:20:26 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/02/28 19:43:00 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// t_win new_win(int width, int height, char *str);

// void start(void)
// {
// 	t_win win;

// 	win = new_win(win.width, win.height, "so_long");
// 	if (!win.mlx_ptr)
// 		exit(EXIT_FAILURE);
// }

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		exit(printf("\t\tNOT ENOUGH PARAMETERS!!!\n"));
		// error_message("\tINCORRECT NUMBER OF PARAMETERS!\n", 1);
	map_create(&map, argv[1]);
	return (0);
}
