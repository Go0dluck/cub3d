/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:41:01 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 22:00:06 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	wall_dist(t_all *all)
{
	if (all->ray.side == 0 || all->ray.side == 1)
		all->ray.w_dist = (all->ray.m_x - all->plr.x +
			(1 - all->ray.s_x) / 2) / all->ray.r_dx;
	else
		all->ray.w_dist = (all->ray.m_y - all->plr.y +
			(1 - all->ray.s_y) / 2) / all->ray.r_dy;
	all->ray.l_h = (int)(all->mlx.h / all->ray.w_dist);
	all->ray.d_s = -all->ray.l_h / 2 + all->mlx.h / 2;
	if (all->ray.d_s < 0)
		all->ray.d_s = 0;
	all->ray.d_e = all->ray.l_h / 2 + all->mlx.h / 2;
	if (all->ray.d_e >= all->mlx.h)
		all->ray.d_e = all->mlx.h - 1;
}

void	ray_size(t_all *all)
{
	if (all->ray.r_dx < 0)
	{
		all->ray.s_x = -1;
		all->ray.s_dx = (all->plr.x - all->ray.m_x) * all->ray.d_dx;
	}
	else
	{
		all->ray.s_x = 1;
		all->ray.s_dx = (all->ray.m_x + 1.0 -
			all->plr.x) * all->ray.d_dx;
	}
	if (all->ray.r_dy < 0)
	{
		all->ray.s_y = -1;
		all->ray.s_dy = (all->plr.y - all->ray.m_y) * all->ray.d_dy;
	}
	else
	{
		all->ray.s_y = 1;
		all->ray.s_dy = (all->ray.m_y + 1.0 -
			all->plr.y) * all->ray.d_dy;
	}
}

void	hit(t_all *all)
{
	all->ray.hit = 0;
	while (all->ray.hit == 0)
	{
		if (all->ray.s_dx < all->ray.s_dy)
		{
			all->ray.s_dx += all->ray.d_dx;
			all->ray.m_x += all->ray.s_x;
			if (all->ray.s_x == 1)
				all->ray.side = 0;
			else if (all->ray.s_x == -1)
				all->ray.side = 1;
		}
		else
		{
			all->ray.s_dy += all->ray.d_dy;
			all->ray.m_y += all->ray.s_y;
			if (all->ray.s_y == 1)
				all->ray.side = 2;
			else if (all->ray.s_y == -1)
				all->ray.side = 3;
		}
		if (all->map[all->ray.m_y][all->ray.m_x] == '1')
			all->ray.hit = 1;
	}
}

void	ray(int x, t_all *all)
{
	all->ray.c_x = 2 * x / (double)all->mlx.w - 1;
	all->ray.r_dx = all->ray.d_x + all->ray.pl_x * all->ray.c_x;
	all->ray.r_dy = all->ray.d_y + all->ray.pl_y * all->ray.c_x;
	all->ray.m_x = (int)all->plr.x;
	all->ray.m_y = (int)all->plr.y;
	all->ray.d_dx = fabs(1 / all->ray.r_dx);
	all->ray.d_dy = fabs(1 / all->ray.r_dy);
}

void	raycast(t_all *all)
{
	int x;

	x = -1;
	all->mlx.img = mlx_new_image(all->mlx.mlx, all->mlx.w, all->mlx.h);
	all->mlx.addr = mlx_get_data_addr(all->mlx.img, &all->mlx.bits_per_pixel,
		&all->mlx.line_length, &all->mlx.endian);
	all->ray.z_buf = malloc(sizeof(double) * all->mlx.w);
	raycast_floor_ceilling(all);
	while (++x < all->mlx.w)
	{
		ray(x, all);
		ray_size(all);
		hit(all);
		wall_dist(all);
		all->ray.z_buf[x] = all->ray.w_dist;
		texture_seting(all);
		verline(x, all);
	}
	draw_sprites(all);
	draw_sprites_bad(all);
	draw_lifebar(all);
	all->blast == 1 ? draw_blast(all) : 0;
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	all->save == 0 ? mlx_destroy_image(all->mlx.mlx, all->mlx.img) : 0;
	free(all->ray.z_buf);
}
