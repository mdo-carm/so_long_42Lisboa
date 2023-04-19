/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:23:00 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/19 22:54:51 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	put_img2(t_img *img, int x_pos, int y_pos)
{
	unsigned int color;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 32)
	{
		while (x < 32)
		{
			color = my_mlx_pixel_get(img, x, y);
			if (color != 4278190080)
			{
				my_mlx_pixel_put(&win()->img, x + (x_pos * 32), y + (y_pos * 32), (int)color);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	put_img_player(void)
{
	put_img2(&pic()->player, comp()->x_player, comp()->y_player);
}

void	put_img(void)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map()->y_map)
	{
		while (x < map()->x_map)
		{
			if (map()->map[y][x] == '1')
				put_img2(&pic()->wall, x, y);
			else
			{
				put_img2(&pic()->water, x, y);
				if (map()->map[y][x] == 'E')
					put_img2(&pic()->tree, x, y);
				if (map()->map[y][x] == 'C')
					put_img2(&pic()->coin, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
