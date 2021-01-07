/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites2_bad_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:32:51 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 21:26:42 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	sort_sprites_bad(t_all *all)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = -1;
	while (++i < all->size_sprite_bad - 1)
	{
		j = -1;
		while (++j < all->size_sprite_bad - i - 1)
		{
			if (all->sprs_bad[j].spr_dist < all->sprs_bad[j + 1].spr_dist)
			{
				tmp = all->sprs_bad[j];
				all->sprs_bad[j] = all->sprs_bad[j + 1];
				all->sprs_bad[j + 1] = tmp;
			}
		}
	}
}

void	draw_next_bad(t_all *all, t_sprite sprite)
{
	int	y;

	y = all->sprbad_s.dr_sy;
	while (y < all->sprbad_s.dr_ey)
	{
		all->sprbad_s.d = (y) * 256 - all->mlx.h * 128 +
			all->sprbad_s.sp_h * 128;
		all->sprbad_s.t_y = ((all->sprbad_s.d *
			all->sprbad_s.s_h) / all->sprbad_s.sp_h) / 256;
		if (all->map[(int)sprite.y][(int)sprite.x] == '4')
			all->t_s.color = (*(int *)(all->t_spr_bad.addr +
				((all->sprbad_s.t_x + (all->sprbad_s.t_y * all->sprbad_s.s_w)) *
				(all->t_spr_bad.bpp / 8))));
		all->t_s.color = shade_color(all->t_s.color, sprite.spr_dist / 3);
		if ((all->t_s.color & 0x00FFFFFF) != 0)
			ft_putpixel(all, all->sprbad_s.stripe, y, all->t_s.color);
		y++;
	}
}

void	draw_vertical_sprite_bad(t_all *all, t_sprite sprite)
{
	all->sprbad_s.stripe = all->sprbad_s.dr_sx;
	while (all->sprbad_s.stripe < all->sprbad_s.dr_ex)
	{
		all->sprbad_s.t_x = (int)(256 * (all->sprbad_s.stripe -
			(-all->sprbad_s.sp_w / 2 + all->sprbad_s.spscrx)) *
				all->sprbad_s.s_w / all->sprbad_s.sp_w) / 256;
		if (all->sprbad_s.trfy > 0 && all->sprbad_s.stripe >
			0 && all->sprbad_s.stripe < all->mlx.w && all->sprbad_s.trfy <
			all->ray.z_buf[all->sprbad_s.stripe])
			draw_next_bad(all, sprite);
		all->sprbad_s.stripe++;
	}
}
