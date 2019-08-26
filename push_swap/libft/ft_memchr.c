/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:48:33 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 11:46:32 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char *ar;

	ar = (unsigned char *)arr;
	while (n > 0)
	{
		if (*(ar++) == (unsigned char)c)
			return (ar - 1);
		n--;
	}
	return (0);
}
