/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:40:52 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 21:40:16 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	struct_init(t_all *all)
{
	all->save = 0;
	all->t_s.t_w = 64;
	all->t_s.t_h = 64;
	all->spr_s.s_w = 64;
	all->spr_s.s_h = 64;
	all->sprbad_s.s_w = 128;
	all->sprbad_s.s_h = 128;
	all->life_s.t_w = 270;
	all->life_s.t_h = 120;
	all->gun_s.t_w = 250;
	all->gun_s.t_h = 250;
	all->blast_s.t_w = 100;
	all->blast_s.t_h = 100;
	all->blast = 0;
	all->size_param = 0;
	all->size_sprite = 0;
	all->size_sprite_bad = 0;
	all->mlx.w = 0;
	all->mlx.h = 0;
	all->col_f.kol = 0;
	all->col_c.kol = 0;
	all->t_ea.img = NULL;
	all->t_no.img = NULL;
	all->t_so.img = NULL;
	all->t_we.img = NULL;
	all->t_spr.img = NULL;
	all->t_spr_bad.img = NULL;
	all->t_c.img = NULL;
	all->t_f.img = NULL;
	all->t_life.img = NULL;
	all->t_gun.img = NULL;
	all->t_blast.img = NULL;
	all->t_spr_bad.img = NULL;
	all->t_spr2.img = NULL;
	all->t_no.path = NULL;
	all->t_c.path = NULL;
	all->t_f.path = NULL;
	all->t_so.path = NULL;
	all->t_we.path = NULL;
	all->t_ea.path = NULL;
	all->t_spr.path = NULL;
	all->t_spr2.path = NULL;
	all->t_spr_bad.path = NULL;
	all->sprs = NULL;
	all->sprs_bad = NULL;
	all->map = NULL;
}

void	check_save(char *file, t_all *all)
{
	int	size;

	size = ft_strlen(file);
	if (size == 6)
	{
		if (!(file[size - 1] == 'e' && file[size - 2] == 'v' &&
			file[size - 3] == 'a' && file[size - 4] == 's' &&
			file[size - 5] == '-' && file[size - 6] == '-'))
			ft_error("Не правильное SAVE параметра", all);
		all->save = 1;
	}
	else
		ft_error("Не правильное SAVE параметра", all);
}

char	*check_name(char *file, t_all *all)
{
	int size;

	size = ft_strlen(file);
	if (size > 4)
	{
		if (!(file[size - 1] == 'b' && file[size - 2] == 'u' &&
			file[size - 3] == 'c' && file[size - 4] == '.'))
			ft_error("Не правильное имя файла карты", all);
		return (file);
	}
	ft_error("Не правильное имя файла карты", all);
	return (NULL);
}

void	ft_init(t_all *all, char *agrv, int save)
{
	int	fd;

	if ((fd = open(agrv, O_RDONLY)) <= 0)
		ft_error("Не возможно открыть файл", all);
	(all->mlx.mlx = mlx_init()) == NULL ?
		ft_error("Ошибка mlx init", all) : 0;
	parser_file(fd, all);
	close(fd);
	(all->mlx.win = mlx_new_window(all->mlx.mlx, all->mlx.w,
		all->mlx.h, "CUB3D")) == NULL ? ft_error("Ошибка mlx win", all) : 0;
	raycast(all);
	if (save == 1)
	{
		save_screen(all);
		return ;
	}
	if (save == 0)
	{
		mlx_hook(all->mlx.win, 2, 1L << 0, ft_hook, all);
		mlx_loop(all->mlx.mlx);
	}
}

int		main(int agrc, char **agrv)
{
	t_all	all;
	//int pid = -1;

	struct_init(&all);
	//pid = fork();
	//pid == 0 ? system("afplay ./bonus/sound/start.mp3") : 0;
	agrc == 1 ? ft_error("Отсутствует файл карты", &all) : 0;
	if (agrc == 2)
		ft_init(&all, check_name(agrv[1], &all), 0);
	if (agrc == 3)
	{
		check_save(agrv[2], &all);
		ft_init(&all, check_name(agrv[1], &all), 1);
	}
	agrc > 3 ? ft_error("Много параметров", &all) : 0;
	return (0);
}
