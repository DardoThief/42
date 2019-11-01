/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 09:27:37 by smanhack          #+#    #+#             */
/*   Updated: 2019/10/25 19:10:54 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

inline char	init(void)
{
	char	error;
	int		flags;

	error = 1;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		error = 0;
	g_win = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED,
	SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
	if (g_win == NULL)
		error = 0;
	g_ren = SDL_CreateRenderer(g_win, -1,
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (g_ren == NULL)
		error = 0;
	flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags) && flags))
		error = 0;
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		error = 0;
	return (error);
}

inline void	lem_im_sdl_init(t_lem *m, char *run)
{
	t_way		*lst;
	int			i;

	if (!init())
		return (quit());
	if (!load())
		return (quit());
	coordinate_processing(m);
	*run = 1;
	lst = m->ways.way;
	while (lst != NULL)
	{
		if (lst->ants > 0)
		{
			i = 0;
			while (i < lst->ants)
			{
				lst->param_ant[i].index = 0;
				lst->param_ant[i].len_way = lst->len;
				i++;
			}
		}
		lst = lst->next;
	}
}

inline void	quit(void)
{
	SDL_DestroyWindow(g_win);
	g_win = NULL;
	SDL_DestroyRenderer(g_ren);
	g_ren = NULL;
	SDL_DestroyTexture(g_flower);
	g_flower = NULL;
	SDL_DestroyTexture(g_bg);
	g_bg = NULL;
	SDL_DestroyTexture(g_bg_2);
	g_bg_2 = NULL;
	Mix_FreeMusic(g_music);
	g_music = NULL;
	SDL_Quit();
	IMG_Quit();
}

inline int	quit_1(void)
{
	quit();
	return (1);
}
