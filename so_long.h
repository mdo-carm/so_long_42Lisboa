/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:54:50 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/02/23 02:17:41 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "library/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

// typedef struct s_win
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	int		height;
// 	int		width;
// }		t_win;

typedef struct s_map
{
	char	**map;
	int		x_map;
	int		y_map;
}		t_map;


// t_win new_program(int width, int height, char *str)
// {
// 	void	*mlx_ptr;

// 	mlx_ptr = mlx_init();
// 	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, width, height, str), width, height});
// }

char	*get_next_line(int fd);
void	map_size(int fd);
void	map_create(int argc, char **argv);

#endif