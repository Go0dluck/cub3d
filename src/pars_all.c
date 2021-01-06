/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:19:35 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/06 18:19:00 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	parser_file_char(t_all *all, char **str)
{
	ft_strcmp(str[0], "R") == 0 ? pars_resolution(str, all) : 0;
	ft_strcmp(str[0], "F") == 0 ? pars_floor(str, all) : 0;
	ft_strcmp(str[0], "C") == 0 ? pars_ceilling(str, all) : 0;
	ft_strcmp(str[0], "NO") == 0 || ft_strcmp(str[0], "SO") == 0 ||
		ft_strcmp(str[0], "WE") == 0 || ft_strcmp(str[0], "EA") == 0 ||
		ft_strcmp(str[0], "S") == 0 ? pars_texture_path(str, all) : 0;
}

void	parser_file(int fd, t_all *all)
{
	char	*line;
	char	**str;
	int		gnl;

	while (all->size_param != 8)
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
	parser_file_map(fd, all);
}
