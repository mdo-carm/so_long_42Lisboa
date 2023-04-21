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
	if (argc != 2)
		exit(printf("\t\tNOT ENOUGH PARAMETERS!!!\n"));
	if (map_create(argv[1]))
		exit (printf("Error\nProblems creating map\n"));
	if (player_position())
		exit (printf("Error\nProblems creating map\n"));
	components_map();
	start_game();
	free_map();
	return (0);
}
