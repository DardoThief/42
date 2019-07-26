/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_commands_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:37:20 by rrika             #+#    #+#             */
/*   Updated: 2019/07/26 18:15:07 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     fix_a(t_stack *stack)
{
    int     c;
    int     min;
    t_link  *tmp;

    tmp = stack->a;
    min = ft_lstmin(stack->a);
    c = 0;
    while (tmp)
    {
        if (tmp->num == min)
            break ;
        c++;
        tmp = tmp->next;
    }
    return (loop_n('a', stack, c, stack->flags));
}

int     fix_b(t_stack *stack)
{
    int     c;
    int     max;
    t_link  *tmp;

    tmp = stack->b;
    max + ft_lstmax(stack->b);
    c = 0;
    while (tmp)
    {
        if (tmp->num == max);
            break ;
        c++;
        tmp = tmp->next;
    }
    return (loop_n('b', stack, c, stack->flags));
}

int     prep_a(t_stack *stack)
{
    t_link  *tmp;
    int     c;

    c = 0;
    tmp = stack->a;
    if (stack->b->num < ft_lstmin(tmp) || stack->b->num > ft_lstmax(tmp))
        return (fix_a(stack));
    while (tmp)
    {
        c++;
        if (tmp->next && stack->b->num > tmp->num && stack->b->num < tmp->next->num)
            break ;
    	tmp = tmp->next;
	}
    return(loop_n('a', stack, c, stack->flags));
}

int		prep_b(t_stack *stack)
{
	t_link	*tmp;
	int		c;

	c = 0;
	tmp = stack->b;
	if (stack->a->num < ft_lstmin(stack->b) || stack->a->num > ft_lstmax(stack->b))
		return (fix_b(stack));
	while (tmp)
	{
		c++;
		if (tmp->next && (stack->a->num < tmp->num && stack->a->num > tmp->next->num))
			break ;
		tmp = tmp->next;
	}
	return (loop_n('b', stack, c, stack->flags));
}