/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:57:27 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/05 20:33:31 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	data_to_bitmap(t_all *all, int fd)
{
	int i;

	i = all->mlx.w * all->mlx.h - 1;
	while (i >= 0)
	{
		write(fd, &all->mlx.addr[i * all->mlx.bits_per_pixel / 8], 4);
		i--;
	}
}

static void	mir_verti_pixel(t_all *all, int line_cnt, int *e, int f)
{
	char	save;
	int		k;

	k = 3;
	while (k >= 0)
	{
		save = all->mlx.addr[*e + (line_cnt * all->mlx.line_length)];
		all->mlx.addr[*e + (line_cnt * all->mlx.line_length)] =
			all->mlx.addr[f - k + (line_cnt * all->mlx.line_length - 1)];
		all->mlx.addr[f - k + (line_cnt * all->mlx.line_length - 1)] =
			save;
		k--;
		*e = *e + 1;
	}
}

void		mir_verti(t_all *all)
{
	int		line_cnt;
	int		e;
	int		f;

	line_cnt = 0;
	while (line_cnt < all->mlx.h)
	{
		e = 0;
		f = all->mlx.line_length;
		while (e < f && e != f)
		{
			mir_verti_pixel(all, line_cnt, &e, f);
			f -= 4;
		}
		line_cnt++;
	}
}

void		bitmap_info_header(t_all *all, int fd)
{
	int header_info_size;
	int plane_nbr;
	int o_count;

	header_info_size = 40;
	plane_nbr = 1;
	write(fd, &header_info_size, 4);
	write(fd, &all->mlx.w, 4);
	write(fd, &all->mlx.h, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &all->mlx.bits_per_pixel, 2);
	o_count = 0;
	while (o_count < 28)
	{
		write(fd, "\0", 1);
		o_count++;
	}
}

void		save_bitmap(t_all *all)
{
	int	fd;
	int file_size;
	int first_pix;

	fd = open("bitmap.bmp", O_CREAT | O_RDWR);
	file_size = 14 + 40 + 4 + (all->mlx.w * all->mlx.h) * 4;
	first_pix = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	bitmap_info_header(all, fd);
	mir_verti(all);
	data_to_bitmap(all, fd);
	close(fd);
}
