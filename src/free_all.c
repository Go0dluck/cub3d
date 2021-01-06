/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:21:29 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/05 21:02:33 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	free(all->sprs);
	mlx_destroy_image(all->mlx.mlx, all->t_spr.img);
	mlx_destroy_image(all->mlx.mlx, all->t_no.img);
	mlx_destroy_image(all->mlx.mlx, all->t_so.img);
	mlx_destroy_image(all->mlx.mlx, all->t_we.img);
	mlx_destroy_image(all->mlx.mlx, all->t_ea.img);
	mlx_destroy_window(all->mlx.mlx, all->mlx.win);
	free(all->mlx.mlx);
}

void	free_map(t_all *all)
{
	while (all->size_map)
		free(all->map[--all->size_map]);
	free(all->map);
}
