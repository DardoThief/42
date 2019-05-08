/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:57:14 by rrika             #+#    #+#             */
/*   Updated: 2019/02/21 20:20:22 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	char *arr;
	int i;
	int nbr2;

	i = 1;
	nbr2 = nbr;
	if (nbr == 0 || nbr < 0)
	{
		i++;
		nbr2 = nbr * -1;
	}
	while (nbr2 /= 10)
		i++;
	if ((arr = (char*)malloc(sizeof(char) * (i + 1))) == 0)
		return (0);
	arr[i] = '\0';
	i--;
	while (i >= 0)
	{
		arr[i--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (nbr < 0)
		arr[0] = '-';
	return (arr);
}

int		main()
{
	int nbr = 123;

	printf("%s\n", ft_itoa(nbr));
	return (0);
}
