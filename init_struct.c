/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:55:16 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/05 22:36:31 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

t_img	*img(void)
{
	static	t_img	img;
	
	return (&img);
}

t_win	*win(void)
{
	static	t_win	win;
	
	return (&img);
}

t_player	*player()
{
	static t_player	player;
	
	return (&img);
}
