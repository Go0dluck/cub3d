/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_ceilling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:24:10 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/06 19:25:01 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	pars_color_ceilling(t_all *all, char **color)
{
	all->col_c.r = ft_atoi(color[0]);
	all->col_c.r < 0 ? all->col_c.r = 0 : 0;
	all->col_c.r > 255 ? all->col_c.r = 255 : 0;
	all->col_c.g = ft_atoi(color[1]);
	all->col_c.g < 0 ? all->col_c.g = 0 : 0;
	all->col_c.g > 255 ? all->col_c.g = 255 : 0;
	all->col_c.b = ft_atoi(color[2]);
	all->col_c.b < 0 ? all->col_c.b = 0 : 0;
	all->col_c.b > 255 ? all->col_c.b = 255 : 0;
}

void	pars_ceilling(char **str, t_all *all)
{
	char **color;

	all->col_c.kol > 0 ? ft_error("Дубликат цвета потолка", all) : 0;
	if (ft_split_size(str) == 2)
	{
		if (ft_split_size(color = ft_split(str[1], ',')) == 3)
		{
			all->col_c.kol++;
			all->size_param++;
			if (ft_isnum(color[0]) || ft_isnum(color[1]) || ft_isnum(color[2]))
			{
				free_split(color);
				ft_error("Не верный формат RGB цвета потолка", all);
			}
			pars_color_ceilling(all, color);
			free_split(color);
		}
		else
			ft_error("Не верный формат RGB цвета потолка", all);
	}
	else
		ft_error("Не верные параметры цвета потолка", all);
}
