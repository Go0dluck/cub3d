/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:20:28 by goodluck          #+#    #+#             */
/*   Updated: 2020/12/21 08:29:46 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verline(int x, t_all *all)
{
	int y;

	y = 0;
	while (y < all->ray.drawStart)
	{
		ft_putpixel(all, x, y, 0x99FFFF);
		y++;
	}
	while(all->ray.drawStart < all->ray.drawEnd)
	{
		ft_putpixel(all, x, all->ray.drawStart, 0xCC3300);
		all->ray.drawStart++;
	}
	while (all->ray.drawEnd < all->mlx.h)
	{
		ft_putpixel(all, x, all->ray.drawEnd, 0xCCCCCC);
		all->ray.drawEnd++;
	}
}

void	wall_dist(t_all *all)
{
	if (all->ray.side == 0)
		all->ray.perpWallDist = (all->ray.mapX - all->plr.x + (1 - all->ray.stepX) / 2) / all->ray.rayDirX;
	else
		all->ray.perpWallDist = (all->ray.mapY - all->plr.y + (1 - all->ray.stepY) / 2) / all->ray.rayDirY;
	all->ray.lineHeight = (int)(all->mlx.h / all->ray.perpWallDist);
	all->ray.drawStart = -all->ray.lineHeight / 2 + all->mlx.h / 2;
	if (all->ray.drawStart < 0)
		all->ray.drawStart = 0;
	all->ray.drawEnd = all->ray.lineHeight / 2 + all->mlx.h / 2;
	if (all->ray.drawEnd >= all->mlx.h)
		all->ray.drawEnd = all->mlx.h - 1;
}

void	hit(t_all *all)
{
	all->ray.hit = 0;
	while (all->ray.hit == 0)
	{
		if (all->ray.sideDistX < all->ray.sideDistY)
		{
			all->ray.sideDistX += all->ray.deltaDistX;
			all->ray.mapX += all->ray.stepX;
			all->ray.side = 0;
		}
		else
		{
			all->ray.sideDistY += all->ray.deltaDistY;
			all->ray.mapY += all->ray.stepY;
			all->ray.side = 1;
		}
		if (all->map[all->ray.mapY][all->ray.mapX] == '1')
		{
			all->ray.hit = 1;
		}
	}
}

void	ray_size(t_all *all)
{
	if (all->ray.rayDirX < 0)
	{
		all->ray.stepX = -1;
		all->ray.sideDistX = (all->plr.x - all->ray.mapX) * all->ray.deltaDistX;
	}
	else
	{
		all->ray.stepX = 1;
		all->ray.sideDistX = (all->ray.mapX + 1.0 - all->plr.x) * all->ray.deltaDistX;
	}
	if (all->ray.rayDirY < 0)
	{
		all->ray.stepY = -1;
		all->ray.sideDistY = (all->plr.y - all->ray.mapY) * all->ray.deltaDistY;
	}
	else
	{
		all->ray.stepY = 1;
		all->ray.sideDistY = (all->ray.mapY + 1.0 - all->plr.y) * all->ray.deltaDistY;
	}
}

void	ray(int x, t_all *all)
{
	all->ray.cameraX = 2 * x / (double)all->mlx.w - 1;
	all->ray.rayDirX = all->ray.dirX + all->ray.planeX * all->ray.cameraX;
	all->ray.rayDirY = all->ray.dirY + all->ray.planeY * all->ray.cameraX;
	all->ray.mapX = (int)all->plr.x;
	all->ray.mapY = (int)all->plr.y;
	all->ray.deltaDistX = (all->ray.rayDirY == 0) ? 0 : ((all->ray.rayDirX == 0) ? 1 : sqrt(1 + (all->ray.rayDirY * all->ray.rayDirY) / (all->ray.rayDirX * all->ray.rayDirX)));
	all->ray.deltaDistY = (all->ray.rayDirX == 0) ? 0 : ((all->ray.rayDirY == 0) ? 1 : sqrt(1 + (all->ray.rayDirX * all->ray.rayDirX) / (all->ray.rayDirY * all->ray.rayDirY)));
}

void	raycast(t_all *all)
{
	all->mlx.img = mlx_new_image(all->mlx.mlx, all->mlx.w, all->mlx.h);
	all->mlx.addr = mlx_get_data_addr(all->mlx.img, &all->mlx.bits_per_pixel, &all->mlx.line_length, &all->mlx.endian);
	for (int x = 0; x < all->mlx.w; x++)
	{
		ray(x, all);
		ray_size(all);
		hit(all);
		wall_dist(all);
		verline(x, all);
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
}
