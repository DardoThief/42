/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_commands_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:04:27 by rrika             #+#    #+#             */
/*   Updated: 2019/07/26 18:14:32 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     rot_loop(char s, t_stack *stack, int c, t_flags flags)
{
    int     i;
    int     ap;

	i = -1;
	ap = 0;
	if (s == 'a')
		while (++i < c)
			ap += action("ra", &(stack->a), &(stack->b), flags);
	else if (s == 'b')
		while (++i < c)
			ap += action("rb", &(stack->a), &(stack->b), flags);
	return (ap);
}

int		revrot_loop(char s, t_stack *stack, int c, t_flags flags)
{
	int		i;
	int		ap;

	i = -1;
	ap = 0;
	if (s == 'a')
		while (++i < c)
			ap += action("rra", &(stack->a), &(stack->b), flags);
	else if (s == 'b')
		while (++i < c)
			ap += action("rrb", &(stack->a), &(stack->b), flags);
	return (ap);
}

int		loop_n(char s, t_stack *stack, int c, t_flags flags)
{
	int		n;
	int		ap;

	ap = 0;
	n = ft_lstsize(s == 'a' ? stack->a : stack->b);
	if (c <= n / 2)
		ap = rot_loop(s, stack, c, flags);
	else
		ap += revrot_loop(s, stack, n - c, flags);
	return (ap);	
}

int	back_to_a(t_link **a, t_link **b, t_flags flags)
{
	int		ap;

	ap = 0;
	while (*b)
	{
		action("pa", a, b, flags);
		ap++;
	}
	return (ap);
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