/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:51:18 by rrika             #+#    #+#             */
/*   Updated: 2019/08/08 15:25:33 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_link **a, char prog)
{
	if (prog == 'p')
		ft_putendl("sa");
	ft_lstswp(a);
}

void	sb(t_link **b, char prog)
{
	if (prog == 'p')
		ft_putendl("sb");
	ft_lstswp(b);
}

void	ss(t_link **a, t_link **b, char prog)
{
	if (prog == 'p')
		ft_putendl("ss");
	ft_lstswp(a);
	ft_lstswp(b);
}

void	pa(t_link **a, t_link **b, char prog)
{
	if (prog == 'p')
		ft_putendl("pa");
	ft_lstpush(a, b);
}

void	pb(t_link **a, t_link **b, char prog)
{
	if (prog == 'p')
		ft_putendl("pb");
	ft_lstpush(b, a);
}
