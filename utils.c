/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09:31:12 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/04 10:07:20 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gfx.h>

int ft_map(int val)
{
	double x;

	x = ((val - 64) / 64);
	return ((int)x);
}
