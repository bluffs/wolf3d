/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:32:14 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/10 09:42:26 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_menu(t_all *all)
{
	int		color;

	color = 0x00FFFFFF;
	if (mlx_string_put(all->mlx, all->screen->win, 30, 50, color,
				"Commandes :") == -1)
		return (-1);
	if (mlx_string_put(all->mlx, all->screen->win, 30, 75, color,
				"Move : arrows") == -1)
		return (-1);
	if (mlx_string_put(all->mlx, all->screen->win, 30, 90, color,
				"Enter : Teleport") == -1)
		return (-1);
	if (mlx_string_put(all->mlx, all->screen->win, 30, 105, color,
				"Move and straff : w, a, s, d") == -1)
		return (-1);
	if (mlx_string_put(all->mlx, all->screen->win, 30, 120, color,
				"P : pause/unpause") == -1)
		return (-1);
	return (1);
}

int		ft_pause(t_all *all)
{
	if (!all->pause)
	{
		all->pause = 1;
		if (ft_menu(all) == -1)
			return (-1);
	}
	else
	{
		all->pause = 0;
		ft_draw(all);
		ft_draw_player(all);
	}
	return (1);
}

int		ft_clean(t_all *all)
{
	mlx_destroy_image(all->mlx, all->img->image);
	open_image(all);
	mlx_put_image_to_window(all->mlx, all->win,
							all->img->image, 0, 0);
	return (1);
}

int		ft_close(void)
{
	exit(0);
}

int		ft_usage(void)
{
	ft_putendl("Usage : ./wolf3d <map_file>");
	exit(0);
}
