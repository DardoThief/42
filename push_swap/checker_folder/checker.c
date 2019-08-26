/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:29:06 by rrika             #+#    #+#             */
/*   Updated: 2019/08/26 19:12:14 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	commands(t_link **a, t_link **b)
{
	char	*cmd;

	while (get_next_line(0, &cmd) > 0)
	{
		fdis(cmd, a, b, 'c');
		free(cmd);
	}
	if (cmd && *cmd)
		free(cmd);
}

static int	check(t_link *a, t_link *b)
{
	if (b)
		return (0);
	while (a && a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

t_link		*parse_arg(int k, int ac, char **av)
{
	t_link	*a;
	int		n;
	char	**str;
	int		i;

	a = NULL;
	while (++k < ac)
	{
		i = 0;
		str = ft_strsplit(av[k], ' ');
		while (str[i])
		{
			n = ft_atoi(str[i]);
			dupe_check(a, n);
			ft_lstend(&a, n);
			i++;
		}
		ft_free_table(str);
	}
	return (a);
}

int			main(int argc, char **argv)
{
	t_link	*a;
	t_link	*b;

	if (argc == 1)
		return (0);
	a = parse_arg(0, argc, argv);
	b = NULL;
	commands(&a, &b);
	ft_putendl(check(a, b) ? "\033[32mOK\033[0m" : "\033[31mKO\033[0m");
	ft_lstfree(&a);
	ft_lstfree(&b);
	return (0);
}
