/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 22:45:09 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/08 18:33:40 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int				create_rgb_f(t_all *all)
{
	return (all->col_f.r << 16 | all->col_f.g << 8 | all->col_f.b);
}

int				create_rgb_c(t_all *all)
{
	return (all->col_c.r << 16 | all->col_c.g << 8 | all->col_c.b);
}

unsigned int	shade_color(unsigned int color, float dist)
{
	unsigned int	i;

	if (dist <= 1)
		return (color);
	i = ((int)(((0xFF0000 & color) >> 16) / dist) << 16) +
		((int)(((0x00FF00 & color) >> 8) / dist) << 8) +
		((int)((0x0000FF & color) / dist));
	return (i);
}
