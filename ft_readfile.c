/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:27:37 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/10 08:18:28 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		**ft_register_tab(char ***tabline, t_all *all)
{
	int		i;
	int		j;
	int		**tab;

	if (!(tab = ft_memalloc(sizeof(tab) * all->img->map->height)))
		return (NULL);
	j = -1;
	while (++j < all->img->map->height)
	{
		i = -1;
		if (!(tab[j] = ft_memalloc(sizeof(*tab) * all->img->map->width)))
			return (NULL);
		while (++i < all->img->map->width)
		{
			tab[j][i] = ft_atoi(tabline[j][i]);
			if (tab[j][i] == 2)
			{
				all->player->pos.x = (double)i * SIZEX /
					(double)all->img->map->width;
				all->player->pos.y = (double)j * SIZEY /
					(double)all->img->map->height;
			}
		}
	}
	return (tab);
}

char	***ft_addline(char ***tabline, char *line, int nbline)
{
	char	***new;
	int		i;

	if (!(new = ft_memalloc(sizeof(new) * nbline)))
		return (NULL);
	i = 0;
	while (i < nbline - 1)
	{
		new[i] = tabline[i];
		i++;
	}
	new[i] = ft_strsplit(line, ' ');
	i = 0;
	free(tabline);
	return (new);
}

void	ft_free_tab(t_all *all, char ***tabline)
{
	int		i;
	int		j;

	i = 0;
	while (i < all->img->map->height)
	{
		j = 0;
		while (j < all->img->map->width)
		{
			free(tabline[i][j]);
			j++;
		}
		free(tabline[i]);
		i++;
	}
	free(tabline);
}

int		ft_read(t_all *all, char *file)
{
	int		fd;
	char	*line;
	char	***tabline;

	tabline = NULL;
	if ((fd = open(file, O_RDONLY)) <= 0)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		all->img->map->height += 1;
		if (!(all->img->map->width))
			all->img->map->width = ft_getnbword_max(line, 20);
		if (all->img->map->width != ft_getnbword_max(line, 20))
			return (0);
		tabline = ft_addline(tabline, line, all->img->map->height);
		ft_strdel(&line);
	}
	if (all->img->map->height == 0 || all->img->map->width == 0)
		return (0);
	ft_strdel(&line);
	all->img->map->tab = ft_register_tab(tabline, all);
	ft_free_tab(all, tabline);
	close(fd);
	return (ft_check_map(all));
}
