/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:47:21 by ksharee           #+#    #+#             */
/*   Updated: 2020/12/29 15:47:27 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		ft_hook(int keycode, t_all *all)
{
	//printf("%d\n", keycode);
	if (keycode == 12)
		all->ray.planeX += 0.1;
	if (keycode == 13)
		all->ray.planeX -= 0.1;
	if (keycode == 0)
		all->ray.planeY += 0.1;
	if (keycode == 1)
		all->ray.planeY -= 0.1;
	//if (keycode == 65307)
	if (keycode == 53)
		exit(0);
	//if (keycode == 65362)
	if (keycode == 126)
	{
		if (all->map[(int)all->plr.y][(int)(all->plr.x + all->ray.dirX * moveSpeed)] != '1')
			all->plr.x += all->ray.dirX * moveSpeed;
		if (all->map[(int)(all->plr.y + all->ray.dirY * moveSpeed)][(int)all->plr.x] != '1')
			all->plr.y += all->ray.dirY * moveSpeed;
	}
	//if (keycode == 65364)
	if (keycode == 125)
	{
		if (all->map[(int)all->plr.y][(int)(all->plr.x - all->ray.dirX * moveSpeed)] != '1')
			all->plr.x -= all->ray.dirX * moveSpeed;
		if (all->map[(int)(all->plr.y - all->ray.dirY * moveSpeed)][(int)all->plr.x] != '1')
			all->plr.y -= all->ray.dirY * moveSpeed;
	}
	//if (keycode == 65361)
	if (keycode == 123)
	{
		double oldDirX = all->ray.dirX;
		double oldPlaneX = all->ray.planeX;
		all->ray.dirX = all->ray.dirX * cos(-moveSpeed) - all->ray.dirY * sin(-moveSpeed);
		all->ray.dirY = oldDirX * sin(-moveSpeed) + all->ray.dirY * cos(-moveSpeed);
		all->ray.planeX = all->ray.planeX * cos(-moveSpeed) - all->ray.planeY * sin(-moveSpeed);
		all->ray.planeY = oldPlaneX * sin(-moveSpeed) + all->ray.planeY * cos(-moveSpeed);
	}
	//if (keycode == 65363)
	if (keycode == 124)
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
