/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:40:52 by ksharee           #+#    #+#             */
/*   Updated: 2020/12/29 16:57:46 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	game_init(t_all *all)
{
	all->mlx.w = 1920;
	all->mlx.h = 1080;
	all->text.img_path = "./pics/redbrick.xpm";
	all->text1.img_path = "./pics/greystone.xpm";
	all->text2.img_path = "./pics/wood.xpm";
	all->text3.img_path = "./pics/bluestone.xpm";
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx, all->mlx.w, all->mlx.h, "CUB3D");
	all->text.img = mlx_xpm_file_to_image(all->mlx.mlx, all->text.img_path, &all->text.img_w, &all->text.img_h);
	all->text.addr = mlx_get_data_addr(all->text.img, &all->text.bits_per_pixel, &all->text.line_length, &all->text.endian);

	all->text1.img = mlx_xpm_file_to_image(all->mlx.mlx, all->text1.img_path, &all->text.img_w, &all->text.img_h);
	all->text1.addr = mlx_get_data_addr(all->text1.img, &all->text1.bits_per_pixel, &all->text1.line_length, &all->text1.endian);

	all->text2.img = mlx_xpm_file_to_image(all->mlx.mlx, all->text2.img_path, &all->text.img_w, &all->text.img_h);
	all->text2.addr = mlx_get_data_addr(all->text2.img, &all->text2.bits_per_pixel, &all->text2.line_length, &all->text3.endian);

	all->text3.img = mlx_xpm_file_to_image(all->mlx.mlx, all->text3.img_path, &all->text.img_w, &all->text.img_h);
	all->text3.addr = mlx_get_data_addr(all->text3.img, &all->text3.bits_per_pixel, &all->text3.line_length, &all->text3.endian);
	raycast(all);
	mlx_hook(all->mlx.win, 2, 1L<<0, ft_hook, all);
	mlx_string_put(all->mlx.mlx, all->mlx.win, 25, 75, 0xffffff, "Look Up : /\\ , Look down : \\/ , Look left : <, Look right : >");
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
				all->plr.x = (double)x + 0.5;
				all->plr.y = (double)y + 0.5;
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
	all->ray.planeY = -0.66;

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
