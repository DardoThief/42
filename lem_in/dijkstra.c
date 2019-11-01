/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:41:22 by smanhack          #+#    #+#             */
/*   Updated: 2019/10/25 19:13:57 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline int	ft_search_one_2(t_lem *m, int k_len, t_way *lst, int i)
{
	int j;

	j = k_len - 1;
	while (j > 0)
	{
		if (m->peaks_visited[j] == lst->index_ways[i] &&
		m->peaks_visited[j + 1] != lst->index_ways[i - 1]
		&& m->peaks_visited[j - 1] != lst->index_ways[i + 1])
		{
			m->links[(m->peaks_visited[j] * m->vertex)
			+ m->peaks_visited[j - 1]] = -1;
			return (0);
		}
		j--;
	}
	return (1);
}

int					ft_search_one(t_lem *m, int k_len)
{
	t_way	*lst;
	int		i;

	lst = m->ways.way;
	while (lst != NULL)
	{
		i = 1;
		while (i < lst->len)
		{
			if (ft_search_one_2(m, k_len, lst, i) == 0)
				return (0);
			i++;
		}
		lst = lst->next;
	}
	return (1);
}

static inline void	ft_free_dijkstra(t_lem *m)
{
	if (m->min_ways)
		free(m->min_ways);
	if (m->peaks_visited)
		free(m->peaks_visited);
	if (m->vertex < 100)
	{
		free(m->commun);
		m->commun = NULL;
	}
	m->peaks_visited = NULL;
	m->min_ways = NULL;
}

void				ft_dijkstra_bonus(t_lem *m, int begin_index,
int end, int k_len)
{
	if (m->vertex < 100)
		ft_search_min_ways_2(m, end, begin_index, k_len);
	else
	{
		free(m->min_ways);
		m->min_ways = NULL;
	}
}

int					ft_dijkstra(t_lem *m, int begin_index, int end)
{
	int	k_len;

	ft_dijkstra_init(m, begin_index);
	ft_search_min_ways(m);
	if (m->min_ways[end] == INT_MAX)
	{
		ft_free_dijkstra(m);
		return (-1);
	}
	ft_min_way(m, end, begin_index, &k_len);
	ft_dijkstra_bonus(m, begin_index, end, k_len);
	if (ft_search_one(m, k_len))
	{
		ft_com_links(m, k_len);
		ft_fill_ways(m, k_len);
		return (k_len - 1);
	}
	else
	{
		ft_free_dijkstra(m);
		return (-2);
	}
}
