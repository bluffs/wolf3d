/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 13:53:14 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/10 09:45:00 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_texture_pack(t_all *all)
{
	int			i;
	char		**list;
	t_texture	**tex;

	if (!(list = ft_memalloc(sizeof(list) * 4)))
		return (0);
	i = -1;
	list[0] = ft_strdup("textures/ciel.xpm");
	list[1] = ft_strdup("textures/wall.xpm");
	list[2] = ft_strdup("textures/floor.xpm");
	list[3] = ft_strdup("textures/shotgun.xpm");
	if (!(tex = ft_memalloc(sizeof(t_texture *) * 4)))
		return (0);
	while (++i < 4)
		tex[i] = create_texture(all, list[i]);
	i = 0;
	while (i < 4)
	{
		ft_strdel(&list[i]);
		i++;
	}
	free(list);
	all->tex = tex;
	return (1);
}

t_all	*create_t_all(void)
{
	t_all		*all;
	t_image		*img;
	t_player	*player;
	t_screen	*screen;

	if (!(all = ft_memalloc(sizeof(t_all))))
		return (NULL);
	if (!(img = create_t_image()))
		return (NULL);
	if (!(player = create_t_player()))
		return (NULL);
	if (!(screen = create_t_screen()))
		return (NULL);
	all->player = player;
	all->img = img;
	all->screen = screen;
	all->pause = 0;
	return (all);
}

void	ft_get_info_sqr(t_image *img)
{
	img->sqr_width = SIZEX / img->map->width;
	img->sqr_height = SIZEY / img->map->height;
}

void	open_image(t_all *all)
{
	all->img->image = mlx_new_image(all->mlx, SIZEX, SIZEY);
	all->img->array = (unsigned char *)mlx_get_data_addr(all->img->image,
			&(all->img->bpp), &(all->img->sl), &(all->img->endian));
}

void	open_screen(t_all *all)
{
	all->screen->image = mlx_new_image(all->mlx, BIGX, BIGY);
	all->screen->array = (unsigned char *)mlx_get_data_addr(all->screen->image,
			&(all->screen->bpp), &(all->screen->sl), &(all->screen->endian));
}
