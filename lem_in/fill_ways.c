/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:39:30 by smanhack          #+#    #+#             */
/*   Updated: 2019/10/24 19:49:29 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_fill_ways(t_lem *m, int len)
{
	t_way	*way;
	t_way	*lst;

	way = (t_way *)malloc(sizeof(*way));
	way->len = len - 1;
	way->index_ways = m->peaks_visited;
	m->peaks_visited = NULL;
	way->ants = 0;
	way->num_ant = 0;
	way->next = NULL;
	if (m->ways.way == NULL)
	{
		m->ways.way = way;
		m->ways.num_ways++;
		m->ways.sum_len += way->len;
	}
	else
	{
		lst = m->ways.way;
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = way;
		m->ways.num_ways++;
		m->ways.sum_len += way->len;
	}
}

void	ft_distribution_ants_mod_2(t_lem *m, int *ants, int s, int n)
{
	int		l;
	int		i;
	t_way	*lst;

	lst = m->ways.way;
	l = (*ants + s) / n;
	i = 0;
	while ((i++) < n)
	{
		if ((l - lst->len) <= 0 || (l - lst->len) > *ants)
			break ;
		lst->ants += l - lst->len;
		*ants -= l - lst->len;
		lst = lst->next;
	}
}

void	ft_distribution_ants_mod(t_lem *m, int ants)
{
	int		i;
	int		sum_len;
	int		num_ways;
	t_way	*lst;

	sum_len = m->ways.sum_len;
	num_ways = m->ways.num_ways;
	while (ants != 0)
	{
		i = 1;
		lst = m->ways.way;
		while ((i++) < num_ways)
			lst = lst->next;
		sum_len -= lst->len;
		num_ways--;
		ft_distribution_ants_mod_2(m, &ants, sum_len, num_ways);
	}
}

void	ft_distribution_ants(t_lem *m)
{
	t_way	*lst;
	int		l;
	int		ants;

	ants = m->ants;
	l = ((m->ants + m->ways.sum_len) / m->ways.num_ways);
	lst = m->ways.way;
	while (lst != NULL)
	{
		if (l - lst->len <= 0 || (l - lst->len) > ants)
			break ;
		lst->ants = l - lst->len;
		ants -= lst->ants;
		lst = lst->next;
	}
	ft_distribution_ants_mod(m, ants);
}
