/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:53:16 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 15:33:46 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		num;
	int		znak;

	num = ft_numlen(n);
	znak = 1;
	if (n < 0)
		znak = -1;
	if (!(str = ft_strnew(num)))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[num - 1] = '0' + znak * (n % 10);
		n = n / 10;
		num--;
	}
	return (str);
}
