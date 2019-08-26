/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_commands_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:04:27 by rrika             #+#    #+#             */
/*   Updated: 2019/08/09 14:25:18 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rot_loop(char s, t_stack *stack, int c, t_flags flags)
{
	int	i;

	i = -1;
	if (s == 'a')
		while (++i < c)
			action("ra", &(stack->a), &(stack->b), flags);
	else if (s == 'b')
		while (++i < c)
			action("rb", &(stack->a), &(stack->b), flags);
}

void	revrot_loop(char s, t_stack *stack, int c, t_flags flags)
{
	int	i;

	i = -1;
	if (s == 'a')
		while (++i < c)
			action("rra", &(stack->a), &(stack->b), flags);
	else if (s == 'b')
		while (++i < c)
			action("rrb", &(stack->a), &(stack->b), flags);
}

void	loop_n(char s, t_stack *stack, int c, t_flags flags)
{
	int	n;

	n = ft_lstsize(s == 'a' ? stack->a : stack->b);
	if (c <= n / 2)
		rot_loop(s, stack, c, flags);
	else
		revrot_loop(s, stack, n - c, flags);
}

void	back_to_a(t_link **a, t_link **b, t_flags flags)
{
	while (*b)
		action("pa", a, b, flags);
}

int		stack_contains(t_link *s, int lmax)
{
	while (s)
	{
		if (s->num <= lmax)
			return (1);
		s = s->next;
	}
	return (0);
}
