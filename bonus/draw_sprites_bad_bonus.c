/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_bad_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:31:43 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 22:02:16 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	camera_transform_bad(t_all *all, t_sprite sprite)
{
	all->sprbad_s.spx = sprite.x - all->plr.x;
	all->sprbad_s.spy = sprite.y - all->plr.y;
	all->sprbad_s.invdet = 1.0 / (all->ray.pl_x *
		all->ray.d_y - all->ray.d_x * all->ray.pl_y);
	all->sprbad_s.trfx = all->sprbad_s.invdet *
		(all->ray.d_y * all->sprbad_s.spx - all->ray.d_x * all->sprbad_s.spy);
	all->sprbad_s.trfy = all->sprbad_s.invdet *
		(-all->ray.pl_y * all->sprbad_s.spx + all->ray.pl_x *
			all->sprbad_s.spy);
	all->sprbad_s.spscrx = (int)((all->mlx.w / 2) *
		(1 + all->sprbad_s.trfx / all->sprbad_s.trfy));
}

void	sprite_width_bad(t_all *all)
{
	all->sprbad_s.sp_w = abs((int)(all->mlx.h / (all->sprbad_s.trfy)));
	all->sprbad_s.dr_sx = -all->sprbad_s.sp_w / 2 + all->sprbad_s.spscrx;
	if (all->sprbad_s.dr_sx < 0)
		all->sprbad_s.dr_sx = 0;
	all->sprbad_s.dr_ex = all->sprbad_s.sp_w / 2 + all->sprbad_s.spscrx;
	if (all->sprbad_s.dr_ex >= all->mlx.w)
		all->sprbad_s.dr_ex = all->mlx.w - 1;
}

void	sprite_height_bad(t_all *all)
{
	all->sprbad_s.sp_h = abs((int)(all->mlx.h / (all->sprbad_s.trfy)));
	all->sprbad_s.dr_sy = -all->sprbad_s.sp_h / 2 + all->mlx.h / 2;
	if (all->sprbad_s.dr_sy < 0)
		all->sprbad_s.dr_sy = 0;
	all->sprbad_s.dr_ey = all->sprbad_s.sp_h / 2 + all->mlx.h / 2;
	if (all->sprbad_s.dr_ey >= all->mlx.h)
		all->sprbad_s.dr_ey = all->mlx.h - 1;
}

void	draw_sprites_bad(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->size_sprite_bad)
		all->sprs_bad[i].spr_dist = ((all->plr.x - all->sprs_bad[i].x) *
			(all->plr.x - all->sprs_bad[i].x) + (all->plr.y -
				all->sprs_bad[i].y) * (all->plr.y - all->sprs_bad[i].y));
	sort_sprites_bad(all);
	i = -1;
	while (++i < all->size_sprite_bad)
	{
		camera_transform_bad(all, all->sprs_bad[i]);
		sprite_height_bad(all);
		sprite_width_bad(all);
		draw_vertical_sprite_bad(all, all->sprs_bad[i]);
	}
}
