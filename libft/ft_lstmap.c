/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:28:33 by ksharee           #+#    #+#             */
/*   Updated: 2020/11/03 13:48:37 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_elem;
	t_list *begin_elem;

	if (lst == NULL)
		return (NULL);
	if (!(new_elem = ft_lstnew(f(lst->content))))
		return (NULL);
	begin_elem = new_elem;
	lst = lst->next;
	while (lst)
	{
		if (!(new_elem = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&begin_elem, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&begin_elem, new_elem);
	}
	return (begin_elem);
}
