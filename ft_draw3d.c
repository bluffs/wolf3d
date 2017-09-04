/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:06:14 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/10 09:46:56 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_draw_sky(t_all *all, int nb, int x)
{
	t_point		skyratio;

	skyratio.x = (double)all->tex[0]->width / BIGX;
	skyratio.y = (double)all->tex[0]->height / BIGY;
	all->screen->array[(BIGY / 2 - nb) * all->screen->sl + x *
		all->screen->bpp / 8 + 0] = all->tex[0]->array[(int)((BIGY / 2 - nb) *
		all->tex[0]->sl) + (int)(x * skyratio.x) * all->tex[0]->bpp / 8 + 0];
	all->screen->array[(BIGY / 2 - nb) * all->screen->sl + x *
		all->screen->bpp / 8 + 1] = all->tex[0]->array[(int)((BIGY / 2 - nb) *
		all->tex[0]->sl) + (int)(x * skyratio.x) * all->tex[0]->bpp / 8 + 1];
	all->screen->array[(BIGY / 2 - nb) * all->screen->sl + x *
		all->screen->bpp / 8 + 2] = all->tex[0]->array[(int)((BIGY / 2 - nb) *
		all->tex[0]->sl) + (int)(x * skyratio.x) * all->tex[0]->bpp / 8 + 2];
}

void	ft_draw_walls_down(t_all *all, int nb, int x, t_point wallratio)
{
	if (BIGY / 2 + nb < BIGY)
	{
		all->screen->array[(BIGY / 2 + nb) * all->screen->sl + x *
			all->screen->bpp / 8 + 0] = all->tex[1]->array[(int)
			((all->tex[1]->height / 2 - (int)(wallratio.y * (double)nb)) *
			all->tex[1]->sl) + (int)(wallratio.x) * all->tex[1]->bpp / 8 + 0];
		all->screen->array[(BIGY / 2 + nb) * all->screen->sl + x *
			all->screen->bpp / 8 + 1] = all->tex[1]->array[(int)
			((all->tex[1]->height / 2 - (int)(wallratio.y * (double)nb)) *
			all->tex[1]->sl) + (int)(wallratio.x) * all->tex[1]->bpp / 8 + 1];
		all->screen->array[(BIGY / 2 + nb) * all->screen->sl + x *
			all->screen->bpp / 8 + 2] = all->tex[1]->array[(int)
			((all->tex[1]->height / 2 - (int)(wallratio.y * (double)nb)) *
			all->tex[1]->sl) + (int)(wallratio.x) * all->tex[1]->bpp / 8 + 2];
	}
}

void	ft_draw_walls_up(t_all *all, int nb, int x, t_point wallratio)
{
	all->screen->array[(BIGY / 2 - nb) * all->screen->sl + x *
		all->screen->bpp / 8 + 0] = all->tex[1]->array[(int)
		((all->tex[1]->height / 2 - (int)(wallratio.y * (double)nb)) *
		all->tex[1]->sl) + (int)(wallratio.x) * all->tex[1]->bpp / 8 + 0];
	all->screen->array[(BIGY / 2 - nb) * all->screen->sl + x *
		all->screen->bpp / 8 + 1] = all->tex[1]->array[(int)
		((all->tex[1]->height / 2 - (int)(wallratio.y * (double)nb)) *
		all->tex[1]->sl) + (int)(wallratio.x) * all->tex[1]->bpp / 8 + 1];
	all->screen->array[(BIGY / 2 - nb) * all->screen->sl + x *
		all->screen->bpp / 8 + 2] = all->tex[1]->array[(int)
		((all->tex[1]->height / 2 - (int)(wallratio.y * (double)nb)) *
		all->tex[1]->sl) + (int)(wallratio.x) * all->tex[1]->bpp / 8 + 2];
}

void	ft_draw_gun(t_all *all)
{
	int		x;
	int		y;

	all->player->i += all->player->side;
	if (all->player->i >= 5 || all->player->i <= 0)
		all->player->side *= -1;
	x = (BIGX - all->tex[3]->width) / 2;
	y = BIGY - all->tex[3]->height;
	mlx_put_image_to_window(all->mlx, all->screen->win, all->tex[3]->image,
			x + all->player->i, y);
}

int		ft_draw3d(t_all *all, int x, double distance, t_point *hit)
{
	int			nb;
	t_point		wallratio;

	nb = -1;
	distance = 64 / distance * 277 * 0.8;
	wallratio.x = (double)(((int)hit->x + (int)hit->y) % 64 *
			all->tex[1]->width / 64);
	wallratio.y = (double)all->tex[1]->height / (double)(distance * 2);
	while ((int)distance > 0 && ++nb <= BIGY / 2)
	{
		ft_draw_walls_up(all, nb, x, wallratio);
		ft_draw_walls_down(all, nb, x, wallratio);
		distance--;
	}
	while (nb <= BIGY / 2)
	{
		ft_draw_sky(all, nb, x);
		if (BIGY / 2 + nb < BIGY)
			all->screen->array[(BIGY / 2 + nb) * all->screen->sl +
				x * all->screen->bpp / 8 + 1] = 150;
		nb++;
	}
	return (1);
}
