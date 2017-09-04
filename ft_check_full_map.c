/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_full_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 10:50:30 by jyakdi            #+#    #+#             */
/*   Updated: 2017/04/17 14:00:14 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_check_tp2(t_all *all)
{
	int		i;
	int		j;
	int		tp2;

	tp2 = 0;
	i = 0;
	while (i < all->img->map->height)
	{
		j = 0;
		while (j < all->img->map->width)
		{
			if (all->img->map->tab[i][j] == 5)
				tp2++;
			j++;
		}
		i++;
	}
	return (tp2);
}

int		ft_check_tp1(t_all *all)
{
	int		i;
	int		j;
	int		tp1;

	tp1 = 0;
	i = 0;
	while (i < all->img->map->height)
	{
		j = 0;
		while (j < all->img->map->width)
		{
			if (all->img->map->tab[i][j] == 4)
				tp1++;
			j++;
		}
		i++;
	}
	return (tp1);
}

int		ft_check_player(t_all *all)
{
	int		i;
	int		j;
	int		player;

	player = 0;
	i = 0;
	while (i < all->img->map->height)
	{
		j = 0;
		while (j < all->img->map->width)
		{
			if (all->img->map->tab[i][j] == 2)
				player++;
			j++;
		}
		i++;
	}
	return (player);
}

int		ft_check_map(t_all *all)
{
	int		player;
	int		tp1;
	int		tp2;

	player = 0;
	tp1 = 0;
	tp2 = 0;
	player = ft_check_player(all);
	tp1 = ft_check_tp1(all);
	tp2 = ft_check_tp2(all);
	if (player == 1 && ((tp1 == 0 && tp2 == 0) || (tp1 == 1 && tp2 == 1)))
		return (1);
	return (0);
}
