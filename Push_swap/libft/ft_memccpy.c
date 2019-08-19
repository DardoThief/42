/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:53:45 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 11:46:32 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sr;
	size_t			i;

	if (dest == src || n == 0)
		return (0);
	i = 0;
	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	while (n > i)
	{
		dst[i] = sr[i];
		if (dst[i] == (unsigned char)c)
			return (dst + i + 1);
		if (dst[i] == 0)
			return (0);
		i++;
	}
	return (0);
}
