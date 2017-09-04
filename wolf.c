/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:13:57 by jyakdi            #+#    #+#             */
/*   Updated: 2017/08/16 11:33:12 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int argc, char **argv)
{
	t_all	*all;

	if (argc != 2)
		ft_usage();
	if (!(all = create_t_all()))
		return (0);
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, SIZEX, SIZEY, "MiniMap");
	all->screen->win = mlx_new_window(all->mlx, BIGX, BIGY, "Wolf3d");
	if (!(ft_texture_pack(all)))
		return (0);
	if (!(ft_read(all, argv[1])))
	{
		ft_putendl_fd("Bad Map", 2);
		return (0);
	}
	ft_get_info_sqr(all->img);
	open_image(all);
	open_screen(all);
	ft_draw(all);
	ft_draw_player(all);
	mlx_hook(all->screen->win, 2, 0, ft_key_hook, all);
	mlx_hook(all->screen->win, 17, (1L << 17), ft_close, all);
	mlx_loop(all->mlx);
	return (0);
}
