/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:03:07 by smanhack          #+#    #+#             */
/*   Updated: 2019/10/25 15:48:07 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# include </Users/smanhack/.brew/include/SDL2/SDL.h>
# include </Users/smanhack/.brew/include/SDL2/SDL_image.h>
# include "/Users/smanhack/.brew/include/SDL2/SDL2_gfxPrimitives.h"
# include "/Users/smanhack/.brew/include/SDL2/SDL_mixer.h"
# include "lem_in.h"
# include <math.h>
# define RADIUS 600
# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 1300

SDL_Window		*g_win;
SDL_Renderer	*g_ren;
SDL_Texture		*g_flower;
SDL_Texture		*g_bg;
SDL_Texture		*g_bg_2;
Mix_Music		*g_music;
char			init(void);
void			lem_im_sdl_init(t_lem *m, char *run);
void			quit(void);
int				quit_1(void);
char			load(void);
void			draw_sdl(t_lem *m);
void			lem_im_sdl(t_lem *m);
void			move_ant(t_way *lst, int i, t_lem *m);
void			coordinate_processing(t_lem *m);
void			poll_event(char *run);
void			lem_in_sdl_zero(t_way *lst, t_lem *m, int i);

#endif
