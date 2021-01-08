/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 21:13:03 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/08 16:26:44 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	draw_side(t_all *all, int x)
{
	int	y;

	y = all->ray.d_s;
	while (y < all->ray.d_e)
	{
		all->t_s.t_y = (int)all->t_s.t_p & (all->t_s.t_h - 1);
		all->t_s.t_p += all->t_s.step;
		if (all->ray.side == 0)
			all->t_s.color = (*(int *)(all->t_no.addr + ((all->t_s.t_x +
				(all->t_s.t_y * 64)) * (all->t_no.bpp / 8))));
		else if (all->ray.side == 1)
			all->t_s.color = (*(int *)(all->t_no.addr + ((all->t_s.t_x +
				(all->t_s.t_y * 64)) * (all->t_no.bpp / 8))));
		else if (all->ray.side == 2)
			all->t_s.color = (*(int *)(all->t_no.addr + ((all->t_s.t_x +
				(all->t_s.t_y * 64)) * (all->t_no.bpp / 8))));
		else if (all->ray.side == 3)
			all->t_s.color = (*(int *)(all->t_no.addr + ((all->t_s.t_x +
				(all->t_s.t_y * 64)) * (all->t_no.bpp / 8))));
		all->t_s.color = shade_color(all->t_s.color, all->ray.w_dist / 1.5);
		ft_putpixel(all, x, y, all->t_s.color);
		y++;
	}
}

void	verline(int x, t_all *all)
{
	draw_side(all, x);
}

void	texture_seting(t_all *all)
{
	if (all->ray.side == 0 || all->ray.side == 1)
		all->t_s.wallx = all->plr.y + all->ray.w_dist * all->ray.r_dy;
	else
		all->t_s.wallx = all->plr.x + all->ray.w_dist * all->ray.r_dx;
	all->t_s.wallx -= floor((all->t_s.wallx));
	all->t_s.t_x = (int)(all->t_s.wallx * (double)all->t_s.t_w);
	if ((all->ray.side == 0 || all->ray.side == 1) && all->ray.r_dx > 0)
		all->t_s.t_x = all->t_s.t_w - all->t_s.t_x - 1;
	if ((all->ray.side == 2 || all->ray.side == 3) && all->ray.r_dy < 0)
		all->t_s.t_x = all->t_s.t_w - all->t_s.t_x - 1;
	all->t_s.step = 1.0 * all->t_s.t_h / all->ray.l_h;
	all->t_s.t_p = (all->ray.d_s - all->ray.pitch
		- all->mlx.h / 2 + all->ray.l_h / 2) * all->t_s.step;
}
