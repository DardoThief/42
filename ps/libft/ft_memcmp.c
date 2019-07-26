/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:09:34 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 11:46:32 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*ar1;
	unsigned char	*ar2;
	size_t			i;

	ar1 = (unsigned char *)arr1;
	ar2 = (unsigned char *)arr2;
	i = 0;
	if (n == 0)
		return (0);
	while (ar1[i] == ar2[i])
	{
		i++;
		n--;
		if (n == 0)
			return (0);
	}
	return (ar1[i] - ar2[i]);
}
