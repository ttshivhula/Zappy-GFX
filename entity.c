/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:54:43 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/03 15:56:04 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gfx.h>

void	draw_food(t_graphics *gui, int x, int y)
{
	((gui->food).rect).x = x;
	((gui->food).rect).y = y + 2;
	((gui->food).rect).w = 20;
	((gui->food).rect).h = 18;
	SDL_RenderCopy(gui->renderer,
					       (gui->food).texture, NULL,
					       &((gui->food).rect));
}

void	draw_thystame(t_graphics *gui, int x, int y)
{
	((gui->thystame).rect).x = x + 21;
	((gui->thystame).rect).y = y + 2;
	((gui->thystame).rect).w = 20;
	((gui->thystame).rect).h = 20;
	SDL_RenderCopy(gui->renderer,
					       (gui->thystame).texture, NULL,
					       &((gui->thystame).rect));
}

void	draw_phiras(t_graphics *gui, int x, int y)
{
	((gui->phiras).rect).x = x + 41;
	((gui->phiras).rect).y = y + 2;
	((gui->phiras).rect).w = 20;
	((gui->phiras).rect).h = 20;
	SDL_RenderCopy(gui->renderer,
					       (gui->phiras).texture, NULL,
					       &((gui->phiras).rect));
}

void	draw_mendiane(t_graphics *gui, int x, int y)
{
	((gui->mendiane).rect).x = x;
	((gui->mendiane).rect).y = y + 22;
	((gui->mendiane).rect).w = 20;
	((gui->mendiane).rect).h = 20;
	SDL_RenderCopy(gui->renderer,
					       (gui->mendiane).texture, NULL,
					       &((gui->mendiane).rect));
}

void	draw_sibur(t_graphics *gui, int x, int y)
{
	((gui->sibur).rect).x = x + 41;
	((gui->sibur).rect).y = y + 22;
	((gui->sibur).rect).w = 20;
	((gui->sibur).rect).h = 20;
	SDL_RenderCopy(gui->renderer,
					       (gui->sibur).texture, NULL,
					       &((gui->sibur).rect));
}
