/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:41:27 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/04 00:08:03 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_spritenew(t_all *all)
{
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
		return (NULL);
	new->next = NULL;
	new->x = all->ray.mapX;
	new->y = all->ray.mapY;
}
