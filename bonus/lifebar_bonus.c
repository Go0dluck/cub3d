/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifebar_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:03:21 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/08 22:51:45 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	draw_blast(t_all *all)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < all->blast_s.t_h)
	{
		x = 0;
		while (x < all->blast_s.t_w)
		{
			color = (*(int *)(all->t_blast.addr + (y *
				all->t_blast.line_length + x * (all->t_blast.bpp / 8))));
			if ((color & 0x00FFFFFF) != 0)
				ft_putpixel(all, x + (all->mlx.w / 2) -
					(all->blast_s.t_w / 2), y + (all->mlx.h / 2) +
					(all->blast_s.t_h), color);
			x++;
		}
		y++;
	}
}

void	draw_center(t_all *all)
{
	int	x;

	x = all->mlx.w / 2 - 15;
	while (x < all->mlx.w / 2 + 15)
	{
		ft_putpixel(all, x, all->mlx.h / 2, 0xFF0000);
		x++;
	}
	x = all->mlx.h / 2 - 15;
	while (x < all->mlx.h / 2 + 15)
	{
		ft_putpixel(all, all->mlx.w / 2, x, 0xFF0000);
		x++;
	}
}

void	draw_gun(t_all *all)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < all->gun_s.t_h)
	{
		x = 0;
		while (x < all->gun_s.t_w)
		{
			color = (*(int *)(all->t_gun.addr + (y *
				all->t_gun.line_length + x * (all->t_gun.bpp / 8))));
			if ((color & 0x00FFFFFF) != 0)
				ft_putpixel(all, x + ((all->mlx.w / 2) -
					(all->gun_s.t_w / 2)), y + ((all->mlx.h / 2) +
					(all->gun_s.t_h / 2)), color);
			x++;
		}
		y++;
	}
	draw_center(all);
}

void	draw_lifebar(t_all *all)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < all->life_s.t_h)
	{
		x = 0;
		while (x < all->life_s.t_w)
		{
			color = (*(int *)(all->t_life.addr + (y *
				all->t_life.line_length + x * (all->t_life.bpp / 8))));
			if ((color & 0x00FFFFFF) != 0)
				ft_putpixel(all, x, y, color);
			x++;
		}
		y++;
	}
	draw_gun(all);
}
