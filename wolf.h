/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:14:28 by jyakdi            #+#    #+#             */
/*   Updated: 2017/05/10 09:41:52 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF_H
# define __WOLF_H
# include "libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define PI 3.14159265
# define SIZEX 800
# define SIZEY 600
# define BIGX 1200
# define BIGY 800
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_D 2
# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_ENTER 36
# define KEY_P 35

typedef struct		s_point
{
	double	x;
	double	y;
}					t_point;

typedef struct		s_player
{
	t_point	pos;
	int		rot;
	int		range;
	int		speed;
	int		i;
	int		side;
	double	v_angle;
	int		rot_spd;
}					t_player;

typedef struct		s_map
{
	int		**tab;
	int		height;
	int		width;
}					t_map;

typedef struct		s_image
{
	void			*image;
	unsigned char	*array;
	int				bpp;
	int				sl;
	int				endian;
	t_map			*map;
	int				sqr_height;
	int				sqr_width;
}					t_image;

typedef struct		s_screen
{
	void			*win;
	void			*image;
	unsigned char	*array;
	int				bpp;
	int				sl;
	int				endian;
}					t_screen;

typedef struct		s_texture
{
	void			*image;
	unsigned char	*array;
	int				bpp;
	int				sl;
	int				endian;
	int				width;
	int				height;
}					t_texture;

typedef struct		s_all
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_screen	*screen;
	t_player	*player;
	t_texture	**tex;
	int			pause;
}					t_all;

t_all				*create_t_all(void);
t_map				*create_t_map(void);
t_image				*create_t_image(void);
t_player			*create_t_player(void);
t_screen			*create_t_screen(void);
void				open_image(t_all *all);
void				open_screen(t_all *all);
int					ft_read(t_all *all, char *file);
int					ft_check_map(t_all *all);
t_map				*ft_get_map(void);
void				ft_get_info_sqr(t_image *img);
int					ft_texture_pack(t_all *all);
t_texture			*create_texture(t_all *all, char *file);
int					ft_clean(t_all *all);
int					ft_pause(t_all *all);
int					ft_draw(t_all *all);
double				ft_draw_line(t_all *all, t_point *pt1,
								t_point *pt2, t_point *hit);
int					ft_draw_vision(t_all *all);
int					ft_draw_player(t_all *all);
int					ft_draw3d(t_all *all, int x, double distance, t_point *hit);
void				ft_draw_gun(t_all *all);
int					ft_paint(int x, int y, t_image *img, char c);
int					ft_check_wall(t_image *img, double x, double y);
int					ft_key_hook(int keycode, t_all *all);
int					ft_usage(void);
int					ft_close(void);

#endif
