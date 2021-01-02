/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_floor_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:23:00 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/02 12:44:08 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	pars_floor(char **str, t_all *all)
{
	char **color;

	if (ft_split_size(str) == 2)
	{
		if (ft_split_size(color = ft_split(str[1], ',')) == 3)
		{
			all->size_param++;
			all->col_f.r = ft_atoi(color[0]);
			all->col_f.r < 0 ? all->col_f.r = 0 : 0;
			all->col_f.r > 255 ? all->col_f.r = 255 : 0;
			all->col_f.g = ft_atoi(color[1]);
			all->col_f.g < 0 ? all->col_f.g = 0 : 0;
			all->col_f.g > 255 ? all->col_f.g = 255 : 0;
			all->col_f.b = ft_atoi(color[2]);
			all->col_f.b < 0 ? all->col_f.b = 0 : 0;
			all->col_f.b > 255 ? all->col_f.b = 255 : 0;
			free_split(color);
		}
		else
			ft_error("Не верный формат RGB цвета пола");
	}
	else
		ft_error("Не верные параметры цвета пола");
}

