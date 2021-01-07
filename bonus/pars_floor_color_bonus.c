/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_floor_color_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:23:00 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 22:06:02 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	pars_floor(char **str, t_all *all)
{
	if (ft_split_size(str) == 2)
	{
		all->size_param++;
		all->t_f.img != NULL ? ft_error("Дубликат F текстуры", all) : 0;
		all->t_f.img = mlx_xpm_file_to_image(all->mlx.mlx,
			all->t_f.path = ft_strdup(str[1]),
			&all->t_f.img_w, &all->t_f.img_h);
		all->t_f.img == NULL ?
			ft_error("Ошибка открытия файла F текстуры", all) : 0;
		all->t_f.addr = mlx_get_data_addr(all->t_f.img, &all->t_f.bpp,
			&all->t_f.line_length, &all->t_f.endian);
	}
}
