/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:08:02 by rrika             #+#    #+#             */
/*   Updated: 2019/08/12 15:35:03 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			main(int ac, char **av)
{
	t_stack	stack;
	int		k;
	t_flags	flags;

	flags = init_flags();
	k = check_mod(av[1], ac);
	if (k == 1)
		stack.flags = get_flags(k, av[1], flags);
	stack.a = parse_args(k, ac, av);
	if (!(stack.a))
		return (0);
	stack.b = NULL;
	sorting_hat(&stack);
	ft_lstfree(&(stack.a));
	ft_lstfree(&(stack.b));
	return (0);
}
