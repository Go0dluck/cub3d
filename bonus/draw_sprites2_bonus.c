/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:31:44 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/09 16:09:59 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	sort_sprites(t_all *all)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = -1;
	while (++i < all->size_sprite - 1)
	{
		j = -1;
		while (++j < all->size_sprite - i - 1)
		{
			if (all->sprs[j].spr_dist < all->sprs[j + 1].spr_dist)
			{
				tmp = all->sprs[j];
				all->sprs[j] = all->sprs[j + 1];
				all->sprs[j + 1] = tmp;
			}
		}
	}
}

void	draw_next(t_all *all, t_sprite sprite)
{
	int	y;

	y = all->spr_s.dr_sy - 1;
	while (++y < all->spr_s.dr_ey)
	{
		all->spr_s.d = (y - all->spr_s.vms) * 256 - all->mlx.h * 128 +
			all->spr_s.sp_h * 128;
		all->spr_s.t_y = ((all->spr_s.d * all->spr_s.s_h) /
			all->spr_s.sp_h) / 256;
		if (all->map[(int)sprite.y][(int)sprite.x] == '2')
			all->t_s.color = (*(int *)(all->t_life.addr +
				((all->spr_s.t_x + (all->spr_s.t_y * all->spr_s.s_w)) *
				(all->t_life.bpp / 8))));
		else if (all->map[(int)sprite.y][(int)sprite.x] == '3')
			all->t_s.color = (*(int *)(all->t_spr2.addr +
				((all->spr_s.t_x + (all->spr_s.t_y * all->spr_s.s_w)) *
				(all->t_spr2.bpp / 8))));
		else if (all->map[(int)sprite.y][(int)sprite.x] == '4')
			all->t_s.color = (*(int *)(all->t_spr_bad.addr +
				((all->spr_s.t_x + (all->spr_s.t_y * all->spr_s.s_w)) *
				(all->t_spr_bad.bpp / 8))));
		all->t_s.color = shade_color(all->t_s.color, sprite.spr_dist / 3);
		if ((all->t_s.color & 0x00FFFFFF) != 0 && all->heart_size != 0)
			ft_putpixel(all, all->spr_s.stripe, y, all->t_s.color);
	}
}

void	draw_vertical_sprite(t_all *all, t_sprite sprite)
{
	all->spr_s.stripe = all->spr_s.dr_sx;
	while (all->spr_s.stripe < all->spr_s.dr_ex)
	{
		all->spr_s.t_x = (int)(256 * (all->spr_s.stripe -
			(-all->spr_s.sp_w / 2 + all->spr_s.spscrx)) *
				all->spr_s.s_w / all->spr_s.sp_w) / 256;
		if (all->spr_s.trfy > 0 && all->spr_s.stripe >
			0 && all->spr_s.stripe < all->mlx.w && all->spr_s.trfy <
			all->ray.z_buf[all->spr_s.stripe])
			draw_next(all, sprite);
		all->spr_s.stripe++;
	}
}
