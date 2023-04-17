/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:27:16 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/17 21:17:36 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_program(int width, int height, char *str)
{
	void	*mlx_ptr;

	win()->mlx_ptr = mlx_init();
	if (win()->mlx_ptr == NULL)
		exit (ft_printf("Error\nProblem with mlx pointer\n"));
	win()->width = width;
	win()->height = height;
	win()->win_ptr = mlx_new_window(win()->mlx_ptr, width, height, str);
}

void	start_game(void)
{
	if (!comp() && !map())
		exit(printf("Error\n")); //
	new_program(map()->x_map * 32, map()->y_map * 32, "so_long");
	if (win()->win_ptr == NULL)
	{
		free(win()->win_ptr);
		free_map();
		exit(ft_printf("Error\nWindow not created\n"));
	}
	create_img();
	win_hooks();
	put_img_player();
	comp()->move_nbr = 0;
	mlx_loop(win()->mlx_ptr);
	mlx_destroy_display(win()->mlx_ptr);
	free(win()->mlx_ptr);
}
