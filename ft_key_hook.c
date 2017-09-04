/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 08:47:19 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/10 08:24:58 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_rotate(int keycode, t_all *all)
{
	if (keycode == KEY_LEFT)
		all->player->rot += all->player->rot_spd;
	if (keycode == KEY_RIGHT)
		all->player->rot -= all->player->rot_spd;
	all->player->rot %= 360;
	ft_draw(all);
	ft_draw_player(all);
}

void	ft_move(int keycode, t_all *all)
{
	t_point		position;

	if (keycode == KEY_UP || keycode == KEY_W)
	{
		position.x = all->player->pos.x +
			(cos((double)all->player->rot / 180 * PI) * all->player->speed);
		position.y = all->player->pos.y -
			(sin((double)all->player->rot / 180 * PI) * all->player->speed);
		if ((ft_check_wall(all->img, position.x, position.y)) <= 0)
			all->player->pos = position;
	}
	if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		position.x = all->player->pos.x -
			(cos((double)all->player->rot / 180 * PI) * all->player->speed / 2);
		position.y = all->player->pos.y +
			(sin((double)all->player->rot / 180 * PI) * all->player->speed / 2);
		if ((ft_check_wall(all->img, position.x, position.y)) <= 0)
			all->player->pos = position;
	}
	ft_draw(all);
	ft_draw_player(all);
}

void	ft_strafe(int keycode, t_all *all)
{
	t_point		position;

	if (keycode == KEY_A)
	{
		position.x = all->player->pos.x + (cos((double)(all->player->rot + 90)
					/ 180 * PI) * all->player->speed / 2);
		position.y = all->player->pos.y - (sin((double)(all->player->rot + 90)
					/ 180 * PI) * all->player->speed / 2);
		if ((ft_check_wall(all->img, position.x, position.y)) <= 0)
			all->player->pos = position;
	}
	if (keycode == KEY_D)
	{
		position.x = all->player->pos.x + (cos((double)(all->player->rot - 90)
					/ 180 * PI) * all->player->speed / 2);
		position.y = all->player->pos.y - (sin((double)(all->player->rot - 90)
					/ 180 * PI) * all->player->speed / 2);
		if ((ft_check_wall(all->img, position.x, position.y)) <= 0)
			all->player->pos = position;
	}
	ft_draw(all);
	ft_draw_player(all);
}

void	ft_tp(t_all *all)
{
	double			i;
	double			j;
	int				ok;

	j = 0;
	i = 0;
	ok = ft_check_wall(all->img, all->player->pos.x, all->player->pos.y);
	if (ok)
	{
		if (ok == -1)
			ok = -2;
		else if (ok == -2)
			ok = -1;
		while ((int)j < SIZEY && ft_check_wall(all->img, i, j) != ok)
		{
			i = 0;
			while ((int)i < SIZEX && ft_check_wall(all->img, i, j) != ok)
				i++;
			j++;
		}
		all->player->pos.x = i;
		all->player->pos.y = j;
		ft_draw(all);
		ft_draw_player(all);
	}
}

int		ft_key_hook(int keycode, t_all *all)
{
	if (!all->pause)
	{
		if (keycode == KEY_UP || keycode == KEY_DOWN ||
		keycode == KEY_W || keycode == KEY_S)
			ft_move(keycode, all);
		if (keycode == KEY_D || keycode == KEY_A)
			ft_strafe(keycode, all);
		if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
			ft_rotate(keycode, all);
		if (keycode == KEY_ENTER)
			ft_tp(all);
	}
	if (keycode == KEY_P)
		if (ft_pause(all) == -1)
			ft_close();
	if (keycode == KEY_ESC)
		ft_close();
	return (1);
}
