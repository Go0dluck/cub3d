/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:34:17 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/04 00:06:39 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H
# define moveSpeed 0.2
# define BUFFER_SIZE 1000
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include "../libft/libft.h"
//# include "../minilibx/mlx.h"
# include "../libmlx/mlx.h"

typedef struct	s_sprite
{
	double			x;
	double			y;
	struct s_sprite	*next;
}				t_sprite;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;


typedef struct	s_text_set
{
	int			texWidth;
	int			texHeight;
	int			texX;
	int			texY;
	double		step;
	double		texPos;
	//char		texNum;
	double		wallX;
}				t_text_set;

typedef struct	s_text
{
	void		*img;
	int			img_w;
	int			img_h;
	void		*addr;
	char		*img_path;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
}				t_text;

typedef struct	s_ray
{
	double	dirX;
	double	dirY;
	double	posX;
	double	posY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	double	sideDistX;
	double	sideDistY;
	double	perpWallDist;
	double	*zBuffer;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
}				t_ray;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
	int		w;
	int		h;
}				t_mlx;

typedef struct	s_plr
{
	char	position;
	double	x;
	double	y;
}				t_plr;

typedef struct	s_all
{
	char 	**map;
	int		size_map;
	int		size_param;
	t_plr	plr;
	t_mlx	mlx;
	t_ray	ray;
	t_text_set text_set;
	t_text	text_no;
	t_text	text_so;
	t_text	text_we;
	t_text	text_ea;
	t_text	sprite;
	t_sprite *sprites;
	t_color col_f;
	t_color col_c;
}				t_all;

void 	parser_file_map(int fd, t_all *all);
void	ft_error(char *str);
int		get_next_line(int fd, char **line);
void	raycast(t_all *all);
int		ft_hook(int keycode, t_all *all);
void	ft_putpixel(t_all *all, int x, int y, int color);
void	texture(t_all *all);
void	free_split(char **str);
int		ft_split_size(char **str);
void	free_struct(t_all *all);
void	free_map(t_all *all);
int		create_rgb_f(t_all *all);
int		create_rgb_c(t_all *all);
void	ft_spritenew(t_all *all);

//PARSER
void	parser_file(int fd, t_all *all);
void	pars_resolution(char **str, t_all *all);
void	pars_floor(char **str, t_all *all);
void	pars_texture_path(char **str, t_all *all);
void	pars_ceilling(char **str, t_all *all);
void	parser_player(t_all *all);

#endif
