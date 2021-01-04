/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:41:01 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/04 19:31:58 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	verline(int x, t_all *all)
{
	unsigned int color = 0;

	for(int y = 0; y < all->ray.drawStart; y++)
	{
		ft_putpixel(all, x, y, create_rgb_c(all));
	}
	for(int y = all->ray.drawStart; y < all->ray.drawEnd; y++)
	{
		all->text_set.texY = (int)all->text_set.texPos & (all->text_set.texHeight - 1);
		all->text_set.texPos += all->text_set.step;
		if (all->ray.side == 0)
			color = (*(int *)(all->text_no.addr + ((all->text_set.texX + (all->text_set.texY * 64)) * (all->text_no.bits_per_pixel / 8))));
		else if (all->ray.side == 1)
			color = (*(int *)(all->text_so.addr + ((all->text_set.texX + (all->text_set.texY * 64)) * (all->text_so.bits_per_pixel / 8))));
		else if (all->ray.side == 2)
			color = (*(int *)(all->text_we.addr + ((all->text_set.texX + (all->text_set.texY * 64)) * (all->text_we.bits_per_pixel / 8))));
		else if (all->ray.side == 3)
			color = (*(int *)(all->text_ea.addr + ((all->text_set.texX + (all->text_set.texY * 64)) * (all->text_ea.bits_per_pixel / 8))));
		ft_putpixel(all, x, y, color);
	}
	for(int y = all->ray.drawEnd; y < all->mlx.h; y++)
	{
		ft_putpixel(all, x, y, create_rgb_f(all));
	}

}

void	wall_dist(t_all *all)
{
	if (all->ray.side == 0 || all->ray.side == 1)
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
			if (all->ray.stepX == 1)
				all->ray.side = 0;
			else if (all->ray.stepX == -1)
				all->ray.side = 1;
		}
		else
		{
			all->ray.sideDistY += all->ray.deltaDistY;
			all->ray.mapY += all->ray.stepY;
			if (all->ray.stepY == 1)
				all->ray.side = 2;
			else if (all->ray.stepY == -1)
				all->ray.side = 3;
		}
		if (all->map[all->ray.mapY][all->ray.mapX] > '0')
			all->ray.hit = 1;
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
	all->ray.deltaDistX = fabs(1 / all->ray.rayDirX);
	all->ray.deltaDistY = fabs(1 / all->ray.rayDirY);
}

void	texture_seting(t_all *all)
{
	if (all->ray.side == 0 || all->ray.side == 1)
		all->text_set.wallX = all->plr.y + all->ray.perpWallDist * all->ray.rayDirY;
	else
		all->text_set.wallX = all->plr.x + all->ray.perpWallDist * all->ray.rayDirX;
	all->text_set.wallX -= floor((all->text_set.wallX));
	all->text_set.texX = (int)(all->text_set.wallX * (double)all->text_set.texWidth);
	if ((all->ray.side == 0 || all->ray.side == 1) && all->ray.rayDirX > 0)
		all->text_set.texX = all->text_set.texWidth - all->text_set.texX - 1;
	if ((all->ray.side == 2 || all->ray.side == 3) && all->ray.rayDirY < 0)
		all->text_set.texX = all->text_set.texWidth - all->text_set.texX - 1;
	all->text_set.step = 1.0 * all->text_set.texHeight / all->ray.lineHeight;
	all->text_set.texPos = (all->ray.drawStart - all->mlx.h / 2 + all->ray.lineHeight / 2) * all->text_set.step;
}

void	raycast(t_all *all)
{
	all->mlx.img = mlx_new_image(all->mlx.mlx, all->mlx.w, all->mlx.h);
	all->mlx.addr = mlx_get_data_addr(all->mlx.img, &all->mlx.bits_per_pixel, &all->mlx.line_length, &all->mlx.endian);
	all->ray.zBuffer = malloc(sizeof(double) * all->mlx.w);
	for (int x = 0; x < all->mlx.w; x++)
	{
		ray(x, all);
		ray_size(all);
		hit(all);
		wall_dist(all);
		all->ray.zBuffer[x] = all->ray.perpWallDist;
		texture_seting(all);
		verline(x, all);
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	free(all->ray.zBuffer);
}
