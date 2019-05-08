/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:45:09 by rrika             #+#    #+#             */
/*   Updated: 2019/02/21 16:17:53 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_rrange(int start, int end)
{
	int *arr;
	int i;

	arr = (int*)malloc(sizeof(int) * (end - start + 1));
	i = 0;
	while (end >= start)
	{
		arr[i] = end;
		end--;
		i++;
	}
	return (arr);
}

int		main(int argc, char **argv)
{
	int *arr;
	arr = ft_rrange(atoi(argv[1]), atoi(argv[2]));

	int c = (atoi(argv[2]) - atoi(argv[1]));
	argc = -1;
	while (++argc <= c)
		printf("%d\n", arr[argc]);
	return (0);
}
