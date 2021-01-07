/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:50:25 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/06 23:16:08 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_putpixel(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->mlx.addr + (y * all->mlx.line_length + x *
		(all->mlx.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
