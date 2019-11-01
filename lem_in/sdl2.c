/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:54:24 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 15:46:44 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static inline void	lem_in_sdl_888_2(t_way *lst, t_lem *m, int i)
{
	SDL_Rect	bg_st_tr;

	lst->param_ant[i].brez->deltax =
	abs(m->room[lst->index_ways[lst->param_ant[i].len_way - 1]].x
	- lst->param_ant[i].x);
	lst->param_ant[i].brez->deltay =
	abs(m->room[lst->index_ways[lst->param_ant[i].len_way - 1]].y
	- lst->param_ant[i].y);
	lst->param_ant[i].brez->signx =
	lst->param_ant[i].x
	< m->room[lst->index_ways[lst->param_ant[i].len_way - 1]].x ? 1 : -1;
	lst->param_ant[i].brez->signy =
	lst->param_ant[i].y
	< m->room[lst->index_ways[lst->param_ant[i].len_way - 1]].y ? 1 : -1;
	lst->param_ant[i].brez->error =
	lst->param_ant[i].brez->deltax - lst->param_ant[i].brez->deltay;
	bg_st_tr.w = 50;
	bg_st_tr.h = 50;
	bg_st_tr.x = lst->param_ant[i].x - bg_st_tr.w / 2;
	bg_st_tr.y = lst->param_ant[i].y - bg_st_tr.h / 2;
	SDL_RenderCopy(g_ren, g_flower, NULL, &bg_st_tr);
}

static inline void	lem_in_sdl_888_1(t_way *lst, t_lem *m, int i)
{
	SDL_Rect	bg_st_tr;

	move_ant(lst, i, m);
	bg_st_tr.w = 50;
	bg_st_tr.h = 50;
	bg_st_tr.x = lst->param_ant[i].x - bg_st_tr.w / 2;
	bg_st_tr.y = lst->param_ant[i].y - bg_st_tr.h / 2;
	SDL_RenderCopy(g_ren, g_flower, NULL, &bg_st_tr);
}

static inline int	lem_in_sdl_888(t_way *lst, t_lem *m, int i)
{
	if ((lst->param_ant[i].x !=
	m->room[lst->index_ways[lst->param_ant[i].len_way - 1]].x)
	|| (lst->param_ant[i].y
	!= m->room[lst->index_ways[lst->param_ant[i].len_way - 1]].y))
		lem_in_sdl_888_1(lst, m, i);
	else if (lst->param_ant[i].len_way != 0)
	{
		lst->param_ant[i].x =
		m->room[lst->index_ways[lst->param_ant[i].len_way - 1]].x;
		lst->param_ant[i].y =
		m->room[lst->index_ways[lst->param_ant[i].len_way - 1]].y;
		lst->param_ant[i].len_way--;
		if (lst->param_ant[i].len_way != 0)
			lem_in_sdl_888_2(lst, m, i);
		else
		{
			free(lst->param_ant[i].brez);
			m->ants--;
			if (m->ants == 0)
				return (quit_1());
		}
	}
	return (0);
}

static inline int	lem_in_sdl_88(t_lem *m, t_way *lst)
{
	int									i;

	if (lst->ants > 0)
	{
		i = 0;
		while (i < lst->ants)
		{
			if (lst->param_ant[i].len_way > 0)
			{
				if (lst->param_ant[i].index != 0)
				{
					if (lem_in_sdl_888(lst, m, i) == 1)
						return (1);
				}
				else if (i == 0 || (i > 0
	&& (lst->param_ant[i - 1].x ==
	m->room[lst->index_ways[lst->param_ant[i].len_way - 1]].x)
	&& (lst->param_ant[i - 1].y ==
	m->room[lst->index_ways[lst->param_ant[i].len_way - 1]].y)))
					lem_in_sdl_zero(lst, m, i);
			}
			i++;
		}
	}
	return (0);
}

inline void			lem_im_sdl(t_lem *m)
{
	char	run;
	t_way	*lst;

	lem_im_sdl_init(m, &run);
	while (run)
	{
		poll_event(&run);
		draw_sdl(m);
		lst = m->ways.way;
		if (m->ants > 0)
			while (lst != NULL)
			{
				if (lem_in_sdl_88(m, lst) == 1)
					return ;
				lst = lst->next;
			}
		SDL_RenderPresent(g_ren);
		SDL_Delay(10);
	}
	quit();
	return ;
}
