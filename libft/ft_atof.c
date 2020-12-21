/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:21:57 by ksharee           #+#    #+#             */
/*   Updated: 2020/11/30 12:07:40 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(char *str)
{
	float	num_f;
	float	num_i;
	int		i;

	i = 0;
	num_i = (float)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	num_f = (float)ft_atoi(str);
	i = ft_strlen(str);
	while (i--)
		num_f /= 10;
	if (num_i < 0)
		num_f *= -1;
	return (num_i + num_f);
}
