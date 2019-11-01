/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:40:56 by smanhack          #+#    #+#             */
/*   Updated: 2019/10/25 13:19:33 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_search_min_ways_4(t_lem *m, int *end, int *weight)
{
	int	temp;
	int	i;

	i = 0;
	while (i < m->vertex)
	{
		if (m->links[(i * m->vertex) + *end] >= 0)
		{
			temp = *weight - m->links[(i * m->vertex) + *end];
			if (temp == m->min_ways[i])
			{
				m->commun[(i * m->vertex) + *end] = 1;
				m->commun[(*end * m->vertex) + i] = 1;
				*weight = temp;
				*end = i;
			}
		}
		i++;
	}
}

void	ft_search_min_ways_2(t_lem *m, int end, int begin_index, int k_len)
{
	int k;
	int weight;
	int j;

	k = 0;
	while (k < m->vertex)
	{
		if (m->min_ways[k] >= 0 && m->min_ways[k]
		!= INT_MAX && k != m->end && k != m->start)
		{
			end = k;
			weight = m->min_ways[end];
			j = 0;
			while (j < k_len)
			{
				if (m->peaks_visited[j] == end)
					break ;
				j++;
			}
			while (end != begin_index && j == k_len)
				ft_search_min_ways_4(m, &end, &weight);
		}
		k++;
	}
}

void	ft_com_links(t_lem *m, int k_len)
{
	int	i;
	int	a;
	int	b;

	i = k_len - 1;
	while (i > 0)
	{
		a = (m->peaks_visited[i] * m->vertex) + m->peaks_visited[i - 1];
		b = (m->peaks_visited[i - 1] * m->vertex) + m->peaks_visited[i];
		m->links[a] = -1;
		m->links[b] = -1;
		if (m->vertex < 100)
		{
			m->links[b] = 0;
			m->commun[b] = 0;
			m->commun[a] = 0;
		}
		i--;
	}
}

void	ft_min_way_init(t_lem *m, int end, int *k, int *weight)
{
	int i;

	i = 0;
	while (i < m->vertex)
		m->peaks_visited[i++] = 0;
	m->peaks_visited[0] = end;
	*k = 1;
	*weight = m->min_ways[end];
}

void	ft_min_way(t_lem *m, int end, int begin_index, int *k_len)
{
	int weight;
	int i;
	int k;
	int temp;

	ft_min_way_init(m, end, &k, &weight);
	while (end != begin_index && (i = 0) == 0)
	{
		while (i < m->vertex)
		{
			if (m->links[(i * m->vertex) + end] >= 0 && end != i)
			{
				temp = weight - m->links[(i * m->vertex) + end];
				if (temp == m->min_ways[i])
				{
					weight = temp;
					end = i;
					m->peaks_visited[k] = i;
					k++;
				}
			}
			i++;
		}
	}
	*k_len = k;
}
