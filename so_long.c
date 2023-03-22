/* ************************************************************************** */
/*                                                                            */
/*                                              d returned 1 exit status
make: *** [Makefile:34: so_long] Error 1
      +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:20:26 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/03/12 20:36:29 by mdo-carm         ###   ########.fr       */
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
	t_map		map;
	t_player	player;
	// int	i = 0; //REMOVE THIS WHEN PROJECT IS COMPLETE

	player.x_player = 0;
	player.y_player = 0;
	map.x_map = 0;
	map.y_map = 0;
	if (argc != 2)
		exit(printf("\t\tNOT ENOUGH PARAMETERS!!!\n"));
		// error_message("\tINCORRECT NUMBER OF PARAMETERS!\n", 1);
	if (map_create(&map, argv[1]))
		return (2);
	// while (map.map[i] != NULL)
	// {
	// 	printf("%s", map.map[i]); //REMOVE THIS WHEN PROJECT IS COMPLETE
	// 	i++;
	// }
	// printf("\n\n"); //REMOVE THIS WHEN PROJECT IS COMPLETE
	player_position(&player, &map);
	// printf("Player x_axis: %d\nPlayer y_axis: %d\n", player.x_player, player.y_player); //REMOVE THIS WHEN PROJECT IS COMPLETE
	start_game(&map, &player);
	free_map(&map);
	return (0);
}
