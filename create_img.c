/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:23:05 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/27 23:15:51 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	create_img2(char *img_path)
{
	t_img	img;

	img.mlx_img = \
	mlx_xpm_file_to_image(win()->mlx_ptr, img_path, &img.img_x, &img.img_y);
	img.addr = \
	mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
	return ((t_img){img.mlx_img, img.addr, img.bpp, \
	img.line_len, img.endian, img.img_x, img.img_y});
}

void	create_img(t_img *img)
{
	win()->action = 0;
	img->mlx_img = mlx_new_image(win()->mlx_ptr, \
	map()->x_map * 32, map()->y_map * 32);
	img->addr = mlx_get_data_addr(img->mlx_img, \
	&img->bpp, &img->line_len, &img->endian);
	pic()->coin = create_img2("./textures/fish.xpm");
	pic()->player[0] = create_img2("./textures/player.xpm");
	pic()->player[1] = create_img2("./textures/player2.xpm");
	pic()->player[2] = create_img2("./textures/player3.xpm");
	pic()->player[3] = create_img2("./textures/player4.xpm");
	pic()->player[4] = create_img2("./textures/player5.xpm");
	pic()->player[5] = create_img2("./textures/player6.xpm");
	pic()->tree = create_img2("./textures/tree_exit.xpm");
	pic()->wall = create_img2("./textures/wall_tile.xpm");
	pic()->water = create_img2("./textures/water2_tile.xpm");
}
