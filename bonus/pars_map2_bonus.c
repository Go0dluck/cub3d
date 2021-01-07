/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:07:11 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/07 00:28:09 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	check_char_map(char **str, int i, int ii, t_all *all)
{
	while (str[i][++ii])
	{
		if (str[i][ii] != ' ' && str[i][ii] != '1' &&
			str[i][ii] != '0' && str[i][ii] != '2' &&
			str[i][ii] != 'S' && str[i][ii] != 'N' &&
			str[i][ii] != 'W' && str[i][ii] != 'E' &&
			str[i][ii] != '3')
		{
			free_split(str);
			ft_error("Не допустимые символы в карте", all);
		}
	}
}

void	check_line_map(char *str_map, t_all *all)
{
	char	**str;
	int		i;
	int		ii;

	ii = -1;
	i = -1;
	str = ft_split(str_map, ' ');
	while (str[++i])
	{
		if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
		{
			free_split(str);
			ft_error("Карта не закрыта", all);
		}
		ii = -1;
		check_char_map(str, i, ii, all);
	}
	free_split(str);
}
