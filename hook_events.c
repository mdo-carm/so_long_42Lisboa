/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:58:34 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/19 22:04:57 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void)
{
	put_img();
	put_img_player();
	mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, win()->img.mlx_img, 0, 0);
	return (0);
}

int	close_x(void)
{
	if (win())
	{
		mlx_destroy_window(win()->mlx_ptr, win()->win_ptr);
		win()->win_ptr = NULL;
		mlx_loop_end(win()->mlx_ptr);
	}
	return (0);
}

int	close_esc(int keycode)
{
	if (win() && keycode == ESC)
	{
		mlx_destroy_window(win()->mlx_ptr, win()->win_ptr);
		win()->win_ptr = NULL;
		mlx_loop_end(win()->mlx_ptr);
	}
	return (0);
}

int	walk_player(int keycode)
{
	move_player(keycode);
	return (0);
}

void	win_hooks(void)
{
	mlx_hook(win()->win_ptr, 2, 1L<<0, walk_player, win);
	mlx_hook(win()->win_ptr, 17, 0, close_x, win);
	mlx_hook(win()->win_ptr, 3, 1L<<1, close_esc, win);
	mlx_loop_hook(win()->mlx_ptr, &handle_no_event, win);
}
