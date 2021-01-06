/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 09:41:23 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/06 09:56:53 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_full_map(char *str_map, int y, t_all *all)
{
	int	i;

	i = 0;
	while (str_map[i])
	{
		if (str_map[i] == '0')
			if (all->map[y - 1][i] == ' ' || all->map[y + 1][i] == ' ')
				ft_error("Error\nКарта не закрыта");
		i++;
	}
}

void	check_map(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	x = -1;
	while (all->map[0][++x])
		all->map[0][x] != '1' && all->map[0][x] != ' ' ?
			ft_error("Error\nОшибка первой строки карты") : 0;
	x = -1;
	while (all->map[all->size_map - 1][++x])
		all->map[all->size_map - 1][x] != '1' &&
		all->map[all->size_map - 1][x] != ' ' ?
		ft_error("Error\nОшибка последней строки карты") : 0;
	while (++y < all->size_map - 1)
	{
		check_line_map(all->map[y]);
		check_full_map(all->map[y], y, all);
	}
}

void	make_map(t_list **head, int size, t_all *all)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = *head;
	size < 3 ? ft_error("Error\nОшибка строк карты") : 0;
	if (!(all->map = ft_calloc(size + 1, sizeof(char *))))
		ft_error("Error\nОшибка malloc карты");
	while (tmp)
	{
		all->map[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	all->size_map = size;
	check_map(all);
	parser_player(all);
	parser_sprites(all);
}

void	add_struct_map(t_all *all, int fd, char *line)
{
	int		start_map;
	t_list	*head;

	head = NULL;
	start_map = 1;
	ft_lstadd_back(&head, ft_lstnew(line));
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
		{
			start_map = 2;
			continue ;
		}
		start_map == 2 ? ft_error("Error\nОшибка карты") :
			ft_lstadd_back(&head, ft_lstnew(line));
	}
	line[0] != '\0' ? ft_lstadd_back(&head, ft_lstnew(line)) : 0;
	free(line);
	make_map(&head, ft_lstsize(head), all);
	ft_lstclear(&head, free);
}

void	parser_file_map(int fd, t_all *all)
{
	char	*line;
	int		otv;

	otv = 0;
	line = NULL;
	otv = get_next_line(fd, &line);
	while (line[0] == '\0' && otv == 1)
		otv = get_next_line(fd, &line);
	line == NULL || otv == 0 ? ft_error("Error\nОтсутствует карта в файле") : 0;
	add_struct_map(all, fd, line);
}
