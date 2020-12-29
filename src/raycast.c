/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:41:01 by ksharee           #+#    #+#             */
/*   Updated: 2020/12/29 16:58:21 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	verline(int x, t_all *all)
{
	unsigned int color = 0;
	//write(1, "HELLO\n", 6);
	for(int y = 0; y < all->ray.drawStart; y++)
	{
		ft_putpixel(all, x, y, 0x202020);
	}
	for(int y = all->ray.drawStart; y < all->ray.drawEnd; y++)
	{

		all->text.texY = (int)all->text.texPos & (all->text.texHeight - 1);
		all->text.texPos += all->text.step;
		if (all->ray.side == 0)
			color = (*(int *)(all->text.addr + ((all->text.texX + (all->text.texY * 64)) * (all->text.bits_per_pixel / 8))));
		else if (all->ray.side == 1)
			color = (*(int *)(all->text1.addr + ((all->text.texX + (all->text.texY * 64)) * (all->text1.bits_per_pixel / 8))));
		else if (all->ray.side == 2)
			color = (*(int *)(all->text2.addr + ((all->text.texX + (all->text.texY * 64)) * (all->text1.bits_per_pixel / 8))));
		else if (all->ray.side == 3)
			color = (*(int *)(all->text3.addr + ((all->text.texX + (all->text.texY * 64)) * (all->text1.bits_per_pixel / 8))));
		ft_putpixel(all, x, y, color);
	}
	for(int y = all->ray.drawEnd; y < all->mlx.h; y++)
	{
		ft_putpixel(all, x, y, 0x202020);
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
			//all->ray.side = 0;
			if (all->ray.stepX == 1)
				all->ray.side = 0;
			else if (all->ray.stepX == -1)
				all->ray.side = 1;
		}
		else
		{
			all->ray.sideDistY += all->ray.deltaDistY;
			all->ray.mapY += all->ray.stepY;
			//all->ray.side = 1;
			if (all->ray.stepY == 1)
				all->ray.side = 2;
			else if (all->ray.stepY == -1)
				all->ray.side = 3;
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
	//all->ray.deltaDistX = (all->ray.rayDirY == 0) ? 0 : ((all->ray.rayDirX == 0) ? 1 : sqrt(1 + (all->ray.rayDirY * all->ray.rayDirY) / (all->ray.rayDirX * all->ray.rayDirX)));
	//all->ray.deltaDistY = (all->ray.rayDirX == 0) ? 0 : ((all->ray.rayDirY == 0) ? 1 : sqrt(1 + (all->ray.rayDirX * all->ray.rayDirX) / (all->ray.rayDirY * all->ray.rayDirY)));
	all->ray.deltaDistX = fabs(1 / all->ray.rayDirX);
	all->ray.deltaDistY = fabs(1 / all->ray.rayDirY);
}

void	texture_draw(t_all *all)
{
	//all->text.texNum = all->map[all->ray.mapY][all->ray.mapX] - 1;
	if (all->ray.side == 0 || all->ray.side == 1)
		all->text.wallX = all->plr.y + all->ray.perpWallDist * all->ray.rayDirY;
	else
		all->text.wallX = all->plr.x + all->ray.perpWallDist * all->ray.rayDirX;
	all->text.wallX -= floor((all->text.wallX));
	all->text.texX = (int)(all->text.wallX * (double)all->text.texWidth);
	if ((all->ray.side == 0 || all->ray.side == 1) && all->ray.rayDirX > 0)
		all->text.texX = all->text.texWidth - all->text.texX - 1;
	if ((all->ray.side == 2 || all->ray.side == 3) && all->ray.rayDirY < 0)
		all->text.texX = all->text.texWidth - all->text.texX - 1;
	all->text.step = 1.0 * all->text.texHeight / all->ray.lineHeight;
	all->text.texPos = (all->ray.drawStart - all->mlx.h / 2 + all->ray.lineHeight / 2) * all->text.step;
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
		texture_draw(all);
		verline(x, all);
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
}
