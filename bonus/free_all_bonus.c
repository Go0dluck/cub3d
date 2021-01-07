/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:21:29 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 22:02:38 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int		ft_split_size(char **str)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void	free_split(char **str)
{
	int size;

	size = ft_split_size(str);
	while (size)
	{
		free(str[--size]);
	}
	free(str);
}

void	free_struct(t_all *all)
{
	free(all->t_no.path);
	free(all->t_so.path);
	free(all->t_we.path);
	free(all->t_ea.path);
	free(all->t_spr.path);
	free(all->t_f.path);
	free(all->t_c.path);
	free(all->sprs);
	all->t_c.img != NULL ? mlx_destroy_image(all->mlx.mlx, all->t_c.img) : 0;
	all->t_spr.img != NULL ? mlx_destroy_image(all->mlx.mlx, all->t_spr.img)
		: 0;
	all->t_no.img != NULL ? mlx_destroy_image(all->mlx.mlx, all->t_no.img) : 0;
	all->t_so.img != NULL ? mlx_destroy_image(all->mlx.mlx, all->t_so.img) : 0;
	all->t_we.img != NULL ? mlx_destroy_image(all->mlx.mlx, all->t_we.img) : 0;
	all->t_ea.img != NULL ? mlx_destroy_image(all->mlx.mlx, all->t_ea.img) : 0;
	free(all->mlx.mlx);
}

void	free_map(t_all *all)
{
	if (all->map != NULL)
	{
		while (all->size_map)
			free(all->map[--all->size_map]);
		free(all->map);
	}
}
