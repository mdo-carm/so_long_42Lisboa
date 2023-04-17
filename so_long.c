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

int	main(int argc, char **argv)
{
	t_map	map;
	t_comp	comp;
	// int	i = 0; //REMOVE THIS WHEN PROJECT IS COMPLETE

	comp.x_player = 0;
	comp.y_player = 0;
	map.x_map = 0;
	map.y_map = 0;
	if (argc != 2)
		exit(printf("\t\tNOT ENOUGH PARAMETERS!!!\n"));
		// error_message("\tINCORRECT NUMBER OF PARAMETERS!\n", 1);
	if (map_create(argv[1]))
		exit (printf("Error\nProblems creating map\n"));
	// while (map.map[i] != NULL)
	// {
	// 	printf("%s", map.map[i]); //REMOVE THIS WHEN PROJECT IS COMPLETE
	// 	i++;
	// }
	// printf("\n\n"); //REMOVE THIS WHEN PROJECT IS COMPLETE
	if (player_position())
		exit (printf("Error\nProblems creating map\n"));
	components_map();
	start_game();
	free_map();
	return (0);
}
