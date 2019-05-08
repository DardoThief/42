/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:09:46 by rrika             #+#    #+#             */
/*   Updated: 2019/02/21 14:13:27 by rrika            ###   ########.fr       */
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
	int word;

	i = 0;
	word = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (word == 0)
			{
				if (!(('\t' <= argv[1][i] && argv[1][i] <= '\r') || argv[1][i] == ' '))
				{
					word = 1;
					ft_putchar(argv[1][i]);
				}
			}
			else
			{
				if (('\t' <= argv[1][i] && argv[1][i] <= '\r') || argv[1][i] == ' ')
					break ;
				ft_putchar(argv[1][i]);
			}
			++i;
		}
	}
	ft_putchar('\n');
	return (0);
}
