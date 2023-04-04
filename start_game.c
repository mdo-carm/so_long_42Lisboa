/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:27:16 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/04 22:26:20 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win	new_program(int width, int height, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		exit (EXIT_FAILURE); //change to fuction that deals with errors
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, width, height, str), width, height});
}

unsigned int	my_mlx_pixel_get(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return(*(unsigned int*)dst);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	start_game(t_map *map, t_player *player)
{
	t_win	win;
	t_img	img;
	char	*relative_path = "./textures/1 Tiles/Tile_01.xpm";
	unsigned int color;
	int		i;

	if (!player && !map)
		exit(printf("Error\n")); //
	win = new_program(WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (win.win_ptr == NULL)
	{
		free(win.win_ptr);
		free_map(map);
		exit(printf("Error\nWindow not created\n")); //change to fuction that deals with errors
	}
	win.img.mlx_img = mlx_new_image(win.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	win.img.addr = mlx_get_data_addr(win.img.mlx_img, &win.img.bpp, &win.img.line_len, &win.img.endian);
	img.mlx_img = mlx_xpm_file_to_image(win.mlx_ptr, relative_path, &img.img_x, &img.img_y);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
	i = 0;
	while(i < 31)
	{
		color = my_mlx_pixel_get(&img, i, 15);
		my_mlx_pixel_put(&win.img, 200 + i, 200, color);
		i++;
	}
	win_hooks(&win, &img);
	mlx_loop(win.mlx_ptr);
	mlx_destroy_display(win.mlx_ptr);
	free(win.mlx_ptr);
}
