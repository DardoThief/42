/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_hat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:18:11 by rrika             #+#    #+#             */
/*   Updated: 2019/07/26 18:25:51 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		sa_ra_sort(t_stack *stack)
{
	int	ap;

	ap = 0;
	if (!is_sorted(stack->a))
		ap += action("sa", &(stack->a), &(stack->b), stack->flags);
	if (stack->a->num != ft_lstmin(stack->a))
	{
		if (stack->a->next->num == ft_lstmin(stack->a))
			ap += action("ra", &(stack->a), &(stack->b), stack->flags);
		else
			ap += action("rra", &(stack->a), &(stack->b), stack->flags);
	}
	return (ap);
}

int		pa_pb_sort(t_stack *stack)
{
	int ap;

	ap = 0;
	while (!ft_lstsorted(stack->a) && ft_lstsize(stack->a) > 3)
	{
		ap += prep_b(stack);
		ap += action("pb", &(stack->a), &(stack->b), stack->flags);
	}
	ap += sa_ra_sort(stack);
	while (stack->b)
	{
		ap += prep_a(stack);
		ap += action("pa", &(stack->a), &(stack->b), stack->flags);
	}
	ap += fix_a(stack);
	return (ap);
}

int		pb_ra_sort(t_stack *stack, int lmax)
{
	int ap;

	ap = 0;
	while ((stack->a) && stack_contains(stack->a, lmax))
	{
		if (stack->a->num <= lmax)
		{
			ap += prep_b(stack);
			ap += action("pb", &stack->a, &stack->b, stack->flags);
		}
		else
			ap += action("ra", &(stack->a), &(stack->b), stack->flags);	
	}
	ap += fix_b(stack);
	return (ap);
}

int		sorting_hat(t_stack *stack)
{
	int		ap;
	int		chunk;
	int		temp;
	int		i;

	ap = 0;
	chunk = 0;
	temp = 0;
	i = 0;
	if (ft_lstsize(stack->a) <= 3)
		ap += sa_ra_sort(stack);
	else if (ft_lstsize(stack->a) <= 40)
		ap += pa_pb_sort(stack);
	else
		temp = (ft_lstsize(stack->a) <= 200 ? 5 : 11);
	if (temp)
	{
		chunk = (ft_lstmax(stack->a) - ft_lstmin(stack->a)) / temp;
		while (++i < temp)
			ap += pb_ra_sort(stack, chunk * i);
		ap += pb_ra_sort(stack, ft_lstmax(stack->a) + 1);
		ap += back_to_a(&(stack->a), &(stack->b), stack->flags);
	}
	return (ap);
}