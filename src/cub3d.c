/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:40:52 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/06 09:55:47 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	struct_init(t_all *all)
{
	all->save = 0;
	all->t_s.t_w = 64;
	all->t_s.t_h = 64;
	all->spr_s.s_w = 64;
	all->spr_s.s_h = 64;
	all->size_param = 0;
	all->size_sprite = 0;
	all->mlx.w = 0;
	all->mlx.h = 0;
	all->col_f.kol = 0;
	all->col_c.kol = 0;
	all->t_ea.img = NULL;
	all->t_no.img = NULL;
	all->t_so.img = NULL;
	all->t_we.img = NULL;
	all->t_spr.img = NULL;
}

void	check_save(char *file, char *str, t_all *all)
{
	if (!(ft_strnstr(file, str, ft_strlen(file))))
		ft_error("Error\nНе верный параметр save");
	all->save = 1;
}

char	*check_name(char *file, char *str)
{
	if (!(ft_strnstr(file, str, ft_strlen(file))))
		ft_error("Error\nНе правильное имя файла карты");
	return (file);
}

void	ft_init(t_all *all, char *agrv, int save)
{
	int	fd;

	if ((fd = open(agrv, O_RDONLY)) <= 0)
		ft_error("Error\nНе возможно открыть файл");
	(all->mlx.mlx = mlx_init()) == NULL ?
		ft_error("Error\nОшибка mlx init") : 0;
	parser_file(fd, all);
	close(fd);
	(all->mlx.win = mlx_new_window(all->mlx.mlx, all->mlx.w,
		all->mlx.h, "CUB3D")) == NULL ? ft_error("Error\nОшибка mlx win") : 0;
	raycast(all);
	if (save == 1)
	{
		save_bitmap(all);
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

	agrc == 1 ? ft_error("Error\nОтсутствует файл карты") : 0;
	struct_init(&all);
	if (agrc == 2)
		ft_init(&all, check_name(agrv[1], ".cub"), 0);
	if (agrc == 3)
	{
		check_save(agrv[2], "--save", &all);
		ft_init(&all, check_name(agrv[1], ".cub"), 1);
	}
	agrc > 3 ? ft_error("Error\nМного параметров") : 0;
}
