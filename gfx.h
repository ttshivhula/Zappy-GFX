/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:49:17 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/03 18:34:17 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GFX_H
# define GFX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/param.h>
# include <stdint.h>
# include <sys/wait.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <dirent.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include "gfx_entity.h"

#ifdef __APPLE__
	#include <SDL_timer.h>
	#include <SDL_image.h>
	#include <SDL_ttf.h>
#else
	#include <SDL2/SDL_timer.h>
	#include <SDL2/SDL_image.h>
	#include <SDL2/SDL_ttf.h>
#endif

#define h_addr h_addr_list[0]
#define WINDOW_WIDTH 1280 - (64 * 4) //1280 //(1088 + 192) //15 blocks for game, 2 for boders
#define WINDOW_REAL_WIDTH 1280 + 64
#define WINDOW_HEIGHT (704) // 9 for game

typedef struct		s_sprite
{
	SDL_Surface*	surface;
	SDL_Texture	*texture;
	SDL_Rect	rect;
}			t_sprite;

typedef struct		s_text
{
	SDL_Surface*	surface;
	SDL_Texture		*texture;
	SDL_Rect		rect;
	SDL_Color		color;
}					t_text;

typedef struct		s_graphics
{
	SDL_Window	*window;
	SDL_Renderer	*renderer;
	int		x;
	int		y;
	TTF_Font			*mfont;
	t_sprite	wall;
	t_sprite	grass;
	t_sprite	water;
	t_sprite	linemate;
	t_sprite	deraumere;
	t_sprite	sibur;
	t_sprite	mendiane;
	t_sprite	phiras;
	t_sprite	thystame;
	t_sprite	food;
	t_sprite	egg;
	t_text		tmain;
}			t_graphics;

typedef	struct		s_main
{
	t_graphics	gui;
	fd_set		master;
	int		fd;
}			t_main;

void	draw_food(t_graphics *gui, int x, int y);
void	draw_egg(t_graphics *gui, int x, int y);
void	draw_thystame(t_graphics *gui, int x, int y);
void	draw_phiras(t_graphics *gui, int x, int y);
void	draw_mendiane(t_graphics *gui, int x, int y);
void	draw_sibur(t_graphics *gui, int x, int y);
void	draw_deraumere(t_graphics *gui, int x, int y);
void	draw_linemate(t_graphics *gui, int x, int y);

#endif
