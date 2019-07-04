/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:53:15 by rrika             #+#    #+#             */
/*   Updated: 2019/07/03 14:45:43 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     main(int argc, char **argv)
{
    int i;
    int nbr;

    if (argc == 2)
    {
        i = 1;
        nbr = atoi(argv[1]);
        while (nbr >= ++i)
        {
            if (nbr % i == 0)
            {
                printf("%d", i);
				if (nbr == i)
					break ;
				printf("*");
				nbr /= i;
				i = 1;
            }
        }
    }
	printf("\n");
	return (0);
}