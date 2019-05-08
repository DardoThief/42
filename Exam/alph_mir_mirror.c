/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alph_mir_mirror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:18:31 by rrika             #+#    #+#             */
/*   Updated: 2019/02/18 12:37:58 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar (char c)
{
	write(1, &c, 1);
}

void	ft_reverse(char str)
{
	int index;

	if (str >= 'a' && str <= 'z')
	{
		index = 'a' - str;
		ft_putchar('Z' + index);
	}
	else if (str >= 'A' && str <= 'Z')
	{
		index = 'A' - str;
		ft_putchar('z' + index);
	}
	else
		ft_putchar(str);
}

int		main (int argc, char **argv)
{
	char *str;
	int i;

	i = 0;
	str = argv[1];
	while (str[i])
	{
		ft_reverse(str[i++]);
	}
	ft_putchar('\n');
	return (0);
}
