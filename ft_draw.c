/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 08:06:33 by jyakdi            #+#    #+#             */
/*   Updated: 2017/04/30 10:41:36 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_paint2(int x, int y, t_image *img, char c)
{
	if (c == 4)
	{
		img->array[y * img->sl + x * img->bpp / 8 + 0] = 0;
		img->array[y * img->sl + x * img->bpp / 8 + 1] = 254;
		img->array[y * img->sl + x * img->bpp / 8 + 2] = 0;
	}
	if (c == 5)
	{
		img->array[y * img->sl + x * img->bpp / 8 + 0] = 0;
		img->array[y * img->sl + x * img->bpp / 8 + 1] = 253;
		img->array[y * img->sl + x * img->bpp / 8 + 2] = 0;
	}
	return (1);
}

int		ft_paint(int x, int y, t_image *img, char c)
{
	if (x >= 0 && x < SIZEX && y >= 0 && y < SIZEY)
	{
		if (c == 1)
		{
			img->array[y * img->sl + x * img->bpp / 8 + 0] = 255;
			img->array[y * img->sl + x * img->bpp / 8 + 1] = 255;
			img->array[y * img->sl + x * img->bpp / 8 + 2] = 255;
		}
		else if (c == 2)
			img->array[y * img->sl + x * img->bpp / 8 + 0] = 255;
		else if (c == 3)
		{
			if (img->array[y * img->sl + x * img->bpp / 8 + 1] != 253 &&
				img->array[y * img->sl + x * img->bpp / 8 + 1] != 254)
			{
				img->array[y * img->sl + x * img->bpp / 8 + 0] = 0;
				img->array[y * img->sl + x * img->bpp / 8 + 1] = 0;
				img->array[y * img->sl + x * img->bpp / 8 + 2] = 255;
			}
		}
		else
			ft_paint2(x, y, img, c);
	}
	return (1);
}

int		ft_draw_sqr(int x, int y, t_image *img, int nb)
{
	int		i;
	int		j;

	j = 0;
	while (j < img->sqr_height)
	{
		i = 0;
		while (i < img->sqr_width)
		{
			ft_paint(x * img->sqr_width + i, y * img->sqr_height + j, img, nb);
			i++;
		}
		j++;
	}
	return (1);
}

int		ft_draw_player(t_all *all)
{
	int		i;
	int		j;

	j = -3;
	while (j < 3)
	{
		i = -3;
		while (i < 3)
		{
			ft_paint(all->player->pos.x + i,
					all->player->pos.y + j, all->img, 2);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img->image, 0, 0);
	return (1);
}

int		ft_draw(t_all *all)
{
	int		i;
	int		j;
	int		nb;

	mlx_destroy_image(all->mlx, all->img->image);
	mlx_destroy_image(all->mlx, all->screen->image);
	open_image(all);
	open_screen(all);
	j = -1;
	while (++j < all->img->map->height)
	{
		i = -1;
		while (++i < all->img->map->width)
		{
			nb = all->img->map->tab[j][i];
			if (nb == 1 || nb == 4 || nb == 5)
				ft_draw_sqr(i, j, all->img, nb);
		}
	}
	ft_draw_vision(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img->image, 0, 0);
	mlx_put_image_to_window(all->mlx, all->screen->win,
							all->screen->image, 0, 0);
	ft_draw_gun(all);
	return (1);
}
