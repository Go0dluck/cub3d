/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:34:13 by ksharee           #+#    #+#             */
/*   Updated: 2020/12/21 08:25:09 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	game_init(t_all *all)
{

	all->mlx.w = 640;
	all->mlx.h = 480;
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx, all->mlx.w, all->mlx.h, "CUB3D");
	raycast(all);
	mlx_hook(all->mlx.win, 2, 0, ft_hook, all);
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
	all->ray.planeY = 0.66;
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
	game_init(&all);
	return 0;
}
