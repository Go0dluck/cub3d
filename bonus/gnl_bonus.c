/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:22:15 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/08 19:23:56 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int		ft_free_ostatok(char **ostatok)
{
	if (*ostatok != NULL)
	{
		free(*ostatok);
		*ostatok = NULL;
	}
	return (-1);
}

int		ft_check_zero(char **ostatok, char **line)
{
	if (ft_strchr(*ostatok, '\0'))
	{
		if (!(*line = ft_strdup(*ostatok)))
			return (-1);
		free(*ostatok);
		*ostatok = NULL;
	}
	return (0);
}

int		ft_check_ostatok(char **ostatok, char **line)
{
	char	*tmp;
	char	*tmp1;

	if (!*ostatok)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
	{
		if ((tmp = ft_strchr(*ostatok, '\n')))
		{
			*tmp = '\0';
			if (!(*line = ft_strdup(*ostatok)))
				return (-1);
			if (!(tmp1 = ft_strdup(tmp + 1)))
				return (-1);
			free(*ostatok);
			*ostatok = tmp1;
			return (1);
		}
	}
	return (ft_check_zero(&*ostatok, &*line));
}

int		get_next_line(int fd, char **line)
{
	static char	*ostatok[1024];
	char		*buf;
	char		*tmp;
	int			buf_read;

	buf = NULL;
	if ((read(fd, buf, 0) < 0) && ostatok[fd])
		free(ostatok[fd]);
	if (fd < 0 || fd > 1024 || !line || BUFFER_SIZE <= 0 ||
	(read(fd, buf, 0) < 0) || !(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!ostatok[fd])
		ostatok[fd] = ft_strdup("");
	while ((buf_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[buf_read] = '\0';
		tmp = ft_strjoin(ostatok[fd], buf);
		free(ostatok[fd]);
		ostatok[fd] = tmp;
		if (ft_strchr(ostatok[fd], '\n'))
			break ;
	}
	free(buf);
	return (buf_read < 0 ? ft_free_ostatok(&ostatok[fd]) :
	ft_check_ostatok(&ostatok[fd], &*line));
}
