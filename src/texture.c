/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 08:58:21 by ksharee           #+#    #+#             */
/*   Updated: 2020/12/22 09:42:10 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	texture(t_all *all)
{
	int i = 0;
	all->text.texture = ft_calloc(8, sizeof(unsigned int *));
	while (i < 8)
	{
		all->text.texture[i] = ft_calloc(all->text.texHeight * all->text.texWidth, sizeof(unsigned int));
		i++;
	}
	for(int x = 0; x < all->text.texWidth; x++)
	{
		for(int y = 0; y < all->text.texHeight; y++)
		{
			int xorcolor = (x * 256 / all->text.texWidth) ^ (y * 256 / all->text.texHeight);
			int ycolor = y * 256 / all->text.texHeight;
			int xycolor = y * 128 / all->text.texHeight + x * 128 / all->text.texWidth;
			all->text.texture[0][all->text.texWidth * y + x] = 65536 * 254 * (x != y && x != all->text.texWidth - y);
			all->text.texture[1][all->text.texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor;
			all->text.texture[2][all->text.texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			all->text.texture[3][all->text.texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			all->text.texture[4][all->text.texWidth * y + x] = 256 * xorcolor; //xor green
			all->text.texture[5][all->text.texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			all->text.texture[6][all->text.texWidth * y + x] = 65536 * ycolor; //red gradient
			all->text.texture[7][all->text.texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
		}
	}

}
