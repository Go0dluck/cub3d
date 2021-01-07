/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_text_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:25:27 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 18:43:15 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	set_text_no(t_all *all, char *path)
{
	all->t_no.img != NULL ? ft_error("Дубликат NO текстуры", all) : 0;
	all->t_no.img = mlx_xpm_file_to_image(all->mlx.mlx, path,
		&all->t_no.img_w, &all->t_no.img_h);
	all->t_no.img == NULL ?
		ft_error("Ошибка открытия файла NO текстуры", all) : 0;
	all->t_no.addr = mlx_get_data_addr(all->t_no.img, &all->t_no.bpp,
		&all->t_no.line_length, &all->t_no.endian);
}

void	set_text_so(t_all *all, char *path)
{
	all->t_so.img != NULL ? ft_error("Дубликат SO текстуры", all) : 0;
	all->t_so.img = mlx_xpm_file_to_image(all->mlx.mlx, path,
		&all->t_so.img_w, &all->t_so.img_h);
	all->t_so.img == NULL ?
		ft_error("Ошибка открытия файла SO текстуры", all) : 0;
	all->t_so.addr = mlx_get_data_addr(all->t_so.img, &all->t_so.bpp,
		&all->t_so.line_length, &all->t_so.endian);
}

void	set_text_we(t_all *all, char *path)
{
	all->t_we.img != NULL ? ft_error("Дубликат WE текстуры", all) : 0;
	all->t_we.img = mlx_xpm_file_to_image(all->mlx.mlx, path,
		&all->t_we.img_w, &all->t_we.img_h);
	all->t_we.img == NULL ?
		ft_error("Ошибка открытия файла WE текстуры", all) : 0;
	all->t_we.addr = mlx_get_data_addr(all->t_we.img, &all->t_we.bpp,
		&all->t_we.line_length, &all->t_we.endian);
}

void	set_text_ea(t_all *all, char *path)
{
	all->t_ea.img != NULL ? ft_error("Дубликат EA текстуры", all) : 0;
	all->t_ea.img = mlx_xpm_file_to_image(all->mlx.mlx, path,
		&all->t_ea.img_w, &all->t_ea.img_h);
	all->t_ea.img == NULL ?
		ft_error("Ошибка открытия файла EA текстуры", all) : 0;
	all->t_ea.addr = mlx_get_data_addr(all->t_ea.img, &all->t_ea.bpp,
		&all->t_ea.line_length, &all->t_ea.endian);
}

void	pars_texture_path(char **str, t_all *all)
{
	if (ft_split_size(str) == 2)
	{
		all->size_param++;
		if (ft_strcmp(str[0], "NO") == 0)
			set_text_no(all, all->t_no.path = ft_strdup(str[1]));
		else if (ft_strcmp(str[0], "SO") == 0)
			set_text_so(all, all->t_so.path = ft_strdup(str[1]));
		else if (ft_strcmp(str[0], "WE") == 0)
			set_text_we(all, all->t_we.path = ft_strdup(str[1]));
		else if (ft_strcmp(str[0], "EA") == 0)
			set_text_ea(all, all->t_ea.path = ft_strdup(str[1]));
		else if (ft_strcmp(str[0], "S") == 0)
			set_text_sprite(all, all->t_spr.path = ft_strdup(str[1]));
		else if (ft_strcmp(str[0], "S2") == 0)
			set_text_sprite_two(all, all->t_spr2.path = ft_strdup(str[1]));
	}
	else
		ft_error("Не верные параметры текстур", all);
}
