/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:56:05 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 15:46:44 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

inline void	move_ant(t_way *lst, int i, t_lem *m)
{
	(void)m;
	lst->param_ant[i].brez->error2 = lst->param_ant[i].brez->error * 2;
	if (lst->param_ant[i].brez->error2 > -(lst->param_ant[i].brez->deltay))
	{
		lst->param_ant[i].brez->error -= lst->param_ant[i].brez->deltay;
		lst->param_ant[i].x += lst->param_ant[i].brez->signx;
	}
	if (lst->param_ant[i].brez->error2 < lst->param_ant[i].brez->deltax)
	{
		lst->param_ant[i].brez->error += lst->param_ant[i].brez->deltax;
		lst->param_ant[i].y += lst->param_ant[i].brez->signy;
	}
}

inline void	coordinate_processing(t_lem *m)
{
	int i;

	i = 0;
	while (i < m->vertex)
	{
		m->room[i].x = (SCREEN_WIDTH / 2) +
		RADIUS * cos((2 * M_PI * i) / m->vertex);
		m->room[i].y = (SCREEN_HEIGHT / 2) +
		RADIUS * sin((2 * M_PI * i) / m->vertex);
		i++;
	}
}

inline void	poll_event(char *run)
{
	SDL_Event	e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			*run = 0;
		else if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
				*run = 0;
			else if (e.key.keysym.sym == SDLK_9)
				Mix_PlayMusic(g_music, -1);
			else if (e.key.keysym.sym == SDLK_0)
				Mix_HaltMusic();
		}
	}
}

inline void	lem_in_sdl_zero(t_way *lst, t_lem *m, int i)
{
	SDL_Rect	bg_st_tr;

	lst->param_ant[i].index = 1;
	lst->param_ant[i].x = m->room[m->start].x;
	lst->param_ant[i].y = m->room[m->start].y;
	lst->param_ant[i].brez = (t_brez *)malloc(sizeof(t_brez));
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
