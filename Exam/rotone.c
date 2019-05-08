/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:20:25 by rrika             #+#    #+#             */
/*   Updated: 2019/02/21 16:44:55 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'a' && argv[1][i] < 'z')
				ft_putchar(argv[1][i] + 1);
			else if (argv[1][i] == 'z')
				ft_putchar('a');
			else if (argv[1][i] >= 'A' && argv[1][i] < 'Z')
				ft_putchar(argv[1][i] + 1);
			else if (argv[1][i] == 'Z')
				ft_putchar('A');
			else
				ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
