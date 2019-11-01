/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:51:03 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 13:49:10 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static inline void	load_1(char *ok)
{
	SDL_Surface	*temp_surf;

	temp_surf = IMG_Load("bg.png");
	if (temp_surf == NULL)
		*ok = 0;
	g_bg = SDL_CreateTextureFromSurface(g_ren, temp_surf);
	if (g_bg == NULL)
		*ok = 0;
	SDL_FreeSurface(temp_surf);
	temp_surf = IMG_Load("bg_2.png");
	if (temp_surf == NULL)
		*ok = 0;
	g_bg_2 = SDL_CreateTextureFromSurface(g_ren, temp_surf);
	if (g_bg_2 == NULL)
		*ok = 0;
	SDL_FreeSurface(temp_surf);
	g_music = Mix_LoadMUS("imp.wav");
	if (g_music == NULL)
		*ok = 0;
}

inline char			load(void)
{
	char		ok;
	SDL_Surface	*temp_surf;

	ok = 1;
	temp_surf = NULL;
	g_flower = NULL;
	g_bg = NULL;
	temp_surf = IMG_Load("flower.png");
	if (temp_surf == NULL)
		ok = 0;
	g_flower = SDL_CreateTextureFromSurface(g_ren, temp_surf);
	if (g_flower == NULL)
		ok = 0;
	SDL_FreeSurface(temp_surf);
	load_1(&ok);
	return (ok);
}

static inline void	draw_sdl_2(t_lem *m)
{
	int	i;
	int	j;

	i = 0;
	SDL_SetRenderDrawColor(g_ren, 0xA7, 0xB3, 0xB8, 0xFF);
	while (i < m->vertex)
	{
		j = 0;
		while (j < m->vertex)
		{
			if (m->links_start[(i * m->vertex) + j] >= 0)
				SDL_RenderDrawLine(g_ren, m->room[i].x,
				m->room[i].y, m->room[j].x, m->room[j].y);
			j++;
		}
		i++;
	}
}

inline void			draw_sdl(t_lem *m)
{
	SDL_Rect	bg_st_tr;
	int			i;

	SDL_SetRenderDrawColor(g_ren, 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderClear(g_ren);
	SDL_RenderCopy(g_ren, g_bg_2, NULL, NULL);
	bg_st_tr.w = 2 * RADIUS;
	bg_st_tr.h = 2 * RADIUS;
	bg_st_tr.x = (SCREEN_WIDTH / 2) - RADIUS;
	bg_st_tr.y = (SCREEN_HEIGHT / 2) - RADIUS;
	SDL_RenderCopy(g_ren, g_bg, NULL, &bg_st_tr);
	i = 0;
	while (i < m->vertex)
	{
		filledCircleRGBA(g_ren, m->room[i].x,
		m->room[i].y, 5, 0xF2, 0xF5, 0xF7, 0xFF);
		i++;
	}
	draw_sdl_2(m);
}
