/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:29:12 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/08 19:20:27 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	set_player(t_all *all, double planex, double planey)
{
	all->ray.pl_x = planex;
	all->ray.pl_y = planey;
}

void	init_player(t_all *all)
{
	if (all->plr.position == 'W')
	{
		all->ray.d_x = -1;
		all->ray.d_y = 0;
		set_player(all, 0, -0.66);
	}
	else if (all->plr.position == 'E')
	{
		all->ray.d_x = 1;
		all->ray.d_y = 0;
		set_player(all, 0, 0.66);
	}
	else if (all->plr.position == 'N')
	{
		all->ray.d_x = 0;
		all->ray.d_y = -1;
		set_player(all, 0.66, 0);
	}
	else if (all->plr.position == 'S')
	{
		all->ray.d_x = 0;
		all->ray.d_y = 1;
		set_player(all, -0.66, 0);
	}
}

void	parser_player(t_all *all)
{
	int		x;
	int		y;

	y = -1;
	all->plr.position = '0';
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			if (all->map[y][x] == 'N' || all->map[y][x] == 'S' ||
				all->map[y][x] == 'E' || all->map[y][x] == 'W')
			{
				all->plr.position == '0' ? all->plr.position = all->map[y][x]
					: ft_error("Несколько игроков на карте", all);
				all->plr.x = (double)x + 0.5;
				all->plr.y = (double)y + 0.5;
				init_player(all);
			}
			all->map[y][x] == '2' || all->map[y][x] == '3' ||
				all->map[y][x] == '4' ?
			all->size_sprite++ : 0;
		}
	}
	all->plr.position == '0' ? ft_error("Нет игрока на карте", all) : 0;
}
