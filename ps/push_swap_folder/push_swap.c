/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:08:02 by rrika             #+#    #+#             */
/*   Updated: 2019/07/26 17:58:09 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     main(int ac, char **av)
{
    int     ap;
    t_stack *stack;

    stack->flags = get_flags(ac, av);
    stack->a = (ac == g_optind ? parse_stdin() : parse_args(ac, av));
    if (!(stack->a))
        return (0);
    stack->b = NULL;
    ap = sorting_hat(&stack);
    ft_lstfree(&(stack->a));
    ft_lstfree(&(stack->b));
    return (0);
}