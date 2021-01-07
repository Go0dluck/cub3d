/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_ceilling_color_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:24:10 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 22:05:51 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	pars_ceilling(char **str, t_all *all)
{
	if (ft_split_size(str) == 2)
	{
		all->size_param++;
		all->t_c.img != NULL ? ft_error("Дубликат C текстуры", all) : 0;
		all->t_c.img = mlx_xpm_file_to_image(all->mlx.mlx,
			all->t_c.path = ft_strdup(str[1]),
			&all->t_c.img_w, &all->t_c.img_h);
		all->t_c.img == NULL ?
			ft_error("Ошибка открытия файла C текстуры", all) : 0;
		all->t_c.addr = mlx_get_data_addr(all->t_c.img, &all->t_c.bpp,
			&all->t_c.line_length, &all->t_c.endian);
	}
}
