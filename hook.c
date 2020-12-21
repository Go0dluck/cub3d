/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:47:21 by ksharee           #+#    #+#             */
/*   Updated: 2020/12/21 08:40:58 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_hook(int keycode, t_all *all)
{
	if (keycode == 53)
		exit(0);
	//printf("%f %f\n", all->plr.x, all->plr.y);
	if (keycode == 126)
	{
		if (all->map[(int)all->plr.y][(int)(all->plr.x + all->ray.dirX * moveSpeed)] != '1')
			all->plr.x += all->ray.dirX * moveSpeed;
		if (all->map[(int)(all->plr.y + all->ray.dirY * moveSpeed)][(int)all->plr.x] != '1')
			all->plr.y += all->ray.dirY * moveSpeed;
	}
	if (keycode == 125)
	{
		if (all->map[(int)all->plr.y][(int)(all->plr.x - all->ray.dirX * moveSpeed)] != '1')
			all->plr.x -= all->ray.dirX * moveSpeed;
		if (all->map[(int)(all->plr.y - all->ray.dirY * moveSpeed)][(int)all->plr.x] != '1')
			all->plr.y -= all->ray.dirY * moveSpeed;
	}
	if (keycode == 124)
	{
		double oldDirX = all->ray.dirX;
		double oldPlaneX = all->ray.planeX;
		all->ray.dirX = all->ray.dirX * cos(-moveSpeed) - all->ray.dirY * sin(-moveSpeed);
		all->ray.dirY = oldDirX * sin(-moveSpeed) + all->ray.dirY * cos(-moveSpeed);
		all->ray.planeX = all->ray.planeX * cos(-moveSpeed) - all->ray.planeY * sin(-moveSpeed);
		all->ray.planeY = oldPlaneX * sin(-moveSpeed) + all->ray.planeY * cos(-moveSpeed);
	}
	if (keycode == 123)
	{
		double oldDirX = all->ray.dirX;
		double oldPlaneX = all->ray.planeX;
		all->ray.dirX = all->ray.dirX * cos(moveSpeed) - all->ray.dirY * sin(moveSpeed);
		all->ray.dirY = oldDirX * sin(moveSpeed) + all->ray.dirY * cos(moveSpeed);
		all->ray.planeX = all->ray.planeX * cos(moveSpeed) - all->ray.planeY * sin(moveSpeed);
		all->ray.planeY = oldPlaneX * sin(moveSpeed) + all->ray.planeY * cos(moveSpeed);
	}
	raycast(all);
	return (0);
}
