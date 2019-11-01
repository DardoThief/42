/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:23:23 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 18:11:06 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

inline void			ft_dijkstra_init(t_lem *m, int begin_index)
{
	int i;

	m->min_ways = (int *)malloc(sizeof(*(m->min_ways)) * m->vertex);
	i = 0;
	if (m->vertex < 100)
	{
		m->commun = (char *)malloc(sizeof(*(m->commun))
		* m->vertex * m->vertex);
		ft_bzero(m->commun, sizeof(*(m->commun)) * m->vertex * m->vertex);
	}
	while (i < m->vertex)
		m->min_ways[i++] = INT_MAX;
	m->peaks_visited = (int *)malloc(sizeof(*m->min_ways) * m->vertex);
	i = 0;
	while (i < m->vertex)
		m->peaks_visited[i++] = 1;
	m->min_ways[begin_index] = 0;
}

static inline void	ft_search_min_ways_3(t_lem *m, int minindex, int min)
{
	int temp;
	int i;

	if (minindex != INT_MAX)
	{
		i = 0;
		while (i < m->vertex)
		{
			if (m->links[(minindex * m->vertex) + i] >= 0 && minindex != i)
			{
				temp = min + m->links[(minindex * m->vertex) + i];
				if (temp < m->min_ways[i])
					m->min_ways[i] = temp;
			}
			i++;
		}
		m->peaks_visited[minindex] = 0;
	}
}

inline void			ft_search_min_ways(t_lem *m)
{
	int min;
	int minindex;
	int i;

	minindex = 0;
	while (minindex != INT_MAX)
	{
		minindex = INT_MAX;
		min = INT_MAX;
		i = 0;
		while (i < m->vertex)
		{
			if (m->peaks_visited[i] == 1 && m->min_ways[i] < min)
			{
				min = m->min_ways[i];
				minindex = i;
			}
			i++;
		}
		ft_search_min_ways_3(m, minindex, min);
	}
}
