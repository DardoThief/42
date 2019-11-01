/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:38:03 by smanhack          #+#    #+#             */
/*   Updated: 2019/10/25 14:26:37 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	ft_wat_out_print_2(t_way *lst, t_way_out *w,
t_lem *m, int i)
{
	char *buff;

	if (lst->param_ant[i].len_way > 0 && lst->param_ant[i].index != 0)
	{
		buff = m->room[lst->index_ways[lst->param_ant[i].len_way - 1]].name;
		if (w->fl_1 == 0)
		{
			ft_putchar('L');
			ft_putnbr(lst->param_ant[i].index);
			ft_putchar('-');
			ft_putstr(buff);
			w->fl_1 = 1;
		}
		else
		{
			write(1, " L", 2);
			ft_putnbr(lst->param_ant[i].index);
			ft_putchar('-');
			ft_putstr(buff);
		}
		lst->param_ant[i].len_way--;
	}
	else
		ft_wat_out_print_2_bonus(lst, w, i);
}

static inline void	ft_wat_out_print_3(t_way *lst, t_way_out *w,
t_lem *m, int i)
{
	char *buff;

	if (lst->param_ant[i].index == 0 && w->fl == 0)
	{
		buff = m->room[lst->index_ways[lst->param_ant[i].len_way - 1]].name;
		lst->param_ant[i].index = w->num_ant;
		if (w->fl_1 == 0)
		{
			ft_putchar('L');
			ft_putnbr(w->num_ant);
			ft_putchar('-');
			ft_putstr(buff);
			w->fl_1 = 1;
		}
		else
		{
			write(1, " L", 2);
			ft_putnbr(w->num_ant);
			ft_putchar('-');
			ft_putstr(buff);
		}
		lst->param_ant[i].len_way--;
		(w->num_ant)++;
		w->fl = 1;
	}
}

static inline void	ft_wat_out_print(t_way *lst, t_way_out *w, t_lem *m)
{
	int i;

	i = 0;
	while (i < lst->ants)
	{
		ft_wat_out_print_2(lst, w, m, i);
		ft_wat_out_print_3(lst, w, m, i);
		i++;
	}
}

static inline void	ft_way_out_init(t_way *lst, t_way_out *w, t_lem *m)
{
	int i;

	lst = m->ways.way;
	w->num_ant = 1;
	while (lst != NULL)
	{
		if (lst->ants > 0)
		{
			lst->param_ant = (t_ants *)malloc(sizeof(t_ants) * lst->ants);
			i = 0;
			while (i < lst->ants)
			{
				lst->param_ant[i].index = 0;
				lst->param_ant[i].len_way = lst->len;
				lst->param_ant[i].x = -1;
				lst->param_ant[i].y = -1;
				i++;
			}
		}
		else
			lst->param_ant = NULL;
		lst = lst->next;
	}
}

void				ft_way_out(t_lem *m)
{
	t_way_out	w;
	t_way		*lst;

	lst = NULL;
	ft_way_out_init(lst, &w, m);
	w.ants = m->ants;
	w.fl_1 = 0;
	while (w.ants != 0)
	{
		lst = m->ways.way;
		while (lst != NULL)
		{
			w.fl = 0;
			if (lst->ants > 0)
				ft_wat_out_print(lst, &w, m);
			lst = lst->next;
		}
		if (w.ants != 0)
			ft_putchar('\n');
		w.fl_1 = 0;
	}
}
