/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:36:54 by smanhack          #+#    #+#             */
/*   Updated: 2019/10/25 17:57:35 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_tail_2(t_proc *p, int k)
{
	int	l;

	l = 0;
	p->len_2_new = p->j - k + l;
	while ((p->i + k + l) <= p->len_1)
	{
		p->way_2[p->j - k + l] = p->way_1[p->i + k + l];
		l++;
		p->len_2_new++;
	}
	p->len_2_new--;
	l = 0;
	p->len_1_new = p->i + (p->g - 1);
	while (p->i + l <= p->len_1_new)
	{
		p->way_1[p->i + l] = p->buff[l];
		l++;
	}
}

void	ft_tail(t_proc *p, t_lem *m, t_way *lst)
{
	int	k;

	p->fl = 0;
	k = 0;
	if (p->way_1[p->i + 1] == p->way_2[p->j - 1])
	{
		while (p->way_1[p->i + k] == p->way_2[p->j - k])
			k++;
		k--;
		p->g = 0;
		while ((p->j + p->g) <= p->len_2)
		{
			p->buff[p->g] = p->way_2[p->j + p->g];
			p->g++;
		}
		ft_tail_2(p, k);
		m->ways.sum_len -= (p->len_1 + p->len_2);
		lst->len = p->len_1_new;
		p->lst->len = p->len_2_new;
		m->ways.sum_len += (p->len_1_new + p->len_2_new);
	}
}

void	ft_init_path_processing(t_lem *m, t_proc *p, t_way *lst)
{
	p->buff = (int *)malloc(sizeof(int) * m->vertex);
	p->way_1 = lst->index_ways;
	p->way_2 = p->lst->index_ways;
	p->len_1 = lst->len;
	p->len_2 = p->lst->len;
	p->fl = 1;
}

void	ft_path_processing_1(t_lem *m, t_way *lst, t_proc *p)
{
	while (p->lst != NULL)
	{
		if (p->lst != lst)
		{
			p->i = 1;
			ft_init_path_processing(m, p, lst);
			while (p->i < p->len_1 && p->fl)
			{
				p->j = 1;
				while (p->j < p->len_2 && p->fl)
				{
					if (p->way_1[p->i] == p->way_2[p->j])
						ft_tail(p, m, lst);
					p->j++;
				}
				p->i++;
			}
			free(p->buff);
		}
		p->lst = p->lst->next;
	}
}

void	ft_path_processing(t_lem *m)
{
	t_proc	p;
	t_way	*lst;

	free(m->commun);
	lst = m->ways.way;
	while (lst != NULL)
	{
		p.lst = lst->next;
		if (lst->len < m->ants)
			ft_path_processing_1(m, lst, &p);
		lst = lst->next;
	}
}
