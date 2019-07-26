/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:30:25 by rrika             #+#    #+#             */
/*   Updated: 2019/07/26 16:42:33 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void    init_flags(t_flags flags)
{
    flags.c = false;
    flags.v = false;
}

static int    check_flags(char *str, int n)
{
    int k;
    
    k = 0;
    if (ft_strcmp(str, "-v") == 0)
		k = 1;
	else if (ft_strcmp(str, "-c") == 0)
		k = 1;
	else if (ft_strcmp(str, "-vc") == 0 || ft_strcmp(str, "-cv") == 0)
		k = 1;
	if (k + 1 >= n)
		exit(0);
	return (k);
}

static void     mod_flags(int k, char *str, t_flags flags)
{
    if (k == 0)
        return ;
    if (ft_strcmp(str, "-v") == 0)
        flags.v = true;
    else if (ft_strcmp(str, "-c") == 0)
        flags.c = true;
    else if (ft_strcmp(str, "-vc") == 0 || ft_strcmp(str, "-cv") == 0)
	{
		flags.c = true;
		flags.v = true;
	}
    return (flags);
}

t_flags     get_flags(int ac, char **av)
{
    t_flags flags;
    int opt;

    opt = check_flags(av[1], ac);
    init_flags(flags);
    mod_flags(opt, av[1], flags);
    return (flags);
}