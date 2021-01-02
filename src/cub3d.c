/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:40:52 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/02 12:48:14 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*check_name(char *file)
{
	if (!(ft_strnstr(file, ".cub", ft_strlen(file))))
		ft_error("Не правильное имя файла");
	return (file);
}

int main(int agrc, char **agrv)
{
	int 	fd;
	t_all	all;

	if (agrc == 2)
	{
		if ((fd = open(check_name(agrv[1]), O_RDONLY)) <= 0)
			ft_error("Не возможно открыть файл");
		(all.mlx.mlx = mlx_init()) == NULL ? ft_error("Ошибка mlx init") : 0;
		parser_file(fd, &all);
		close(fd);
		(all.mlx.win = mlx_new_window(all.mlx.mlx, all.mlx.w, all.mlx.h, "CUB3D")) == NULL ? ft_error("Ошибка mlx win") : 0;
		raycast(&all);
		mlx_hook(all.mlx.win, 2, 1L<<0, ft_hook, &all);
		mlx_loop(all.mlx.mlx);
	}
	ft_error("Отсутствует файл карты");
	return 0;
}
