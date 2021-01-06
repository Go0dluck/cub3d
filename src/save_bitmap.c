/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:57:27 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/06 21:30:21 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_bmp(t_all *all)
{
	all->bmp.file_size = 54 + (all->mlx.w * all->mlx.h) * 4;
	all->bmp.unused = 0;
	all->bmp.offset = 54;
	all->bmp.header = 40;
	all->bmp.plane = 1;
	all->bmp.bpp = 32;
}

void	write_text(t_all *all, int fd)
{
	int	x;
	int	y;
	int	line;

	y = 0;
	while (y < all->mlx.h)
	{
		x = 0;
		line = all->mlx.w * (all->mlx.h - y);
		while (x < all->mlx.w)
		{
			write(fd, &all->mlx.addr[line * 4], 4);
			line++;
			x++;
		}
		y++;
	}
}

void	save_screen(t_all *all)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("screen.bmp", O_CREAT | O_RDWR);
	init_bmp(all);
	write(fd, "BM", 2);
	write(fd, &all->bmp.file_size, 4);
	write(fd, &all->bmp.unused, 4);
	write(fd, &all->bmp.offset, 4);
	write(fd, &all->bmp.header, 4);
	write(fd, &all->mlx.w, 4);
	write(fd, &all->mlx.h, 4);
	write(fd, &all->bmp.plane, 2);
	write(fd, &all->bmp.bpp, 2);
	while (i <= 6)
	{
		write(fd, &all->bmp.unused, 4);
		i++;
	}
	write_text(all, fd);
	close(fd);
}
