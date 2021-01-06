/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 22:45:09 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/05 20:32:20 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		create_rgb_f(t_all *all)
{
	return (all->col_f.r << 16 | all->col_f.g << 8 | all->col_f.b);
}

int		create_rgb_c(t_all *all)
{
	return (all->col_c.r << 16 | all->col_c.g << 8 | all->col_c.b);
}
