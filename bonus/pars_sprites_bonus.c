/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:41:27 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/09 11:04:03 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	set_text_sprite(t_all *all, char *path)
{
	all->t_spr.img != NULL ? ft_error("Дубликат SPRITE текстуры", all) : 0;
	all->t_spr.img = mlx_xpm_file_to_image(all->mlx.mlx, path,
		&all->t_spr.img_w, &all->t_spr.img_h);
	all->t_spr.img == NULL ?
		ft_error("Ошибка открытия файла SPRITE текстуры", all) : 0;
	all->t_spr.addr = mlx_get_data_addr(all->t_spr.img,
		&all->t_spr.bpp, &all->t_spr.line_length,
		&all->t_spr.endian);
}

void	set_text_sprite_two(t_all *all, char *path)
{
	all->t_spr2.img != NULL ? ft_error("Дубликат 2 SPRITE текстуры", all) : 0;
	all->t_spr2.img = mlx_xpm_file_to_image(all->mlx.mlx, path,
		&all->t_spr2.img_w, &all->t_spr2.img_h);
	all->t_spr2.img == NULL ?
		ft_error("Ошибка открытия файла SPRITE текстуры", all) : 0;
	all->t_spr2.addr = mlx_get_data_addr(all->t_spr2.img,
		&all->t_spr2.bpp, &all->t_spr2.line_length,
		&all->t_spr2.endian);
}

void	parser_sprites(t_all *all)
{
	int	x;
	int	y;
	int i;

	i = -1;
	y = -1;
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			if (all->map[y][x] == '2' || all->map[y][x] == '3'
				|| all->map[y][x] == '4')
			{
				all->sprs[++i].x = (double)x + 0.5;
				all->sprs[i].y = (double)y + 0.5;
				all->sprs[i].num = all->map[y][x];
			}
		}
	}
}
