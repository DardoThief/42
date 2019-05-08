/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:29:58 by rrika             #+#    #+#             */
/*   Updated: 2019/02/20 21:15:26 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_count(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - 'A' + 1;
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 1;
	else
		return (0);
	return (c);

}

int		main(int argc, char **argv)
{
	int c;

	if (argc == 2)
	{
		while (*argv[1])
		{
			c = ft_count(*argv[1]);
			while (c > 0)
			{
				write(1, argv[1], 1);
				c--;
			}
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
