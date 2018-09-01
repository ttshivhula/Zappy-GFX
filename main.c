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


#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

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

typedef struct		s_graphics
{
	SDL_Window	*window;
	SDL_Renderer	*renderer;
	int		x;
	int		y;
	t_sprite	wall;
	t_sprite	grass;
	t_sprite	water;
}			t_graphics;

typedef	struct		s_main
{
	t_graphics	gui;
	fd_set		master;
	int		fd;
}			t_main;

void	draw_boaders(t_graphics *gui)
{
	int x;
	int y;

	((gui->wall).rect).y = 0;
	((gui->wall).rect).w = 64;
	((gui->wall).rect).h = 64;
	y = -1;
	while (((gui->wall).rect).y < WINDOW_HEIGHT)
	{
		((gui->wall).rect).x = 0;
		x = -1;
		while (((gui->wall).rect).x < WINDOW_WIDTH)
		{
			if ((!((gui->wall).rect).y || ((gui->wall).rect).y == WINDOW_HEIGHT - ((gui->wall).rect).h) ||
			    (!((gui->wall).rect).x || ((gui->wall).rect).x == WINDOW_WIDTH - ((gui->wall).rect).w))
			{
				SDL_RenderCopy(gui->renderer,
					       (gui->wall).texture, NULL,
					       &((gui->wall).rect));
			}
			else
			{
				if (x < gui->x && y < gui->y)
				{
					SDL_RenderCopy(gui->renderer,
						       (gui->grass).texture,
						       NULL, &((gui->wall).rect));
				}
				else
				{
					SDL_RenderCopy(gui->renderer,
						       (gui->wall).texture,
						       NULL, &((gui->wall).rect));
				}
			}
			((gui->wall).rect).x += ((gui->wall).rect).w;
			//((gui->wall).rect).x += ((gui->wall).rect).w;
			x++;
		}
		((gui->wall).rect).y += ((gui->wall).rect).h;
	//	((gui->wall).rect).y += ((gui->wall).rect).h;
		y++;
	}
}

void	draw_menu(t_graphics *gui)
{	
	((gui->water).rect).y = 0;
	((gui->water).rect).w = 64;
	((gui->water).rect).h = 64;
	while (((gui->water).rect).y < WINDOW_HEIGHT)
	{
		((gui->water).rect).x = WINDOW_WIDTH;
		while (((gui->water).rect).x < WINDOW_REAL_WIDTH)
		{
			SDL_RenderCopy(gui->renderer,
				       (gui->water).texture,
				       NULL, &((gui->water).rect));
			((gui->water).rect).x += ((gui->water).rect).w;
		}
		((gui->water).rect).y += ((gui->water).rect).h;
	}
}

int	texture_info(t_graphics **ptr)
{
    SDL_QueryTexture(((*ptr)->grass).texture, NULL, NULL,
		     &(((*ptr)->grass).rect).w, &(((*ptr)->grass).rect).h);
    SDL_QueryTexture(((*ptr)->wall).texture, NULL, NULL,
		     &(((*ptr)->wall).rect).w, &(((*ptr)->wall).rect).h);
    SDL_QueryTexture(((*ptr)->water).texture, NULL, NULL,
		     &(((*ptr)->water).rect).w, &(((*ptr)->water).rect).h);
    return (1);
}

int	create_textures(t_graphics **ptr)
{
	int error;

	error = 0;
	((*ptr)->grass).surface = IMG_Load("media/cartoonGrass.png");
	((*ptr)->wall).surface = IMG_Load("media/cartoonWall.png");
	((*ptr)->water).surface = IMG_Load("media/ground.jpg");
	if (!((*ptr)->grass).surface || !((*ptr)->wall).surface ||
	    !((*ptr)->water).surface)
		error = 1;
	((*ptr)->grass).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->grass).surface);
	((*ptr)->wall).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->wall).surface);
	((*ptr)->water).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->water).surface);
	SDL_FreeSurface(((*ptr)->grass).surface);
	SDL_FreeSurface(((*ptr)->wall).surface);
	SDL_FreeSurface(((*ptr)->water).surface);
	if (!((*ptr)->wall).texture  || !((*ptr)->grass).texture ||
	    !((*ptr)->grass).texture || error)
	{
		printf("Error: %s\n", SDL_GetError());
		SDL_DestroyRenderer((*ptr)->renderer);
		SDL_DestroyWindow((*ptr)->window);
		SDL_Quit();
		return 0;
	}
	return (texture_info(ptr));
}

int	init_graphics(t_graphics **ptr)
{
	int	error;
	Uint32	render_flags;

	error = 0;
	*ptr = (t_graphics *)malloc(sizeof(t_graphics));
	(*ptr)->x = 0;
	(*ptr)->y = 0;
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
		error = 1;
	(*ptr)->window = SDL_CreateWindow("WTC - Zappy",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       WINDOW_REAL_WIDTH, WINDOW_HEIGHT,0);
	render_flags = SDL_RENDERER_ACCELERATED;
	(*ptr)->renderer = SDL_CreateRenderer((*ptr)->window, -1, render_flags);
	if (!(*ptr)->renderer || !(*ptr)->window || error)
	{
		printf("Error: %s\n", SDL_GetError());
		SDL_DestroyWindow((*ptr)->window);
		SDL_Quit();
		return 0;
	}
	return (create_textures(ptr));
}

void		set_fds_conn(fd_set *master, int fd)
{
	FD_ZERO(master);
	FD_SET(fd, master);
	FD_SET(1, master);
}

void	*render(void *ptr)
{
	t_main *mn = (void *)ptr;
	int	x;
	int	y;
	int	bottons;
	while (1)
	{
		SDL_PumpEvents();
		bottons = SDL_GetMouseState(&x, &y);
		SDL_RenderClear((mn->gui).renderer);
		if (bottons & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			//printf("mouse x: %d y: %d\n", x, y);
			(mn->gui).y++;
			(mn->gui).x++;
		}
		if (bottons & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			//printf("mouse x: %d y: %d\n", x, y);
			(mn->gui).y--;
			(mn->gui).x--;
		}
		draw_boaders(&(mn->gui));
		draw_menu(&(mn->gui));
		SDL_RenderPresent((mn->gui).renderer);
		SDL_Delay(1000/100);
	}
	return ptr;
}

void	*select_loop(void *ptr)
{
	t_main *mn;

	mn = (t_main *)ptr;
	fd_set copy = mn->master;
	while (select(FD_SETSIZE, &copy, NULL, NULL, NULL) > -1)
	{
		int i = 0;
		while (i < FD_SETSIZE)
		{
			if (FD_ISSET(i, &copy))
			{
				char buff[4096];
				if (!read(mn->fd, buff, sizeof(buff)))
				{
					SDL_Quit();
					exit(0);
				}
				if (strchr(buff, '*'))
				{
					SDL_Quit();
					exit(0);
				}
				if (strchr(buff, '+')){
				(mn->gui).y++;
				(mn->gui).x++;
				}
				else
				{
				(mn->gui).y--;
				(mn->gui).x--;
				}
			}
			i++;
		}
		copy = mn->master;
	}
	return (ptr);
}

void	threads(int fd, t_graphics **graphics)
{
	t_main				mn;
	fd_set				master;
	pthread_t			thread;
	pthread_t			thread2;
	pthread_attr_t			attr;
	
	set_fds_conn(&master, fd);
	mn.gui = *(*graphics);
	mn.fd = fd;
	mn.master = master;
	pthread_attr_init(&attr);
	if (!pthread_create(&thread, &attr, render, &mn))
		printf("success 1\n");
	if(!pthread_create(&thread2, &attr, select_loop, (void *)&mn))
		printf("success 2\n");
	pthread_join(thread, NULL);
	pthread_join(thread2, NULL);
}

int	main(int c, char **v)
{
	struct sockaddr_in	addr;
	struct hostent		*host;
	int					fd;
	t_graphics			*gui;

	addr.sin_family = AF_INET;
	host = NULL;
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if ((host = gethostbyname(v[1])) == NULL)
	{
		printf("failed to get host\n");
		exit(1);
	}
	addr.sin_port = htons(atoi(v[2]));
	memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);
	if (connect(fd, (void*)&(addr), sizeof(addr)) < 0)
	{
		printf("failed to connect\n");
			exit(1);
	}
	if (!init_graphics(&gui))
		exit(1);
	threads(fd, &gui);
}
