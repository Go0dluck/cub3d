/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:34:17 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 12:46:07 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# define MS 0.2
# define BUFFER_SIZE 1000
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <math.h>
# include <unistd.h>
# include "../libft/libft.h"
//# include "../minilibx/mlx.h"
# include "../libmlx/mlx.h"

typedef struct		s_bmp
{
	int				file_size;
	int				unused;
	int				offset;
	int				header;
	int				plane;
	int				bpp;
}					t_bmp;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			spr_dist;
}					t_sprite;

typedef struct		s_color
{
	int				kol;
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_sprite_set
{
	double			spx;
	double			spy;
	double			invdet;
	double			trfx;
	double			trfy;
	int				spscrx;
	int				sp_h;
	int				dr_sy;
	int				dr_ey;
	int				sp_w;
	int				dr_sx;
	int				dr_ex;
	int				stripe;
	int				t_x;
	int				d;
	int				t_y;
	int				s_w;
	int				s_h;
}					t_sprite_set;

typedef struct		s_text_set
{
	int				t_w;
	int				t_h;
	int				t_x;
	int				t_y;
	double			step;
	double			t_p;
	unsigned int	color;
	double			wallx;
}					t_text_set;

typedef struct		s_text
{
	void			*img;
	int				img_w;
	int				img_h;
	void			*addr;
	char			*path;
	int				line_length;
	int				bpp;
	int				endian;
}					t_text;

typedef struct		s_ray
{
	double			d_x;
	double			d_y;
	double			p_x;
	double			p_y;
	double			pl_x;
	double			pl_y;
	double			c_x;
	double			r_dx;
	double			r_dy;
	double			d_dx;
	double			d_dy;
	double			s_dx;
	double			s_dy;
	double			w_dist;
	double			*z_buf;
	int				m_x;
	int				m_y;
	int				s_x;
	int				s_y;
	int				hit;
	int				side;
	int				l_h;
	int				d_s;
	int				d_e;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
	int				w;
	int				h;
}					t_mlx;

typedef struct		s_plr
{
	char			position;
	double			x;
	double			y;
}					t_plr;

typedef struct		s_all
{
	char			**map;
	int				size_map;
	int				save;
	int				size_param;
	int				size_sprite;
	t_plr			plr;
	t_mlx			mlx;
	t_ray			ray;
	t_text_set		t_s;
	t_text			t_no;
	t_text			t_so;
	t_text			t_we;
	t_text			t_ea;
	t_text			t_spr;
	t_text			t_spr2;
	t_sprite		*sprs;
	t_sprite_set	spr_s;
	t_color			col_f;
	t_color			col_c;
	t_bmp			bmp;
}					t_all;

void				parser_file_map(int fd, t_all *all);
int					get_next_line(int fd, char **line);
void				ft_error(char *str, t_all *all);
void				raycast(t_all *all);
int					ft_hook(int keycode, t_all *all);
void				ft_putpixel(t_all *all, int x, int y, int color);
void				texture(t_all *all);
void				free_split(char **str);
int					ft_split_size(char **str);
void				free_struct(t_all *all);
void				free_map(t_all *all);
int					create_rgb_f(t_all *all);
int					create_rgb_c(t_all *all);
void				draw_sprites(t_all *all);
void				save_screen(t_all *all);
void				draw_vertical_sprite(t_all *all, t_sprite sprite);
void				sort_sprites(t_all *all);
void				check_line_map(char *str_map, t_all *all);
void				set_text_sprite(t_all *all, char *path);
void				set_text_sprite_two(t_all *all, char *path);
void				texture_seting(t_all *all);
void				verline(int x, t_all *all);
int					ft_isnum(char *str);
int					ft_isnum_comma(char *str);

void				parser_file(int fd, t_all *all);
void				pars_resolution(char **str, t_all *all);
void				pars_floor(char **str, t_all *all);
void				pars_texture_path(char **str, t_all *all);
void				pars_ceilling(char **str, t_all *all);
void				parser_player(t_all *all);
void				parser_sprites(t_all *all);

#endif
