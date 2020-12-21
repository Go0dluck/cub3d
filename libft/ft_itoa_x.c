/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:56:58 by ksharee           #+#    #+#             */
/*   Updated: 2020/12/02 10:27:14 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_x(unsigned int num)
{
	unsigned long	tmp_num;
	int				size;
	char			*str;

	size = 0;
	num == 0 ? size++ : 0;
	tmp_num = num;
	while (tmp_num)
	{
		tmp_num /= 16;
		size++;
	}
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size)
	{
		if (num % 16 >= 10)
			str[size - 1] = (num % 16) - 10 + 'A';
		else
			str[size - 1] = (num % 16) + '0';
		num /= 16;
		size--;
	}
	return (str);
}
