/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_floor_color_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:23:00 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 14:06:56 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	check_color_floor(t_all *all)
{
	all->col_f.r < 0 || all->col_f.r > 255 || all->col_f.g < 0 ||
		all->col_f.g > 255 || all->col_f.b < 0 || all->col_f.b > 255 ?
		ft_error("Не верные цвета пола", all) : 0;
}

void	pars_floor_next(char **str, t_all *all, int size)
{
	int		i;
	int		ii;
	int		iii;
	char	**color;

	i = 0;
	iii = 0;
	while (++i < size)
	{
		ft_isnum_comma(str[i]) ?
			ft_error("Не верный формат RGB цвета пола", all) : 0;
		color = ft_split(str[i], ',');
		ii = -1;
		while (++ii < ft_split_size(color))
		{
			iii == 0 ? all->col_f.r = ft_atoi(color[ii]) : 0;
			iii == 1 ? all->col_f.g = ft_atoi(color[ii]) : 0;
			iii == 2 ? all->col_f.b = ft_atoi(color[ii]) : 0;
			iii++;
		}
		free_split(color);
	}
	check_color_floor(all);
}

void	pars_floor(char **str, t_all *all)
{
	int		size;

	all->col_f.kol > 0 ? ft_error("Дубликат цвета пола", all) : 0;
	all->col_f.kol++;
	all->size_param++;
	size = ft_split_size(str);
	size > 6 ? ft_error("Не верные параметры цвета пола", all) : 0;
	pars_floor_next(str, all, size);
}
