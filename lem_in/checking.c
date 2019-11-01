/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:09:00 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 14:38:16 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	check_coor(t_lem **r, int x, int y, int g)
{
	int i;

	i = 0;
	while (&(*r)->room[i] && i < g)
	{
		if ((*r)->room[i].x == x && (*r)->room[i].y == y)
			ft_lem_del(r);
		i++;
	}
}

inline void			coordinates(t_lem **r, t_lis *room, char **w, int g)
{
	(*r)->room[g].name = ft_strdup(w[0]);
	if (!w && !w[0] && !w[1] && !w[2] && w[3])
		free_array(w, (*r), 1);
	ft_max_min_int(w[1], r);
	room->x = ft_atoi(w[1]);
	ft_max_min_int(w[2], r);
	room->y = ft_atoi(w[2]);
	check_coor(r, room->x, room->y, g);
}

inline void			checking_names(t_lem *r, char *name, int g)
{
	int index;

	index = 0;
	while (r->room[index].name && index < g)
	{
		if (ft_strcmp(r->room[index].name, name) == 0)
			ft_lem_del(&r);
		index++;
	}
}

inline int			check_links(t_lem **r, int x, int y)
{
	if (((*r)->links[(x * (*r)->vertex) + y] == 1
	|| (*r)->links[(x * (*r)->vertex) + y] == 1) \
	&& ((*r)->links[(y * (*r)->vertex) + x] == 1
	|| (*r)->links[(y * (*r)->vertex) + x] == 1))
		return (1);
	return (0);
}
