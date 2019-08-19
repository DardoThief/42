/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 12:33:58 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 15:36:43 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(size_t nb)
{
	size_t low;
	size_t high;

	if (nb < 1)
		return (0);
	if (nb == 1)
		return (1);
	if (nb > 3000000000)
		return (0);
	high = nb;
	low = high >> 1;
	while (high - low > 1)
	{
		if (low * low > nb)
		{
			high = low;
			low = low >> 1;
		}
		else if (low * low < nb)
			low = (high + low) >> 1;
		if (low * low == nb)
			return (low);
	}
	return (0);
}
