/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:18:52 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/05 22:25:48 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	pars_resolution(char **str, t_all *all)
{
	all->mlx.w != 0 ? ft_error("Error\nДубликат размера окна") : 0;
	if (ft_split_size(str) == 3)
	{
		all->size_param++;
		all->mlx.w = ft_atoi(str[1]);
		all->mlx.w <= 0 || all->mlx.w > 1920 ? all->mlx.w = 1920 : 0;
		all->mlx.h = ft_atoi(str[2]);
		all->mlx.h <= 0 || all->mlx.h > 1080 ? all->mlx.h = 1080 : 0;
	}
	else
		ft_error("Error\nНе верные параметры экрана");
}
