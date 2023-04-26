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
	unsigned int i = 0;

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
	while (i < map()->y_map)
	{
		printf("%s\n", map()->map[i]);
		i++;
	}
	// start_game();
	free_map();
	return (0);
}
