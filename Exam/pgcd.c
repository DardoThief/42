/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:45:00 by rrika             #+#    #+#             */
/*   Updated: 2019/02/21 15:48:52 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int i;
	int j;
	int g;

	g = 0;
	if (argc == 3)
	{
		i = atoi(argv[2]);
		j = atoi(argv[1]);
		if (i > j)
			g = j;
		else
			g = i;
		while (g > 0)
		{
			if (i % g == 0 && j % g == 0)
				break ;
			g--;
		}
		printf("%d", g);
	}
	printf("\n");
	return (0);
}
