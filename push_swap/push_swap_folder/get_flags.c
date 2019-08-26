/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:30:25 by rrika             #+#    #+#             */
/*   Updated: 2019/08/26 17:34:19 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_flags		init_flags(void)
{
	t_flags	flags;

	flags.c = false;
	flags.v = false;
	return (flags);
}

void		get_flags(int k, char *c, t_stack *stack)
{
	if (k == 0)
		return ;
	if (ft_strcmp(c, "-v") == 0)
		stack->flags.v = true;
	else if (ft_strcmp(c, "-c") == 0)
		stack->flags.c = true;
	else if (ft_strcmp(c, "-vc") == 0 || ft_strcmp(c, "-cv") == 0)
	{
		stack->flags.c = true;
		stack->flags.v = true;
	}
	else
		ft_error();
}

int			check_mod(char *str, int n)
{
	int		k;

	k = 0;
	if (str != NULL)
	{
		if (ft_strcmp(str, "-c") == 0)
			k = 1;
		else if (ft_strcmp(str, "-v") == 0)
			k = 1;
		else if (ft_strcmp(str, "-cv") == 0 || ft_strcmp(str, "-vc") == 0)
			k = 1;
		if (k + 1 >= n)
			ft_error();
	}
	return (k);
}
