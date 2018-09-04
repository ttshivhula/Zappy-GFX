/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:20:21 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/04 10:37:21 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gfx.h>

static void player_size(t_graphics *gui, int x, int y)
{
	((gui->front).rect).x = x + 2;
	((gui->front).rect).y = y + 5;
	((gui->front).rect).w = 48;
	((gui->front).rect).h = 48;
	((gui->left).rect).x = x + 2;
	((gui->left).rect).y = y + 5;
	((gui->left).rect).w = 48;
	((gui->left).rect).h = 48;
	((gui->right).rect).x = x + 2;
	((gui->right).rect).y = y + 5;
	((gui->right).rect).w = 48;
	((gui->right).rect).h = 48;
	((gui->back).rect).x = x + 2;
	((gui->back).rect).y = y + 5;
	((gui->back).rect).w = 48;
	((gui->back).rect).h = 48;
}

void	draw_player(t_graphics *gui, int x, int y, int orient)
{
	player_size(gui, x, y);
	if (orient == 90)
	{
		SDL_RenderCopy(gui->renderer, (gui->right).texture, NULL,
			&((gui->right).rect));
	}
	else if (orient == 270)
	{
		SDL_RenderCopy(gui->renderer, (gui->left).texture, NULL,
			&((gui->left).rect));
	}
	else if (orient == 180)
	{
		SDL_RenderCopy(gui->renderer, (gui->front).texture, NULL,
			&((gui->front).rect));
	}
	else
	{
		SDL_RenderCopy(gui->renderer, (gui->back).texture, NULL,
			&((gui->back).rect));
	}
}
