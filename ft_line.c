/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 09:54:36 by jyakdi            #+#    #+#             */
/*   Updated: 2017/03/25 10:52:47 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_hor2(t_point *pt1, t_point *pt2, double *precision, double x)
{
	if (pt1->x > pt2->x)
		pt1->x -= 1;
	else if (pt1->x < pt2->x)
		pt1->x += 1;
	(*precision) += x;
	if ((*precision) > 0.5)
	{
		pt1->y -= 1;
		(*precision)--;
	}
	else if ((*precision) < -0.5)
	{
		pt1->y += 1;
		(*precision)++;
	}
}

double	ft_draw_hor(t_all *all, t_point *pt1, t_point *pt2, t_point *info)
{
	double	precision;
	double	nbx;
	double	nby;
	t_point	tmp;

	nbx = pt2->x - pt1->x;
	nby = pt2->y - pt1->y;
	nbx = (nbx < 0) ? -nbx : nbx;
	info->x = nby / nbx;
	precision = 0;
	tmp.x = pt2->x;
	tmp.y = pt2->y;
	while ((int)tmp.x != (int)pt1->x)
	{
		draw_hor2(&tmp, pt1, &precision, info->x);
		if ((ft_check_wall(all->img, tmp.x, tmp.y)) <= 0)
			ft_paint(tmp.x, tmp.y, all->img, 3);
		else
		{
			*info = tmp;
			return (sqrt(pow(pt2->x - tmp.x, 2) + pow(pt2->y - tmp.y, 2)));
		}
	}
	*info = tmp;
	return (sqrt(pow(pt2->x - tmp.x, 2) + pow(pt2->y - tmp.y, 2)));
}

void	draw_ver2(t_point *pt1, t_point *pt2, double *precision, double x)
{
	if (pt1->y > pt2->y)
		pt1->y -= 1;
	else if (pt1->y < pt2->y)
		pt1->y += 1;
	(*precision) += x;
	if ((*precision) > 0.5)
	{
		pt1->x += 1;
		(*precision)--;
	}
	else if ((*precision) < -0.5)
	{
		pt1->x -= 1;
		(*precision)++;
	}
}

double	ft_draw_ver(t_all *all, t_point *pt1, t_point *pt2, t_point *info)
{
	double		precision;
	double		nbx;
	double		nby;
	t_point		tmp;

	nbx = pt1->x - pt2->x;
	nby = pt2->y - pt1->y;
	nby = (nby < 0) ? -nby : nby;
	info->x = nbx / nby;
	precision = 0;
	tmp.x = pt2->x;
	tmp.y = pt2->y;
	while ((int)tmp.y != (int)pt1->y)
	{
		draw_ver2(&tmp, pt1, &precision, info->x);
		if ((ft_check_wall(all->img, tmp.x, tmp.y)) <= 0)
			ft_paint(tmp.x, tmp.y, all->img, 3);
		else
		{
			*info = tmp;
			return (sqrt(pow(pt2->x - tmp.x, 2) + pow(pt2->y - tmp.y, 2)));
		}
	}
	*info = tmp;
	return (sqrt(pow(pt2->x - tmp.x, 2) + pow(pt2->y - tmp.y, 2)));
}

double	ft_draw_line(t_all *all, t_point *pt1, t_point *pt2, t_point *hit)
{
	double		nbx;
	double		nby;
	double		dis;
	t_point		tmp;

	nbx = pt2->x - pt1->x;
	nby = pt2->y - pt1->y;
	if (fabs(nbx) <= fabs(nby))
	{
		tmp.x = nbx / nby;
		dis = ft_draw_ver(all, pt1, pt2, &tmp);
	}
	else
	{
		tmp.x = nby / nbx;
		dis = ft_draw_hor(all, pt1, pt2, &tmp);
	}
	*hit = tmp;
	return (dis);
}
