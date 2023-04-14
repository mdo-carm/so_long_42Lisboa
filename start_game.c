/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:27:16 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/14 22:48:45 by mdo-carm         ###   ########.fr       */
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

void	put_wall(t_win *win, t_img *img, char *relative_path)
{
	unsigned int color;
	int		x;
	int		y;

	img->mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, relative_path, &img->img_x, &img->img_y);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	x = 0;
	y = 0;
	while (y < 32)
	{
		while (x < 32)
		{
			if (color != 0x000000)
			{
				color = my_mlx_pixel_get(img, x, y);
				my_mlx_pixel_put(&win->img, x, y, color);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	start_game(t_map *map, t_comp *comp)
{
	t_win	win;
	t_img	img;
	char	*relative_path1 = "./textures/water_tile.xpm";
	char	*relative_path2 = "./textures/Player.xpm";

	if (!comp && !map)
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
	put_wall(&win, &img, relative_path1);
	put_wall(&win, &img, relative_path2);
	win_hooks(&win, &img);
	mlx_loop(win.mlx_ptr);
	mlx_destroy_display(win.mlx_ptr);
	free(win.mlx_ptr);
}
