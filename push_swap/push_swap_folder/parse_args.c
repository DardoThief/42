/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:43:35 by rrika             #+#    #+#             */
/*   Updated: 2019/08/26 19:07:48 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		dupe_check(t_link *s, int n)
{
	while (s)
	{
		if (s->num == n)
			ft_error();
		s = s->next;
	}
}

void		ft_lstend(t_link **a, int num)
{
	t_link	*tmp;
	t_link	*end;

	tmp = malloc(sizeof(t_link));
	tmp->num = num;
	tmp->next = NULL;
	if ((end = *a))
	{
		while (end->next)
			end = end->next;
		end->next = tmp;
	}
	else
		(*a) = tmp;
}

t_link		*parse_args(int k, int ac, char **av)
{
	t_link	*a;
	int		n;
	char	**str;
	int		i;

	a = NULL;
	while (++k < ac)
	{
		i = 0;
		str = ft_strsplit(av[k], ' ');
		while (str[i])
		{
			n = ft_atoi(str[i]);
			dupe_check(a, n);
			ft_lstend(&a, n);
			i++;
		}
		ft_free_table(str);
	}
	return (a);
}

void		ft_lstprint(t_link *a)
{
	while (a)
	{
		ft_putnbr(a->num);
		ft_putchar(' ');
		a = a->next;
	}
}
