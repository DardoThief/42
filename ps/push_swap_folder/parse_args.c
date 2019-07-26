/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:43:35 by rrika             #+#    #+#             */
/*   Updated: 2019/07/26 15:31:37 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_link		*parse_args(int ac, char **av)
{
	t_link	*a;
	int		i;
	int		n;

	i = g_optind - 1;
	a = NULL;
	while (++i < ac)
	{
		n = ft_atoi(av[i]);
		dupe_check(a, n);
		ft_lstend(&a, n);
	}
	return (a);
}