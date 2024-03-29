/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:47:25 by ksharee           #+#    #+#             */
/*   Updated: 2020/11/04 16:17:37 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (count);
}

static int	ft_countchar(const char *s, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i++])
		len++;
	return (len);
}

static char	**ft_free(char **ptr, int p_i)
{
	while (p_i > 0)
	{
		p_i--;
		free(ptr[p_i]);
	}
	free(ptr);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		p_i;
	int		p_k;

	i = 0;
	p_i = 0;
	if (!s || !(ptr = (char **)malloc(sizeof(char *)
	* (ft_countword((char *)s, c) + 1))))
		return (NULL);
	while (p_i < ft_countword(s, c))
	{
		p_k = 0;
		if (!(ptr[p_i] = (char *)malloc(ft_countchar((char *)&s[i], c)
		* sizeof(char) + 1)))
			return (ft_free(ptr, p_i));
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			ptr[p_i][p_k++] = s[i++];
		ptr[p_i][p_k] = '\0';
		p_i++;
	}
	ptr[p_i] = NULL;
	return (ptr);
}
