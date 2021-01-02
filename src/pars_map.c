/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 09:41:23 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/01 23:32:37 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	make_map(t_list **head, int size, t_all *all)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = *head;
	all->map = ft_calloc(size + 1, sizeof(char *));
	while (tmp)
	{
		all->map[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	all->size_map = size;
	parser_player(all);
}

void 	parser_file_map(int fd, t_all *all)
{
	t_list	*head;
	char	*line;

	head = NULL;
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\n' || line[0] == '\0')
			continue ;
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head), all);
	ft_lstclear(&head, free);
}
