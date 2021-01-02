/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:29:12 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/02 12:44:39 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_player(t_all *all, double planeX, double planeY)
{
	all->ray.planeX = planeX;
	all->ray.planeY = planeY;
}

void	init_player(t_all *all)
{
	if (all->plr.position == 'W')
	{
		all->ray.dirX = -1;
		all->ray.dirY = 0;
		set_player(all, 0, -0.66);
	}
	else if (all->plr.position == 'E')
	{
		all->ray.dirX = 1;
		all->ray.dirY = 0;
		set_player(all, 0, 0.66);
	}
	else if (all->plr.position == 'N')
	{
		all->ray.dirX = 0;
		all->ray.dirY = -1;
		set_player(all, 0.66, 0);
	}
	else if (all->plr.position == 'S')
	{
		all->ray.dirX = 0;
		all->ray.dirY = 1;
		set_player(all, -0.66, 0);
	}
}

void	parser_player(t_all *all)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	all->plr.position = '0';
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'N' || all->map[y][x] == 'S' ||
				all->map[y][x] == 'E' || all->map[y][x] == 'W')
			{
				all->plr.position == '0' ? all->plr.position = all->map[y][x]
					: ft_error("Несколько игроков на карте");
				all->plr.x = (double)x + 0.5;
				all->plr.y = (double)y + 0.5;
				init_player(all);
			}
			x++;
		}
		y++;
	}
	all->plr.position == '0' ? ft_error("Нет игрока на карте") : 0;
}
