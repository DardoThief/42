/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alph_mirror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:00:29 by rrika             #+#    #+#             */
/*   Updated: 2019/02/18 12:16:44 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_string(char f)
{
	int index;
	if ('a' <= f && f <= 'z')
	{
		index = f - 'a';
		ft_putchar('z' - index);
	}
	else if ('A' <= f && f <= 'Z')
	{
		index = f - 'A';
		ft_putchar('Z' - index);
	}
	else
		ft_putchar(f);
}

int		main (int argc, char **argv)
{
	char *str;
	int i;

	str = argv[1];
	while (str[i])
	{
		ft_string(str[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
