/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:21:24 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 15:20:05 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	camera_transform(t_all *all, t_sprite sprite)
{
	all->spr_s.spx = sprite.x - all->plr.x;
	all->spr_s.spy = sprite.y - all->plr.y;
	all->spr_s.invdet = 1.0 / (all->ray.pl_x *
		all->ray.d_y - all->ray.d_x * all->ray.pl_y);
	all->spr_s.trfx = all->spr_s.invdet *
		(all->ray.d_y * all->spr_s.spx - all->ray.d_x * all->spr_s.spy);
	all->spr_s.trfy = all->spr_s.invdet *
		(-all->ray.pl_y * all->spr_s.spx + all->ray.pl_x * all->spr_s.spy);
	all->spr_s.spscrx = (int)((all->mlx.w / 2) *
		(1 + all->spr_s.trfx / all->spr_s.trfy));
}

void	sprite_width(t_all *all)
{
	all->spr_s.sp_w = abs((int)(all->mlx.h / (all->spr_s.trfy)));
	all->spr_s.dr_sx = -all->spr_s.sp_w / 2 + all->spr_s.spscrx;
	if (all->spr_s.dr_sx < 0)
		all->spr_s.dr_sx = 0;
	all->spr_s.dr_ex = all->spr_s.sp_w / 2 + all->spr_s.spscrx;
	if (all->spr_s.dr_ex >= all->mlx.w)
		all->spr_s.dr_ex = all->mlx.w - 1;
}

void	sprite_height(t_all *all)
{
	all->spr_s.sp_h = abs((int)(all->mlx.h / (all->spr_s.trfy)));
	all->spr_s.dr_sy = -all->spr_s.sp_h / 2 + all->mlx.h / 2;
	if (all->spr_s.dr_sy < 0)
		all->spr_s.dr_sy = 0;
	all->spr_s.dr_ey = all->spr_s.sp_h / 2 + all->mlx.h / 2;
	if (all->spr_s.dr_ey >= all->mlx.h)
		all->spr_s.dr_ey = all->mlx.h - 1;
}

void	draw_sprites(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->size_sprite)
		all->sprs[i].spr_dist = ((all->plr.x - all->sprs[i].x) *
			(all->plr.x - all->sprs[i].x) + (all->plr.y - all->sprs[i].y) *
				(all->plr.y - all->sprs[i].y));
	sort_sprites(all);
	i = -1;
	while (++i < all->size_sprite)
	{
		camera_transform(all, all->sprs[i]);
		sprite_height(all);
		sprite_width(all);
		draw_vertical_sprite(all, all->sprs[i]);
	}
}
