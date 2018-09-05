/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09:31:12 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/05 12:20:46 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gfx.h>

int ft_map(int val)
{
	double x;

	x = ((val - 64) / 64);
	return ((int)x);
}

void	add_i(t_ent **ent, char *tmp)
{
	char	**s;
	t_ent	*t;

	s = ft_strsplit(tmp, ' ');
	printf("adding: %s\n", tmp);
	if (!*ent)
	{
		*ent = (t_ent  *)malloc(sizeof(t_ent));
		ft_strcpy((*ent)->name, s[0]);
		(*ent)->next = NULL;
		(*ent)->x = ft_atoi(s[1]);
		(*ent)->y = ft_atoi(s[2]);
		(*ent)->amount = ft_atoi(s[3]);
		return ;
	}
	t = (t_ent *)malloc(sizeof(t_ent));
	ft_strcpy(t->name, s[0]);
	t->next = *ent;
	t->x = ft_atoi(s[1]);
	t->y = ft_atoi(s[2]);
	t->amount = ft_atoi(s[3]);
	*ent = t;
}

void	add_items(t_ent **ent, char **ptr)
{
	*ent = NULL;
	while (*ptr)
	{
		add_i(ent, *ptr);
		ptr++;
	}
}

void	add_c(t_client **ent, char *tmp)
{
	char	**s;
	t_client	*t;

	s = ft_strsplit(tmp, ' ');
	printf("cliebt: %s\n", tmp);
	if (!*ent)
	{
		*ent = (t_client  *)malloc(sizeof(t_client));
		ft_strcpy((*ent)->name, s[0]);
		(*ent)->next = NULL;
		(*ent)->x = ft_atoi(s[1]);
		(*ent)->y = ft_atoi(s[2]);
		(*ent)->orientation = ft_atoi(s[3]);
		return ;
	}
	t = (t_client *)malloc(sizeof(t_client));
	ft_strcpy(t->name, s[0]);
	t->next = *ent;
	t->x = ft_atoi(s[1]);
	t->y = ft_atoi(s[2]);
	t->orientation = ft_atoi(s[3]);
	*ent = t;
}

void	add_client(t_client **ent, char **ptr)
{
	*ent = NULL;
	while (*ptr)
	{
		add_c(ent, *ptr);
		ptr++;
	}
}
