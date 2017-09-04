/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:58:13 by jyakdi            #+#    #+#             */
/*   Updated: 2017/03/30 13:44:51 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			ft_check_wall(t_image *img, double x, double y)
{
	if (x < 0 || x >= SIZEX || y < 0 || y >= SIZEY)
		return (2);
	if (img->array[(int)y * img->sl + (int)x * img->bpp / 8 + 0] == 255 &&
		img->array[(int)y * img->sl + (int)x * img->bpp / 8 + 1] == 255 &&
		img->array[(int)y * img->sl + (int)x * img->bpp / 8 + 2] == 255)
		return (1);
	if (img->array[(int)y * img->sl + (int)x * img->bpp / 8 + 1] == 254)
		return (-1);
	if (img->array[(int)y * img->sl + (int)x * img->bpp / 8 + 1] == 253)
		return (-2);
	return (0);
}

t_point		ft_nextpoint(t_all *all, double i)
{
	t_point		pt;

	pt.x = (int)(cos((double)(all->player->rot + i) / 180 * PI) *
			(double)all->player->range) + all->player->pos.x;
	pt.y = (int)(-sin((double)(all->player->rot + i) / 180 * PI) *
			(double)all->player->range) + all->player->pos.y;
	return (pt);
}

void		ft_vision(t_all *all, t_point hit)
{
	t_point	pt;
	double	i;
	int		x;
	double	distance;

	i = 0;
	x = 0;
	i += (double)all->player->v_angle / BIGX;
	while ((int)i < all->player->v_angle)
	{
		pt = ft_nextpoint(all, i);
		distance = ft_draw_line(all, &pt, &all->player->pos, &hit);
		ft_draw3d(all, BIGX / 2 - x, distance * fabs(cos(i * PI / 180)), &hit);
		pt = ft_nextpoint(all, -i);
		distance = ft_draw_line(all, &pt, &all->player->pos, &hit);
		if (x < BIGX / 2)
			ft_draw3d(all, BIGX / 2 + x, distance *
					fabs(cos(i * PI / 180)), &hit);
		i = (double)all->player->v_angle / BIGX * x * 2;
		x++;
	}
}

int			ft_draw_vision(t_all *all)
{
	t_point	pt;
	t_point	hit;

	hit.x = 0;
	hit.y = 0;
	pt.x = (int)(cos((double)all->player->rot / 180 * PI) *
			(double)all->player->range) + all->player->pos.x;
	pt.y = (int)(-sin((double)all->player->rot / 180 * PI) *
			(double)all->player->range) + all->player->pos.y;
	ft_vision(all, hit);
	return (-1);
}
