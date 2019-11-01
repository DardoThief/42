/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:11:17 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 19:01:21 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

inline int	room_index(t_lem *r, char *room_name, int start)
{
	int index;

	index = (start) ? 0 : 1;
	while (r->room[index].name && index < r->vertex)
	{
		if (ft_strcmp(r->room[index].name, room_name) == 0)
			return (index);
		index++;
	}
	return (index);
}

inline void	ft_distribution_ants_1(t_lem *m)
{
	int		ants;
	t_way	*lst;
	int		n;

	ants = 0;
	n = m->ways.way->len;
	while (ants != m->ants)
	{
		lst = m->ways.way;
		while (lst != NULL && lst->len <= n)
		{
			if (ants != m->ants)
			{
				lst->ants++;
				ants++;
			}
			if (lst->next != NULL && lst->ants == n && lst->next->len > n)
				n = lst->next->len;
			lst = lst->next;
		}
	}
}

inline void	ft_init_links_st(t_lem *r, char **av)
{
	int i;
	int j;

	(void)av;
	create_links(r, 0, 0);
	free(r->rooms_list);
	r->rooms_list = NULL;
	free(r->links_list);
	r->links_list = NULL;
	if (av && av[1] && (ft_strcmp(av[1], "-v") == 0))
	{
		r->links_start = (char *)malloc(sizeof(char) * (r->vertex * r->vertex));
		i = 0;
		while (i < r->vertex)
		{
			j = 0;
			while (j < r->vertex)
			{
				r->links_start[(i * r->vertex)
				+ j] = r->links[(i * r->vertex) + j];
				j++;
			}
			i++;
		}
	}
}

inline void	algoritm(t_lem *r)
{
	while (r->num_steps != -1)
	{
		r->num_steps = ft_dijkstra(r, r->start, r->end);
		if (r->num_steps != -1 && r->num_steps != -2 && r->vertex < 100)
		{
			ft_suurballe(r);
			free(r->links);
			r->links = r->buff_links;
			r->buff_links = NULL;
		}
	}
	if (r->vertex < 100)
		ft_path_processing(r);
}
