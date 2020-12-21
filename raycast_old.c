/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_old.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:45:13 by ksharee           #+#    #+#             */
/*   Updated: 2020/12/21 08:25:17 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_vert(t_all *all, int x)
{
	while (all->ray.drawStart < all->ray.drawEnd)
	{
		ft_putpixel(all, x, all->ray.drawStart, 0xFF0000);
		all->ray.drawStart++;
	}
}

void	raycast_old(t_all *all)
{
	int		x;

	x = -1;
	all->mlx.img = mlx_new_image(all->mlx.mlx, all->mlx.w, all->mlx.h);
	all->mlx.addr = mlx_get_data_addr(all->mlx.img, &all->mlx.bits_per_pixel,
		&all->mlx.line_length, &all->mlx.endian);
	while (++x < all->mlx.w)
	{
		all->ray.cameraX = 2 * x / (double)all->mlx.w - 1;
		all->ray.rayDirX = all->ray.dirX + all->ray.planeX * all->ray.cameraX;
		all->ray.rayDirY = all->ray.dirY + all->ray.planeY * all->ray.cameraX;
		all->ray.mapX = (int)all->plr.x;
		all->ray.mapY = (int)all->plr.y;
		//all->ray.deltaDistX = sqrt(1 + (all->ray.rayDirY * all->ray.rayDirY) / (all->ray.rayDirX * all->ray.rayDirX));
		//all->ray.deltaDistY = sqrt(1 + (all->ray.rayDirX * all->ray.rayDirX) / (all->ray.rayDirY * all->ray.rayDirY));
		all->ray.deltaDistX = fabs (1 / all->ray.rayDirX);
		all->ray.deltaDistY = fabs (1 / all->ray.rayDirY);
		all->ray.hit = 0;
		if (all->ray.dirX < 0)
		{
			all->ray.stepX = -1;
			all->ray.sideDistX = (all->plr.x - all->ray.mapX) * all->ray.deltaDistX;
		}
		else
		{
			all->ray.stepX = 1;
			all->ray.sideDistX = (all->ray.mapX + 1.0 - all->plr.x) * all->ray.deltaDistX;
		}
		if (all->ray.dirY < 0)
		{
			all->ray.stepY = -1;
			all->ray.sideDistY = (all->plr.y - all->ray.mapY) * all->ray.deltaDistY;
		}
		else
		{
			all->ray.stepY = 1;
			all->ray.sideDistY = (all->ray.mapY + 1.0 - all->plr.y) * all->ray.deltaDistY;
		}
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
			if (all->map[all->ray.mapY][all->ray.mapX] > '0')
			{
				printf("y = %d x = %d\n", all->ray.mapY, all->ray.mapX);
				all->ray.hit = 1;
			}
		}
		if (all->ray.side == 0)
			all->ray.perpWallDist = fabs((all->ray.mapX - all->plr.x + (1 - all->ray.stepX) / 2) / all->ray.rayDirX);
		else
			all->ray.perpWallDist = fabs((all->ray.mapY - all->plr.y + (1 - all->ray.stepY) / 2) / all->ray.rayDirY);
		all->ray.lineHeight = (int)(all->mlx.h / all->ray.perpWallDist);
		all->ray.drawStart = -all->ray.lineHeight / 2 + all->mlx.h / 2;
		if (all->ray.drawStart < 0)
			all->ray.drawStart = 0;
		all->ray.drawEnd = all->ray.lineHeight / 2 + all->mlx.h / 2;
		if (all->ray.drawEnd >= all->mlx.h)
			all->ray.drawEnd = all->mlx.h - 1;
		print_vert(all, x);
		//printf("wallDist = %f lineHeight = %d start = %d end = %d\n", all->ray.perpWallDist, all->ray.lineHeight, all->ray.drawStart, all->ray.drawEnd);
	}
	//printf("HELLO\n");
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
}
