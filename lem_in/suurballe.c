/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:40:26 by smanhack          #+#    #+#             */
/*   Updated: 2019/10/25 19:10:41 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	ft_suurballe_if(t_lem *m, int i, int j)
{
	int	a;
	int	b;
	int	res;

	if (m->buff_links[(i * m->vertex) + j] >= 0
	&& i != j && m->commun[(i * m->vertex) + j] == 1)
	{
		a = m->min_ways[j];
		b = m->min_ways[i];
		res = m->buff_links[(i * m->vertex) + j] - a + b;
		m->links[(i * m->vertex) + j] = res;
	}
}

inline void			ft_suurballe_cpy(t_lem *m)
{
	int	i;
	int	j;

	m->buff_links = (char *)malloc(m->vertex * m->vertex * sizeof(char));
	i = 0;
	while (i < m->vertex)
	{
		j = 0;
		while (j < m->vertex)
		{
			m->buff_links[(i * m->vertex) + j] = m->links[(i * m->vertex) + j];
			j++;
		}
		i++;
	}
}

inline void			ft_suurballe(t_lem *m)
{
	int		i;
	int		j;

	ft_suurballe_cpy(m);
	i = 0;
	while (i < m->vertex)
	{
		j = 0;
		while (j < m->vertex)
		{
			ft_suurballe_if(m, i, j);
			j++;
		}
		i++;
	}
	free(m->min_ways);
	free(m->commun);
	m->min_ways = NULL;
	m->commun = NULL;
}

inline void			ft_wat_out_print_2_bonus(t_way *lst, t_way_out *w, int i)
{
	if (lst->param_ant[i].len_way == 0 && lst->param_ant[i].index != 0)
	{
		lst->param_ant[i].len_way--;
		(w->ants)--;
	}
}
