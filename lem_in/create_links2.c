/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_links2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:59:11 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 14:36:46 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

inline int			create_links_1(t_lem *r, int *i, int *flag, char **lines)
{
	while (ft_strchr(lines[*i], '#'))
	{
		(*i)++;
		if (lines[*i] == NULL)
		{
			*flag = -1;
			break ;
		}
	}
	if (*flag == -1)
		return (0);
	if (ft_strchr(lines[*i], ' ') || (lines[*i][0] == '-'))
		free_array(lines, r, 1);\
	return (1);
}

static inline void	create_links_2_bonus(t_lem *r, char **l,
char **lines, int *j)
{
	*j = 0;
	while (*j < r->vertex && ft_strcmp(r->room[*j].name, l[1]) != 0)
	{
		if (*j == r->vertex - 1)
		{
			free_array(l, r, 0);
			free_array(lines, r, 1);
		}
		(*j)++;
	}
	if (ft_strcmp(l[0], l[1]) == 0)
	{
		free_array(l, r, 0);
		free_array(lines, r, 1);
	}
}

inline void			create_links_2(t_lem *r, int j, char **lines, char **l)
{
	int y;
	int x;

	create_links_2_bonus(r, l, lines, &j);
	x = j;
	y = j;
	if ((x = room_index(r, l[0], 1)) >= r->vertex ||
		(y = room_index(r, l[1], 1)) >= r->vertex)
	{
		free_array(l, r, 0);
		free_array(lines, r, 1);
	}
	if (check_links(&r, x, y) == 1)
	{
		free_array(l, r, 0);
		free_array(lines, r, 1);
	}
	if (x >= 0)
		r->links[(x * r->vertex) + y] = 1;
	else
		r->links[(x * r->vertex) + y] = 0;
	if (y >= 0)
		r->links[(y * r->vertex) + x] = 1;
	else
		r->links[(y * r->vertex) + x] = 0;
}

static inline void	create_links_3_bonus(t_lem *r, char **l, char **lines)
{
	int i;

	if ((ft_strcmp(r->room[r->start].name, l[0]) == 0
	|| ft_strcmp(r->room[r->start].name, l[1]) == 0)
	&& (ft_strcmp(r->room[r->end].name, l[0]) == 0
	|| ft_strcmp(r->room[r->end].name, l[1]) == 0))
	{
		i = 1;
		while (i <= r->ants)
		{
			ft_printf("L%d-%s ", i, r->room[r->end].name);
			if (i == r->ants)
				ft_printf("\n");
			i++;
		}
		free_array(lines, r, 0);
		free_array(l, r, 0);
		exit(0);
	}
}

inline void			create_links_3(t_lem *r, char **l, char **lines)
{
	int j;

	j = 0;
	create_links_3_bonus(r, l, lines);
	while (j < r->vertex && ft_strcmp(r->room[j].name, l[0]) != 0)
	{
		if (j == r->vertex - 1)
		{
			free_array(l, r, 0);
			free_array(lines, r, 1);
		}
		j++;
	}
	if (j > r->vertex)
	{
		free_array(l, r, 0);
		free_array(lines, r, 1);
	}
	create_links_2(r, j, lines, l);
}
