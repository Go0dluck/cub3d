/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_sprites_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:09:49 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/09 16:15:29 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	del_sprites(t_all *all)
{
	t_sprite	*tmp;
	int			new_size;

	new_size = all->size_sprite;
	if (new_size > 0)
	{
		tmp = malloc(sizeof(t_sprite) * new_size - 1);
		while (new_size)
		{
			tmp[new_size - 1] = all->sprs[new_size - 1];
			new_size--;
		}
		all->sprs[all->size_sprite - 1].num == '3' ? all->heart_size-- : 0;
		all->sprs[all->size_sprite - 1].num == '2' ? all->heart_size++ : 0;
		if (all->sprs[all->size_sprite - 1].num == '4')
			all->map[(int)all->sprs[all->size_sprite - 1].y]
			[(int)all->sprs[all->size_sprite - 1].x] = '0';
		all->size_sprite--;
		free(all->sprs);
		all->sprs = tmp;
		all->heart_size == 0 ? draw_dead(all) : 0;
	}
}

void	del_sprites_gomer(t_all *all)
{
	t_sprite	*tmp;
	int			new_size;

	new_size = all->size_sprite;
	if (all->sprs[all->size_sprite - 1].num == '4')
	{
		if (new_size > 0)
		{
			tmp = malloc(sizeof(t_sprite) * new_size - 1);
			while (new_size)
			{
				tmp[new_size - 1] = all->sprs[new_size - 1];
				new_size--;
			}
			all->map[(int)all->sprs[all->size_sprite - 1].y]
				[(int)all->sprs[all->size_sprite - 1].x] = '0';
			all->size_sprite--;
			free(all->sprs);
			all->sprs = tmp;
		}
	}
}
