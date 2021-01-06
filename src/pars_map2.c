/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:07:11 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/06 10:19:18 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_char_map(char **str, int i, int ii)
{
	while (str[i][++ii])
	{
		if (str[i][ii] != ' ' && str[i][ii] != '1' &&
			str[i][ii] != '0' && str[i][ii] != '2' &&
			str[i][ii] != 'S' && str[i][ii] != 'N' &&
			str[i][ii] != 'W' && str[i][ii] != 'E')
		{
			free_split(str);
			ft_error("Error\nНе допустимые символы в карте");
		}
	}
}

void	check_line_map(char *str_map)
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
			ft_error("Error\nКарта не закрыта");
		}
		ii = -1;
		check_char_map(str, i, ii);
	}
	free_split(str);
}
