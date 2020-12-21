/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:18:32 by ksharee           #+#    #+#             */
/*   Updated: 2020/12/21 22:36:47 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*ptr;
	size_t	size_all;

	size_all = count * size;
	if (!(ptr = (size_t *)malloc(size_all)))
		return (NULL);
	ft_memset(ptr, 0, size_all);
	return (ptr);
}
