/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:21:29 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/03 21:30:22 by ksharee          ###   ########.fr       */
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
	free(all->text_no.img_path);
	free(all->text_so.img_path);
	free(all->text_we.img_path);
	free(all->text_ea.img_path);
	mlx_destroy_window(all->mlx.mlx, all->mlx.win);
	free(all->mlx.mlx);
	//free(all->sprite.img_path);
}

void	free_map(t_all *all)
{
	while (all->size_map)
		free(all->map[--all->size_map]);
	free(all->map);
}
