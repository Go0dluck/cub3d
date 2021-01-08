/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:19:35 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/08 18:55:41 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	pars_bonus(t_all *all)
{
	all->t_life.img = mlx_xpm_file_to_image(all->mlx.mlx,
		"./pics/lifebar.xpm", &all->t_life.img_w, &all->t_life.img_h);
	all->t_life.addr = mlx_get_data_addr(all->t_life.img,
		&all->t_life.bpp, &all->t_life.line_length, &all->t_life.endian);
	all->t_gun.img = mlx_xpm_file_to_image(all->mlx.mlx,
		"./pics/gun.xpm", &all->t_gun.img_w, &all->t_gun.img_h);
	all->t_gun.addr = mlx_get_data_addr(all->t_gun.img,
		&all->t_gun.bpp, &all->t_gun.line_length, &all->t_gun.endian);
	all->t_blast.img = mlx_xpm_file_to_image(all->mlx.mlx,
		"./pics/blast.xpm", &all->t_blast.img_w, &all->t_blast.img_h);
	all->t_blast.addr = mlx_get_data_addr(all->t_blast.img,
		&all->t_blast.bpp, &all->t_blast.line_length, &all->t_blast.endian);
	all->t_spr_bad.img = mlx_xpm_file_to_image(all->mlx.mlx,
		"./pics/freddy.xpm", &all->t_spr_bad.img_w, &all->t_spr_bad.img_h);
	all->t_spr_bad.addr = mlx_get_data_addr(all->t_spr_bad.img,
		&all->t_spr_bad.bpp, &all->t_spr_bad.line_length,
		&all->t_spr_bad.endian);
}

void	parser_file_char(t_all *all, char **str)
{
	ft_strcmp(str[0], "R") == 0 ? pars_resolution(str, all) : 0;
	ft_strcmp(str[0], "F") == 0 ? pars_floor(str, all) : 0;
	ft_strcmp(str[0], "C") == 0 ? pars_ceilling(str, all) : 0;
	ft_strcmp(str[0], "NO") == 0 || ft_strcmp(str[0], "SO") == 0 ||
		ft_strcmp(str[0], "WE") == 0 || ft_strcmp(str[0], "EA") == 0 ||
		ft_strcmp(str[0], "S") == 0 || ft_strcmp(str[0], "S2") == 0 ?
			pars_texture_path(str, all) : 0;
}

void	parser_file(int fd, t_all *all)
{
	char	*line;
	char	**str;
	int		gnl;

	while (all->size_param != 9)
	{
		if ((gnl = get_next_line(fd, &line)) <= 0)
		{
			free(line);
			ft_error("Не верное количество параметров", all);
		}
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			continue ;
		}
		str = ft_split(line, ' ');
		free(line);
		parser_file_char(all, str);
		free_split(str);
	}
	pars_bonus(all);
	parser_file_map(fd, all);
}
