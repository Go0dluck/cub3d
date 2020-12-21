#include "cub3d.h"

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
}

void 	parser_file(int fd, t_all *all)
{
	t_list	*head;
	char	*line;

	head = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head), all);
	ft_lstclear(&head, free);
}