/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:52:55 by rrika             #+#    #+#             */
/*   Updated: 2019/08/08 15:26:49 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_link **a, char prog)
{
	if (prog == 'p')
		ft_putendl("ra");
	ft_lstrot(a);
}

void	rb(t_link **b, char prog)
{
	if (prog == 'p')
		ft_putendl("rb");
	ft_lstrot(b);
}

void	rr(t_link **a, t_link **b, char prog)
{
	if (prog == 'p')
		ft_putendl("rr");
	ft_lstrot(a);
	ft_lstrot(b);
}

void	ft_lstrot(t_link **stack)
{
	t_link	*temp;
	t_link	*last;

	if (*stack && (*stack)->next)
	{
		last = (*stack);
		temp = (*stack)->next;
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = last;
		last->next = NULL;
		(*stack) = temp;
	}
}

void	ft_lstswp(t_link **stack)
{
	t_link	*temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		temp->next = *stack;
		*stack = temp;
	}
}
