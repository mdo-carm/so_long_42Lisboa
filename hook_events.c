/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:58:34 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/14 22:08:47 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_win *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.mlx_img, 0, 0);
	return (0);
}

int	close_x(t_win *win)
{
	if (win)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		win->win_ptr = NULL;
		mlx_loop_end(win->mlx_ptr);
	}
	return (0);
}

int	close_esc(int keycode, t_win *win)
{
	if (win && keycode == ESC)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		mlx_loop_end(win->mlx_ptr);
	}
	return (0);
}

// int	test_walk(int keycode, t_win *win)
// {
// 	if (keycode == RIGHT && win->img.img_xpos < 928)
// 		win->img.img_xpos += 32;
// 	if (keycode == LEFT && win->img.img_xpos >= 32)
// 		win->img.img_xpos -= 32;
// 	if (keycode == UP && win->img.img_ypos >= 32)
// 		win->img.img_ypos -= 32;
// 	if (keycode == DOWN && win->img.img_ypos < 608)
// 		win->img.img_ypos += 32;
// 	return (0);
// }

void	win_hooks(t_win *win, t_img *img)
{
	mlx_hook(win->win_ptr, 17, 0, close_x, win);
	mlx_hook(win->win_ptr, 3, 1L<<1, close_esc, win);
	// mlx_hook(win->win_ptr, 2, 1L<<0, test_walk, win);
	mlx_loop_hook(win->mlx_ptr, &handle_no_event, win);
}
