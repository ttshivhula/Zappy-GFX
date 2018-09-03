/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:56:23 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/03 15:56:45 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gfx.h>

void	draw_deraumere(t_graphics *gui, int x, int y)
{
	((gui->deraumere).rect).x = x;
	((gui->deraumere).rect).y = y + 41;
	((gui->deraumere).rect).w = 20;
	((gui->deraumere).rect).h = 20;
	SDL_RenderCopy(gui->renderer,
					       (gui->deraumere).texture, NULL,
					       &((gui->deraumere).rect));
}

void	draw_linemate(t_graphics *gui, int x, int y)
{
	((gui->linemate).rect).x = x + 20;
	((gui->linemate).rect).y = y + 41;
	((gui->linemate).rect).w = 20;
	((gui->linemate).rect).h = 20;
	SDL_RenderCopy(gui->renderer,
					       (gui->linemate).texture, NULL,
					       &((gui->linemate).rect));
}

void	draw_egg(t_graphics *gui, int x, int y)
{
	((gui->egg).rect).x = x + 41;
	((gui->egg).rect).y = y + 41;
	((gui->egg).rect).w = 20;
	((gui->egg).rect).h = 20;
	SDL_RenderCopy(gui->renderer,
					       (gui->egg).texture, NULL,
					       &((gui->egg).rect));
}
