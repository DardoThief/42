/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:03:07 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 18:24:41 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

inline void			free_array(char **array, t_lem *m, int error)
{
	int i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			if (array[i])
				free(array[i++]);
		}
		free(array);
	}
	array = NULL;
	if (error)
	{
		ft_lem_del(&m);
		ft_error();
		exit(1);
	}
}

static inline void	free_all_2(t_lem *r)
{
	t_way	*lst;
	t_way	*buff;

	lst = r->ways.way;
	while (lst)
	{
		buff = lst;
		lst = lst->next;
		if (buff->param_ant)
			free(buff->param_ant);
		if (buff->index_ways)
			free(buff->index_ways);
		free(buff);
		buff = NULL;
	}
}

inline void			free_all(t_lem *r)
{
	int		i;

	if (r->links_start)
	{
		free(r->links_start);
		r->links_start = NULL;
	}
	if (r->line)
		free(r->line);
	r->line = NULL;
	i = 0;
	if (r->room)
	{
		while (i < r->vertex)
			free(r->room[i++].name);
		free(r->room);
		r->room = NULL;
	}
	free_all_2(r);
	free(r);
}

inline void			free_mini(t_lem *r)
{
	int i;

	if (r->links_start)
	{
		free(r->links_start);
		r->links_start = NULL;
	}
	free(r->line);
	r->line = NULL;
	i = 0;
	while (i < r->vertex)
		free(r->room[i++].name);
	free(r->room);
	r->room = NULL;
	free(r);
	ft_error();
}
