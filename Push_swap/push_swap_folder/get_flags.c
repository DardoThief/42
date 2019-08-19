/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:30:25 by rrika             #+#    #+#             */
/*   Updated: 2019/08/12 15:35:07 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		ft_error(void)
{
	write(2, "\033[31mError\n\033[0m", 15);
	exit(1);
}

t_flags		init_flags(void)
{
	t_flags	flags;

	flags.c = false;
	flags.v = false;
	return (flags);
}

t_flags		get_flags(int k, char *c, t_flags flags)
{
	if (k == 0)
		return (flags);
	if (ft_strcmp(c, "-v") == 0)
		flags.v = true;
	else if (ft_strcmp(c, "-c") == 0)
		flags.c = true;
	else if (ft_strcmp(c, "-vc") == 0 || ft_strcmp(c, "-cv") == 0)
	{
		flags.c = true;
		flags.v = true;
	}
	else
		ft_error();
	return (flags);
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
