/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:57:07 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/10 08:31:01 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map		*create_t_map(void)
{
	t_map	*map;

	if (!(map = ft_memalloc(sizeof(t_map))))
		return (0);
	map->height = 0;
	map->width = 0;
	return (map);
}

t_image		*create_t_image(void)
{
	t_image	*img;

	if (!(img = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(img->map = create_t_map()))
		return (0);
	return (img);
}

t_player	*create_t_player(void)
{
	t_player	*player;
	t_point		position;

	if (!(player = ft_memalloc(sizeof(t_player))))
		return (NULL);
	position.x = 0;
	position.y = 0;
	player->pos = position;
	player->rot = 90;
	player->range = 1800;
	player->v_angle = 30;
	player->speed = 10;
	player->i = 0;
	player->side = 1;
	player->rot_spd = 4;
	return (player);
}

t_screen	*create_t_screen(void)
{
	t_screen	*screen;

	if (!(screen = ft_memalloc(sizeof(t_screen))))
		return (0);
	return (screen);
}

t_texture	*create_texture(t_all *all, char *file)
{
	t_texture	*tex;

	if (!(tex = ft_memalloc(sizeof(t_texture))))
		return (0);
	tex->image = mlx_xpm_file_to_image(all->mlx, file,
			&(tex->width), &(tex->height));
	if (tex->image == NULL)
	{
		ft_putendl_fd("Texture Failure !", 2);
		exit(-1);
	}
	tex->array = (unsigned char *)mlx_get_data_addr(tex->image,
			&(tex->bpp), &(tex->sl), &(tex->endian));
	return (tex);
}
