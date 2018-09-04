/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:50:59 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/04 11:32:52 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gfx.h>

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
					draw_food(gui, ((gui->wall).rect).x, ((gui->wall).rect).y);
					draw_thystame(gui, ((gui->wall).rect).x, ((gui->wall).rect).y);
					draw_phiras(gui, ((gui->wall).rect).x, ((gui->wall).rect).y);
					draw_mendiane(gui, ((gui->wall).rect).x, ((gui->wall).rect).y);
					draw_sibur(gui, ((gui->wall).rect).x, ((gui->wall).rect).y);
					draw_deraumere(gui, ((gui->wall).rect).x, ((gui->wall).rect).y);
					draw_linemate(gui, ((gui->wall).rect).x, ((gui->wall).rect).y);
					draw_egg(gui, ((gui->wall).rect).x, ((gui->wall).rect).y);
					if (x == 3 && y == 3)
						draw_player(gui, ((gui->wall).rect).x, ((gui->wall).rect).y, 270);
				}
				else
				{
					SDL_RenderCopy(gui->renderer,
						       (gui->wall).texture,
						       NULL, &((gui->wall).rect));
				}
			}
			((gui->wall).rect).x += ((gui->wall).rect).w;
			x++;
		}
		((gui->wall).rect).y += ((gui->wall).rect).h;
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
	SDL_RenderCopy(gui->renderer, (gui->tmain).texture, NULL, &((gui->tmain).rect));
}

void	create_text_textures(t_graphics **ptr)
{
	SDL_Color color = {0, 0, 0, 0};
	((*ptr)->tmain).surface = TTF_RenderText_Solid((*ptr)->mfont, "ZAPPY", color);
	((*ptr)->tmain).texture = SDL_CreateTextureFromSurface((*ptr)->renderer, ((*ptr)->tmain).surface);
    SDL_QueryTexture(((*ptr)->tmain).texture, NULL, NULL, &(((*ptr)->tmain).rect).w, &(((*ptr)->tmain).rect).h);
	(((*ptr)->tmain).rect).x = 1024 + 32;
	(((*ptr)->tmain).rect).y = 0;
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

int	monkey(t_graphics **ptr)
{
	((*ptr)->front).surface = IMG_Load("media/front.png");
	((*ptr)->left).surface = IMG_Load("media/left.png");
	((*ptr)->right).surface = IMG_Load("media/right.png");
	((*ptr)->back).surface = IMG_Load("media/back.png");
	((*ptr)->front).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->front).surface);
	((*ptr)->right).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->right).surface);
	((*ptr)->left).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->left).surface);
	((*ptr)->back).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->back).surface);
	SDL_QueryTexture(((*ptr)->front).texture, NULL, NULL,
		     &(((*ptr)->front).rect).w, &(((*ptr)->front).rect).h);
	SDL_QueryTexture(((*ptr)->left).texture, NULL, NULL,
		     &(((*ptr)->left).rect).w, &(((*ptr)->left).rect).h);
	SDL_QueryTexture(((*ptr)->right).texture, NULL, NULL,
		     &(((*ptr)->right).rect).w, &(((*ptr)->right).rect).h);
	SDL_QueryTexture(((*ptr)->back).texture, NULL, NULL,
		     &(((*ptr)->back).rect).w, &(((*ptr)->back).rect).h);
	return (1);
}

int	entity_textures(t_graphics **ptr)
{
	((*ptr)->linemate).surface = IMG_Load("media/linemate.png");
	((*ptr)->deraumere).surface = IMG_Load("media/deraumere.png");
	((*ptr)->sibur).surface = IMG_Load("media/sibur.png");
	((*ptr)->mendiane).surface = IMG_Load("media/mendiane.png");
	((*ptr)->phiras).surface = IMG_Load("media/phiras.png");
	((*ptr)->thystame).surface = IMG_Load("media/thystame.png");
	((*ptr)->food).surface = IMG_Load("media/food.png");
	((*ptr)->egg).surface = IMG_Load("media/egg.png");


	((*ptr)->linemate).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->linemate).surface);
	((*ptr)->deraumere).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->deraumere).surface);
	((*ptr)->sibur).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->sibur).surface);
	((*ptr)->mendiane).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->mendiane).surface);
	((*ptr)->phiras).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->phiras).surface);
	((*ptr)->thystame).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->thystame).surface);
	((*ptr)->food).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->food).surface);
	((*ptr)->egg).texture = SDL_CreateTextureFromSurface(
			(*ptr)->renderer, ((*ptr)->egg).surface);

	SDL_QueryTexture(((*ptr)->linemate).texture, NULL, NULL,
		     &(((*ptr)->linemate).rect).w, &(((*ptr)->linemate).rect).h);
	SDL_QueryTexture(((*ptr)->deraumere).texture, NULL, NULL,
		     &(((*ptr)->deraumere).rect).w, &(((*ptr)->deraumere).rect).h);
	SDL_QueryTexture(((*ptr)->sibur).texture, NULL, NULL,
		     &(((*ptr)->sibur).rect).w, &(((*ptr)->sibur).rect).h);
	SDL_QueryTexture(((*ptr)->mendiane).texture, NULL, NULL,
		     &(((*ptr)->mendiane).rect).w, &(((*ptr)->mendiane).rect).h);
	SDL_QueryTexture(((*ptr)->phiras).texture, NULL, NULL,
		     &(((*ptr)->phiras).rect).w, &(((*ptr)->phiras).rect).h);
	SDL_QueryTexture(((*ptr)->thystame).texture, NULL, NULL,
		     &(((*ptr)->thystame).rect).w, &(((*ptr)->thystame).rect).h);
	SDL_QueryTexture(((*ptr)->food).texture, NULL, NULL,
		     &(((*ptr)->food).rect).w, &(((*ptr)->food).rect).h);
	SDL_QueryTexture(((*ptr)->egg).texture, NULL, NULL,
		     &(((*ptr)->egg).rect).w, &(((*ptr)->egg).rect).h);
	return (1);
}

int	create_textures(t_graphics **ptr)
{
	int error;

	error = 0;
	((*ptr)->grass).surface = IMG_Load("media/grass.png");
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
	create_text_textures(ptr);
	entity_textures(ptr);
	monkey(ptr);
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
	if(TTF_Init())
		error = 1;
	(*ptr)->mfont = TTF_OpenFont("media/font.ttf", 80);
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
			(mn->gui).y++;
			(mn->gui).x++;
			x = ft_map(x);
			y = ft_map(y);
			printf("mouse x: %d y: %d\n", x, y);
		}
		if (bottons & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
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

void	communication(void *ptr)
{
	t_main	*mn;
	static	first  = 0;
	char	buff[BUFF_SIZE];
	char	*tmp;

	bzero(buff, sizeof(buff));
	mn = (t_main *)ptr;
	if (first < 2)
	{
		read(mn->fd, buff, sizeof(buff));
		if (fisrt)
		{
			tmp = strchr(buff, ' ') + 1;
			(mn->gui).x = atoi(buff);
			(mn->gui).y = atoi(tmp);
		}
		else
			send(mn->fd, "GRAPHIC\n", 8, 0);
		first++;
	}
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
	
	set_fds_conn(&master, fd);
	mn.gui = *(*graphics);
	mn.fd = fd;
	mn.master = master;
	if(pthread_create(&thread, NULL, select_loop, (void *)&mn))
		printf("unable to create thread\n");
	render(&mn);
	pthread_join(thread, NULL);
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
