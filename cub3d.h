/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:34:17 by ksharee           #+#    #+#             */
/*   Updated: 2020/12/21 13:04:32 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H
# define moveSpeed 0.2
# define BUFFER_SIZE 1000
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

typedef struct	s_text
{
	int			texWidth;
	int			texHeight;
	int			texX;
	int			texY;
	double		step;
	double		texPos;
	char		texNum;
	double		wallX;
	unsigned int	**texture;
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
	double	x;
	double	y;
}				t_plr;

typedef struct	s_all
{
	char 	**map;
	t_plr	plr;
	t_mlx	mlx;
	t_ray	ray;
	t_text	text;
}				t_all;

void 	parser_file(int fd, t_all *all);
int		get_next_line(int fd, char **line);
void	raycast(t_all *all);
int		ft_hook(int keycode, t_all *all);
void	ft_putpixel(t_all *all, int x, int y, int color);
void	texture(t_all *all);

#endif
