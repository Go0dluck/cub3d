/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_floor_ceilling_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:43:01 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/08 19:28:03 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	get_color_floor(t_all *all, int x, int y)
{
	if (all->flor_cel.is_floor)
	{
		all->t_s.color = (*(int *)(all->t_f.addr + ((all->flor_cel.tx +
			(all->flor_cel.ty * 64)) * (all->t_f.bpp / 8))));
		all->t_s.color = shade_color(all->t_s.color,
			all->flor_cel.r_dist / 1.5);
		ft_putpixel(all, x, y, all->t_s.color);
	}
	else
	{
		all->t_s.color = (*(int *)(all->t_c.addr + ((all->flor_cel.tx +
			(all->flor_cel.ty * 64)) * (all->t_c.bpp / 8))));
		all->t_s.color = shade_color(all->t_s.color,
			all->flor_cel.r_dist / 1.5);
		ft_putpixel(all, x, y, all->t_s.color);
	}
}

void	draw_floor_ceilling(t_all *all, int y)
{
	int	x;

	x = -1;
	while (++x < all->mlx.w)
	{
		all->flor_cel.c_x = (int)(all->flor_cel.f_x);
		all->flor_cel.c_y = (int)(all->flor_cel.f_y);
		all->flor_cel.tx = (int)(all->t_s.t_w * (all->flor_cel.f_x -
			all->flor_cel.c_x)) & (all->t_s.t_w - 1);
		all->flor_cel.ty = (int)(all->t_s.t_h * (all->flor_cel.f_y -
			all->flor_cel.c_y)) & (all->t_s.t_h - 1);
		all->flor_cel.f_x += all->flor_cel.f_sx;
		all->flor_cel.f_y += all->flor_cel.f_sy;
		get_color_floor(all, x, y);
	}
}

void	raycast_floor_ceilling(t_all *all)
{
	int	y;

	y = -1;
	while (++y < all->mlx.h)
	{
		all->flor_cel.is_floor = y > all->mlx.h / 2 + all->ray.pitch;
		all->flor_cel.rd_x0 = all->ray.d_x - all->ray.pl_x;
		all->flor_cel.rd_y0 = all->ray.d_y - all->ray.pl_y;
		all->flor_cel.rd_x1 = all->ray.d_x + all->ray.pl_x;
		all->flor_cel.rd_y1 = all->ray.d_y + all->ray.pl_y;
		all->flor_cel.p = all->flor_cel.is_floor ? (y - all->mlx.h / 2 -
			all->ray.pitch) : (all->mlx.h / 2 - y + all->ray.pitch);
		all->flor_cel.p_z = 0.5 * all->mlx.h;
		all->flor_cel.r_dist = all->flor_cel.p_z / all->flor_cel.p;
		all->flor_cel.f_sx = all->flor_cel.r_dist *
			(all->flor_cel.rd_x1 - all->flor_cel.rd_x0) / all->mlx.w;
		all->flor_cel.f_sy = all->flor_cel.r_dist *
			(all->flor_cel.rd_y1 - all->flor_cel.rd_y0) / all->mlx.w;
		all->flor_cel.f_x = all->plr.x + all->flor_cel.r_dist
			* all->flor_cel.rd_x0;
		all->flor_cel.f_y = all->plr.y + all->flor_cel.r_dist
			* all->flor_cel.rd_y0;
		draw_floor_ceilling(all, y);
	}
}
