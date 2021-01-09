/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:47:21 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/09 13:06:46 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	left_right(t_all *all, int i)
{
	double olddirx;
	double oldplanex;

	olddirx = all->ray.d_x;
	oldplanex = all->ray.pl_x;
	all->ray.d_x = all->ray.d_x * cos(MS * i) -
		all->ray.d_y * sin(MS * i);
	all->ray.d_y = olddirx * sin(MS * i) +
		all->ray.d_y * cos(MS * i);
	all->ray.pl_x = all->ray.pl_x * cos(MS * i) -
		all->ray.pl_y * sin(MS * i);
	all->ray.pl_y = oldplanex * sin(MS * i) +
		all->ray.pl_y * cos(MS * i);
}

void	move_up_down(t_all *all, int i)
{
	if (i == 0)
	{
		if (all->map[(int)all->plr.y][(int)(all->plr.x +
			all->ray.d_x * MS)] != '1' && all->map[(int)all->plr.y]
			[(int)(all->plr.x + all->ray.d_x * MS)] != '4')
			all->plr.x += all->ray.d_x * MS;
		if (all->map[(int)(all->plr.y + all->ray.d_y *
			MS)][(int)all->plr.x] != '1' && all->map[(int)(all->plr.y +
			all->ray.d_y * MS)][(int)all->plr.x] != '4')
			all->plr.y += all->ray.d_y * MS;
	}
	else if (i == 1)
	{
		if (all->map[(int)all->plr.y][(int)(all->plr.x -
			all->ray.d_x * MS)] != '1' && all->map[(int)all->plr.y]
			[(int)(all->plr.x - all->ray.d_x * MS)] != '4')
			all->plr.x -= all->ray.d_x * MS;
		if (all->map[(int)(all->plr.y - all->ray.d_y *
			MS)][(int)all->plr.x] != '1' && all->map[(int)(all->plr.y -
			all->ray.d_y * MS)][(int)all->plr.x] != '4')
			all->plr.y -= all->ray.d_y * MS;
	}
}

void	move_left_right(t_all *all, int i)
{
	if (i == 0)
	{
		if (all->map[(int)all->plr.y][(int)(all->plr.x -
			all->ray.pl_x * MS)] != '1' && all->map[(int)all->plr.y]
			[(int)(all->plr.x - all->ray.pl_x * MS)] != '4')
			all->plr.x -= all->ray.pl_x * MS;
		if (all->map[(int)(all->plr.y - all->ray.pl_y *
			MS)][(int)all->plr.x] != '1' && all->map[(int)(all->plr.y
			- all->ray.pl_y * MS)][(int)all->plr.x] != '4')
			all->plr.y -= all->ray.pl_y * MS;
	}
	else if (i == 1)
	{
		if (all->map[(int)all->plr.y][(int)(all->plr.x +
			all->ray.pl_x * MS)] != '1' && all->map[(int)all->plr.y]
			[(int)(all->plr.x + all->ray.pl_x * MS)] != '4')
			all->plr.x += all->ray.pl_x * MS;
		if (all->map[(int)(all->plr.y + all->ray.pl_y *
			MS)][(int)all->plr.x] != '1' && all->map[(int)(all->plr.y
			+ all->ray.pl_y * MS)][(int)all->plr.x] != '4')
			all->plr.y += all->ray.pl_y * MS;
	}
}

void	ft_hook_next(int keycode, t_all *all)
{
	if (keycode == 65362)
	{
		all->ray.pitch += 400 * MS;
		all->ray.pitch > 200 ? all->ray.pitch = 200 : 0;
	}
	else if (keycode == 65364)
	{
		all->ray.pitch -= 400 * MS;
		all->ray.pitch < -200 ? all->ray.pitch = -200 : 0;
	}
	else if (keycode == 65507)
	{
		all->blast = 1;
		raycast(all);
		all->blast = 0;
	}
}

int		ft_hook(int keycode, t_all *all)
{
	if (keycode == 65307)
	{
		free_struct(all);
		free_map(all);
		exit(0);
	}
	if (all->death == false)
	{
		ft_hook_next(keycode, all);
		if (keycode == 97)
			move_left_right(all, 0);
		else if (keycode == 100)
			move_left_right(all, 1);
		else if (keycode == 119)
			move_up_down(all, 0);
		else if (keycode == 115)
			move_up_down(all, 1);
		else if (keycode == 65361)
			left_right(all, -1);
		else if (keycode == 65363)
			left_right(all, 1);
		raycast(all);
	}
	return (0);
}
