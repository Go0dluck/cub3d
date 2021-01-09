/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:21:24 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/09 15:57:00 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	draw_dead(t_all *all)
{
	int				x;
	int				y;
	unsigned int	color;

	all->death = true;
	y = 0;
	while (y < all->death_s.s_h)
	{
		x = 0;
		while (x < all->death_s.s_w)
		{
			color = (*(int *)(all->dead.addr + (y *
				all->dead.line_length + x * (all->dead.bpp / 8))));
			if ((color & 0x00FFFFFF) != 0)
				ft_putpixel(all, x + (all->mlx.w / 2) -
						(all->death_s.s_w / 2), y + (all->mlx.h / 2), color);
			x++;
		}
		y++;
	}
}

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
	all->spr_s.sp_w = abs((int)(all->mlx.h / (all->spr_s.trfy))) / UDIV;
	all->spr_s.dr_sx = -all->spr_s.sp_w / 2 + all->spr_s.spscrx;
	if (all->spr_s.dr_sx < 0)
		all->spr_s.dr_sx = 0;
	all->spr_s.dr_ex = all->spr_s.sp_w / 2 + all->spr_s.spscrx;
	if (all->spr_s.dr_ex >= all->mlx.w)
		all->spr_s.dr_ex = all->mlx.w - 1;
}

void	sprite_height(t_all *all)
{
	all->spr_s.vms = (int)(VMOVE / all->spr_s.trfy) + all->ray.pitch;
	all->spr_s.sp_h = abs((int)(all->mlx.h / (all->spr_s.trfy))) / VDIV;
	all->spr_s.dr_sy = -all->spr_s.sp_h / 2 + all->mlx.h / 2 + all->spr_s.vms;
	if (all->spr_s.dr_sy < 0)
		all->spr_s.dr_sy = 0;
	all->spr_s.dr_ey = all->spr_s.sp_h / 2 + all->mlx.h / 2 + all->spr_s.vms;
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
	all->sprs[all->size_sprite - 1].spr_dist < 0.2 ? del_sprites(all) : 0;
	i = -1;
	while (++i < all->size_sprite)
	{
		camera_transform(all, all->sprs[i]);
		sprite_height(all);
		sprite_width(all);
		draw_vertical_sprite(all, all->sprs[i]);
	}
}
