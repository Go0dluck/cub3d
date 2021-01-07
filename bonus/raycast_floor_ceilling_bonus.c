/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_floor_ceilling_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:43:01 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 22:10:44 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	raycast_floor_ceilling(t_all *all)
{
	for (int y = 0; y < all->mlx.h; y++)
	{
		float rayDirX0 = all->ray.d_x - all->ray.pl_x;
		float rayDirY0 = all->ray.d_y - all->ray.pl_y;
		float rayDirX1 = all->ray.d_x + all->ray.pl_x;
		float rayDirY1 = all->ray.d_y + all->ray.pl_y;
		int p = y - all->mlx.h / 2;
		float posZ = 0.5 * all->mlx.h;
		float rowDistance = posZ / p;
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / all->mlx.w;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / all->mlx.w;
		float floorX = all->plr.x + rowDistance * rayDirX0;
		float floorY = all->plr.y + rowDistance * rayDirY0;
		for (int x = 0; x < all->mlx.w; x++)
		{
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);
			int tx = (int)(all->t_s.t_w * (floorX - cellX)) & (all->t_s.t_w - 1);
			int ty = (int)(all->t_s.t_h * (floorY - cellY)) & (all->t_s.t_h - 1);
			floorX += floorStepX;
			floorY += floorStepY;
			all->t_s.color = (*(int *)(all->t_f.addr + ((tx +(ty * 64)) * (all->t_f.bpp / 8))));
			all->t_s.color = shade_color(all->t_s.color, rowDistance / 1.5);
			ft_putpixel(all, x, y, all->t_s.color);
			all->t_s.color = (*(int *)(all->t_c.addr + ((tx +(ty * 64)) * (all->t_c.bpp / 8))));
			all->t_s.color = shade_color(all->t_s.color, rowDistance / 1.5);
			ft_putpixel(all, x, all->mlx.h - y - 1, all->t_s.color);
		}
	}
}
