/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_hat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:18:11 by rrika             #+#    #+#             */
/*   Updated: 2019/08/09 14:29:48 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa_ra_sort(t_stack *stack)
{
	if (!is_sorted(stack->a))
		action("sa", &(stack->a), &(stack->b), stack->flags);
	if (stack->a->num != ft_lstmin(stack->a))
	{
		if (stack->a->next->num == ft_lstmin(stack->a))
			action("ra", &(stack->a), &(stack->b), stack->flags);
		else
			action("rra", &(stack->a), &(stack->b), stack->flags);
	}
}

void	pa_pb_sort(t_stack *stack)
{
	while (!ft_lstsorted(stack->a) && ft_lstsize(stack->a) > 3)
	{
		prep_b(stack);
		action("pb", &(stack->a), &(stack->b), stack->flags);
	}
	sa_ra_sort(stack);
	while (stack->b)
	{
		prep_a(stack);
		action("pa", &(stack->a), &(stack->b), stack->flags);
	}
	fix_a(stack);
}

void	pb_ra_sort(t_stack *stack, int lmax)
{
	while ((stack->a) && stack_contains(stack->a, lmax))
	{
		if (stack->a->num <= lmax)
		{
			prep_b(stack);
			action("pb", &stack->a, &stack->b, stack->flags);
		}
		else
			action("ra", &(stack->a), &(stack->b), stack->flags);
	}
	fix_b(stack);
}

void	sorting_hat(t_stack *stack)
{
	int		chunk;
	int		temp;
	int		i;

	chunk = 0;
	temp = 0;
	i = 0;
	if (ft_lstsize(stack->a) <= 3)
		sa_ra_sort(stack);
	else if (ft_lstsize(stack->a) <= 40)
		pa_pb_sort(stack);
	else
		temp = (ft_lstsize(stack->a) <= 200 ? 5 : 11);
	if (temp)
	{
		chunk = (ft_lstmax(stack->a) - ft_lstmin(stack->a)) / temp;
		while (++i < temp)
			pb_ra_sort(stack, chunk * i);
		pb_ra_sort(stack, ft_lstmax(stack->a) + 1);
		back_to_a(&(stack->a), &(stack->b), stack->flags);
	}
}
