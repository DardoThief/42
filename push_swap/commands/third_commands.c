/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:55:51 by rrika             #+#    #+#             */
/*   Updated: 2019/07/31 18:14:26 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_link **a, char prog)
{
	if (prog == 'p')
		ft_putendl("rra");
	ft_lstrevrot(a);
}

void	rrb(t_link **b, char prog)
{
	if (prog == 'p')
		ft_putendl("rrb");
	ft_lstrevrot(b);
}

void	rrr(t_link **a, t_link **b, char prog)
{
	if (prog == 'p')
		ft_putendl("rrr");
	ft_lstrevrot(a);
	ft_lstrevrot(b);
}

void	ft_lstrevrot(t_link **stack)
{
	t_link	*temp;
	t_link	*first;

	if (*stack && (*stack)->next)
	{
		temp = (*stack);
		while (*stack && (*stack)->next && (*stack)->next->next)
			(*stack) = (*stack)->next;
		first = (*stack)->next;
		(*stack)->next = NULL;
		first->next = temp;
		(*stack) = first;
	}
}

void	ft_lstpush(t_link **a, t_link **b)
{
	t_link	*temp;

	if (*b)
	{
		temp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = temp;
	}
}
