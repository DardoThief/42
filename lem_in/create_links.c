/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:55:35 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 15:29:22 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

inline void			create_links_4(t_lem *r, char **l, t_st_end *s_e)
{
	if (ft_strcmp(r->room[r->start].name, l[0]) == 0
	|| ft_strcmp(r->room[r->start].name, l[1]) == 0)
		s_e->start = 1;
	if (ft_strcmp(r->room[r->end].name, l[0]) == 0
	|| ft_strcmp(r->room[r->end].name, l[1]) == 0)
		s_e->end = 1;
}

inline char			**create_links_init(int *i, int *flag, t_lem *r)
{
	char **lines;

	*i = 0;
	*flag = 0;
	lines = ft_strsplit(r->links_list, '\n');
	if (!lines[*i] && r->step == 2)
		free_array(lines, r, 1);
	return (lines);
}

inline void			create_links_st_end(t_lem *r, char **l,
char **lines, t_st_end s_e)
{
	if (s_e.start == 0 || s_e.end == 0)
	{
		free_array(l, r, 0);
		free_array(lines, r, 1);
	}
	free_array(l, r, 0);
	free_array(lines, r, 0);
}

inline void			create_links_5(t_lem *r, char **l, char **lines)
{
	if (l[0] == NULL || l[1] == NULL || l[2])
	{
		if (l[2])
			free_array(l, r, 0);
		free_array(lines, r, 1);
	}
}

inline void			check_start_end(t_lem *r)
{
	if (r->start == -1 || r->end == -1)
		ft_lem_del(&r);
}
