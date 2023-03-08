/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:58:34 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/03/08 23:01:46 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	close_x(t_win *win)
{
	if (win)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
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

void	win_hooks(t_win *win)
{
	mlx_loop_hook(win->mlx_ptr, &handle_no_event, win);
	mlx_hook(win->win_ptr, 17, 0, close_x, win);
	mlx_hook(win->win_ptr, 3, 1L<<1, close_esc, win);
}
