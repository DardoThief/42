/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:39:20 by rrika             #+#    #+#             */
/*   Updated: 2019/02/18 13:30:20 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int min, int max)
{
	int *arr;
	int i;
	
	arr = (int *)malloc(sizeof(int) * (max - min + 1));
	i = 0;
	while (max >= min)
	{
		arr[i] = max;
		i++;
		max--;
	}	
	return (arr);
}

int		main(void)
{
	int min;
	int max;
	int *arr;

	min = 1;
	max = 5;
	arr = ft_range(min, max);
	
	int i = -1;
	while (++i < 5)
		printf("%d\n", arr[i]);
	return (0);
}
