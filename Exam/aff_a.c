/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:07:01 by rrika             #+#    #+#             */
/*   Updated: 2019/02/20 16:58:37 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main (int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 1)
	{
		ft_putchar('a');
		ft_putchar('\n');
	}
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 'a')
			{
				ft_putchar(argv[1][i]);
				ft_putchar('\n');
				return (0);
			}
			i++;
		}
	}
	return (0);
}
