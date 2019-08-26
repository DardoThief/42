/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:30:57 by rrika             #+#    #+#             */
/*   Updated: 2019/08/13 17:07:41 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fdis(char *cmd, t_link **a, t_link **b, char prog)
{
	if (ft_strequ(cmd, "sa"))
		sa(a, prog);
	else if (ft_strequ(cmd, "sb"))
		sb(b, prog);
	else if (ft_strequ(cmd, "ss"))
		ss(a, b, prog);
	else if (ft_strequ(cmd, "pa"))
		pa(a, b, prog);
	else if (ft_strequ(cmd, "pb"))
		pb(a, b, prog);
	else if (ft_strequ(cmd, "ra"))
		ra(a, prog);
	else if (ft_strequ(cmd, "rb"))
		rb(b, prog);
	else if (ft_strequ(cmd, "rr"))
		rr(a, b, prog);
	else if (ft_strequ(cmd, "rra"))
		rra(a, prog);
	else if (ft_strequ(cmd, "rrb"))
		rrb(b, prog);
	else if (ft_strequ(cmd, "rrr"))
		rrr(a, b, prog);
	else
		ft_error();
}

void	print_status(char *cmd, t_link **a, t_link **b, t_flags flags)
{
	system("clear");
	ft_putstr("Command: ");
	ft_putendl(cmd);
	if (flags.c)
		ft_putstr("\033[32m");
	ft_putstr("Stack A ");
	ft_putstr(": \033[0m");
	ft_lstprint(*a);
	ft_putchar('\n');
	if (flags.c)
		ft_putstr("\033[33m");
	ft_putstr("Stack B ");
	ft_putstr(": \033[0m");
	ft_lstprint(*b);
	ft_putstr("\n");
	sleep(1);
}

void	action(char *cmd, t_link **a, t_link **b, t_flags flags)
{
	fdis(cmd, a, b, (flags.v ? ' ' : 'p'));
	if (flags.v)
		print_status(cmd, a, b, flags);
}

int		is_sorted(t_link *s)
{
	t_link	*head;
	int		cut;

	cut = 0;
	head = s;
	while (s && s->next)
	{
		if (s->next->num < s->num)
			cut++;
		s = s->next;
	}
	if (head->num < s->num)
		cut++;
	return (cut > 1 ? 0 : 1);
}
