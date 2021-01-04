/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:25:27 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/03 23:14:45 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_text_sprite(t_all *all, char *path)
{
	all->sprite.img = mlx_xpm_file_to_image(all->mlx.mlx, path, &all->sprite.img_w, &all->sprite.img_h);
	all->sprite.img == NULL ? ft_error("Ошибка открытия файла SPRITE текстуры") : 0;
	all->sprite.addr = mlx_get_data_addr(all->sprite.img, &all->sprite.bits_per_pixel,
		&all->sprite.line_length, &all->sprite.endian);
}

void	set_text_no(t_all *all, char *path)
{
	all->text_no.img = mlx_xpm_file_to_image(all->mlx.mlx, path, &all->text_no.img_w, &all->text_no.img_h);
	all->text_no.img == NULL ? ft_error("Ошибка открытия файла NO текстуры") : 0;
	all->text_no.addr = mlx_get_data_addr(all->text_no.img, &all->text_no.bits_per_pixel,
		&all->text_no.line_length, &all->text_no.endian);
}

void	set_text_so(t_all *all, char *path)
{
	all->text_so.img = mlx_xpm_file_to_image(all->mlx.mlx, path, &all->text_so.img_w, &all->text_so.img_h);
	all->text_so.img == NULL ? ft_error("Ошибка открытия файла SO текстуры") : 0;
	all->text_so.addr = mlx_get_data_addr(all->text_so.img, &all->text_so.bits_per_pixel,
		&all->text_so.line_length, &all->text_so.endian);
}

void	set_text_we(t_all *all, char *path)
{
	all->text_we.img = mlx_xpm_file_to_image(all->mlx.mlx, path, &all->text_we.img_w, &all->text_we.img_h);
	all->text_we.img == NULL ? ft_error("Ошибка открытия файла WE текстуры") : 0;
	all->text_we.addr = mlx_get_data_addr(all->text_we.img, &all->text_we.bits_per_pixel,
		&all->text_we.line_length, &all->text_we.endian);
}

void	set_text_ea(t_all *all, char *path)
{
	all->text_ea.img = mlx_xpm_file_to_image(all->mlx.mlx, path, &all->text_ea.img_w, &all->text_ea.img_h);
	all->text_ea.img == NULL ? ft_error("Ошибка открытия файла EA текстуры") : 0;
	all->text_ea.addr = mlx_get_data_addr(all->text_ea.img, &all->text_ea.bits_per_pixel,
		&all->text_ea.line_length, &all->text_ea.endian);
}

void	pars_texture_path(char **str, t_all *all)
{
	all->text_set.texWidth = 64;
	all->text_set.texHeight = 64;
	if (ft_split_size(str) == 2)
	{
		all->size_param++;
		if (ft_strcmp(str[0], "NO") == 0)
			set_text_no(all, all->text_no.img_path = ft_strdup(str[1]));
		else if (ft_strcmp(str[0], "SO") == 0)
			set_text_so(all, all->text_so.img_path = ft_strdup(str[1]));
		else if (ft_strcmp(str[0], "WE") == 0)
			set_text_we(all, all->text_we.img_path = ft_strdup(str[1]));
		else if (ft_strcmp(str[0], "EA") == 0)
			set_text_ea(all, all->text_ea.img_path = ft_strdup(str[1]));
		else if (ft_strcmp(str[0], "S") == 0)
			set_text_sprite(all, all->sprite.img_path = ft_strdup(str[1]));
	}
	else
		ft_error("Не верные параметры текстур");
}
