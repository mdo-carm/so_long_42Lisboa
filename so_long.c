/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:20:26 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/02/23 02:19:35 by mdo-carm         ###   ########.fr       */
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
	char	**map_arr;
	int	fd;

	// if (!argv[1] & argc != 2)
		// error_message("\tINCORRECT NUMBER OF PARAMETERS!\n", 1);
	map_create(argc, argv);
	return (0);
}
