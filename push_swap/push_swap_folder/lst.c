/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:55:35 by rrika             #+#    #+#             */
/*   Updated: 2019/08/09 14:29:23 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstfree(t_link **s)
{
	t_link	*tmp;

	while (*s)
	{
		tmp = *s;
		tmp->num = 0;
		(*s) = (*s)->next;
		free(tmp);
	}
}

int		ft_lstsize(t_link *a)
{
	int	n;

	n = 0;
	while (a)
	{
		a = a->next;
		n++;
	}
	return (n);
}

int		ft_lstmax(t_link *s)
{
	int	max;

	max = 0;
	if (s)
		max = s->num;
	while (s)
	{
		if (max < s->num)
			max = s->num;
		s = s->next;
	}
	return (max);
}

int		ft_lstmin(t_link *s)
{
	int	min;

	min = 0;
	if (s)
		min = s->num;
	while (s)
	{
		if (min > s->num)
			min = s->num;
		s = s->next;
	}
	return (min);
}

int		ft_lstsorted(t_link *s)
{
	while (s && s->next)
	{
		if (s->num > s->next->num)
			return (0);
		s = s->next;
	}
	return (1);
}
