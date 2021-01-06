/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:41:27 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/05 22:25:57 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_text_sprite(t_all *all, char *path)
{
	all->t_spr.img != NULL ? ft_error("Error\nДубликат SPRITE текстуры") : 0;
	all->t_spr.img = mlx_xpm_file_to_image(all->mlx.mlx, path,
		&all->t_spr.img_w, &all->t_spr.img_h);
	all->t_spr.img == NULL ?
		ft_error("Error\nОшибка открытия файла SPRITE текстуры") : 0;
	all->t_spr.addr = mlx_get_data_addr(all->t_spr.img,
		&all->t_spr.bpp, &all->t_spr.line_length,
		&all->t_spr.endian);
}

void	parser_sprites(t_all *all)
{
	int	x;
	int	y;
	int i;

	i = 0;
	y = 0;
	if (!(all->sprs = malloc(sizeof(t_sprite) * all->size_sprite)))
		ft_error("Error\nОшибка malloc спрайтов");
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '2')
			{
				all->sprs[i].x = (double)x + 0.5;
				all->sprs[i].y = (double)y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}
