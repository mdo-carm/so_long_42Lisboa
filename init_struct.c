/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:39:58 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/15 19:20:17 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

t_win	*win(void)
{
	static t_win	win;

	return (&win);
}

t_img	*img(void)
{
	static t_img	img;

	return (&img);
}

t_comp	*comp(void)
{
	static t_comp	comp;

	return (&comp);
}

t_pic	*pic(void)
{
	static t_pic	pic;

	return (&pic);
}
