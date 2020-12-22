/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:34:13 by ksharee           #+#    #+#             */
/*   Updated: 2020/12/22 16:06:38 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/cub3d.h"

void	game_init(t_all *all)
{
	all->mlx.w = 1920;
	all->mlx.h = 1080;
	all->text.img_path = "./pics/redbrick.xpm";
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx, all->mlx.w, all->mlx.h, "CUB3D");
	all->text.img = mlx_xpm_file_to_image(all->mlx.mlx, all->text.img_path, &all->text.img_w, &all->text.img_h);
	all->text.addr = mlx_get_data_addr(all->text.img, &all->text.bits_per_pixel, &all->text.line_length, &all->text.endian);
	raycast(all);
	mlx_hook(all->mlx.win, 2, 1L<<0, ft_hook, all);
	mlx_loop(all->mlx.mlx);
}

void	parser_plr(t_all *all)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'N')
			{
				all->plr.x = x;
				all->plr.y = y;
			}
			x++;
		}
		y++;
	}
}

void	struct_init(t_all *all)
{
	all->ray.dirX = -1;
	all->ray.dirY = 0;
	all->ray.planeX = 0;
	all->ray.planeY = 0.76;

	all->text.texWidth = 64;
	all->text.texHeight = 64;
}

int main(int agrc, char **agrv)
{
	(void)agrc;
	(void)agrv;
	int 	fd;
	t_all	all;

	fd = open("test.cub", O_RDONLY);
	parser_file(fd, &all);
	close(fd);
	struct_init(&all);
	parser_plr(&all);
	texture(&all);
	game_init(&all);
	return 0;
}
