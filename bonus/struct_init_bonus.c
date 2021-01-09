/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:52:16 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/09 14:06:36 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	struct_init_next2(t_all *all)
{
	all->t_no.path = NULL;
	all->t_c.path = NULL;
	all->t_f.path = NULL;
	all->t_so.path = NULL;
	all->t_we.path = NULL;
	all->t_ea.path = NULL;
	all->t_spr.path = NULL;
	all->t_spr2.path = NULL;
	all->t_spr_bad.path = NULL;
	all->death = false;
}

void	struct_init_next(t_all *all)
{
	all->t_ea.img = NULL;
	all->t_no.img = NULL;
	all->t_so.img = NULL;
	all->t_we.img = NULL;
	all->t_spr.img = NULL;
	all->t_spr_bad.img = NULL;
	all->t_c.img = NULL;
	all->t_f.img = NULL;
	all->t_life.img = NULL;
	all->t_gun.img = NULL;
	all->t_blast.img = NULL;
	all->t_spr_bad.img = NULL;
	all->t_spr2.img = NULL;
	all->dead.img = NULL;
	all->sprs = NULL;
	all->sprs_bad = NULL;
	all->map = NULL;
	struct_init_next2(all);
}

void	struct_init(t_all *all)
{
	all->save = 0;
	all->heart_size = 5;
	all->t_s.t_w = 64;
	all->t_s.t_h = 64;
	all->spr_s.s_w = 64;
	all->spr_s.s_h = 64;
	all->sprbad_s.s_w = 128;
	all->sprbad_s.s_h = 128;
	all->death_s.s_w = 500;
	all->death_s.s_h = 200;
	all->life_s.t_w = 64;
	all->life_s.t_h = 64;
	all->gun_s.t_w = 250;
	all->gun_s.t_h = 250;
	all->blast_s.t_w = 100;
	all->blast_s.t_h = 100;
	all->blast = 0;
	all->size_param = 0;
	all->size_sprite = 0;
	all->mlx.w = 0;
	all->mlx.h = 0;
	all->col_f.kol = 0;
	all->col_c.kol = 0;
	all->ray.pitch = 0;
	struct_init_next(all);
}
