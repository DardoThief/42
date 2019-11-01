/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:52:05 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 14:38:52 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	add_rooms_1(t_lem *r, t_add_r *a)
{
	if (ft_strcmp(a->line[a->j], "##start") == 0)
		r->start = a->g;
	else
		r->end = a->g;
	a->j++;
	if (!a->line[a->j])
		free_array(a->line, r, 1);
	else if (ft_strcmp(a->line[a->j - 1], "##start") == 0
	|| ft_strcmp(a->line[a->j - 1], "##end") == 0)
	{
		while (ft_strchr(a->line[a->j], '#'))
		{
			if (a->line[a->j][1] == '#')
				free_array(a->line, r, 1);
			a->j++;
		}
		a->w = ft_strsplit(a->line[a->j], ' ');
	}
	if (ft_strcmp(a->line[a->j - 1], "##start") == 0)
		coordinates(&r, &(r->room[r->start]), a->w, a->g);
	else
		coordinates(&r, &(r->room[r->end]), a->w, a->g);
}

static inline void	add_rooms_2(t_lem *r, t_add_r *a)
{
	if (a->w && a->w[0])
		checking_names(r, a->w[0], a->g);
	if (a->w)
	{
		a->i = 0;
		while (a->w[a->i])
			free(a->w[a->i++]);
		free(a->w);
		a->w = NULL;
	}
	a->g++;
	a->j++;
}

static inline int	add_rooms_3(t_lem *r, t_add_r *a)
{
	if (ft_strchr(a->line[a->j], '-'))
		return (0);
	if (ft_strchr(a->line[a->j], '#'))
		a->g--;
	else
	{
		a->w = ft_strsplit(a->line[a->j], ' ');
		coordinates(&r, &(r->room[a->g]), a->w, a->g);
	}
	return (1);
}

void				add_rooms(t_lem *r)
{
	t_add_r	a;

	a.line = ft_strsplit(r->rooms_list, '\n');
	add_rooms_init(r, &a);
	a.j = 0;
	while (a.line[a.j] && ft_strchr(a.line[a.j], '-') == NULL)
	{
		if ((ft_strcmp(a.line[a.j], "##start") == 0)
		|| (ft_strcmp(a.line[a.j], "##end") == 0))
			add_rooms_1(r, &a);
		else
		{
			if ((add_rooms_3(r, &a) == 0))
				return ;
		}
		add_rooms_2(r, &a);
	}
	if (a.line)
	{
		a.i = 0;
		while (a.line[a.i])
			free(a.line[a.i++]);
		free(a.line);
	}
}

void				add_rooms_init(t_lem *r, t_add_r *a)
{
	int j;
	int i;

	a->g = 0;
	a->w = NULL;
	j = 0;
	r->room = (t_lis *)malloc(sizeof(t_lis) * r->vertex);
	ft_bzero(r->room, sizeof(t_lis) * r->vertex);
	r->links = (char *)malloc(sizeof(char) * (r->vertex * r->vertex));
	while (j < r->vertex)
	{
		i = 0;
		while (i < r->vertex)
		{
			if (i == j)
				r->links[(i * r->vertex) + j] = -1;
			else
				r->links[(i * r->vertex) + j] = -1;
			i++;
		}
		j++;
	}
}
