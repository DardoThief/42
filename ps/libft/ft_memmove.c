/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:25:01 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 11:47:11 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*sr;
	unsigned char	*dst;
	size_t			i;

	if (src == dest)
		return (dest);
	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (src < dest)
	{
		i = n;
		while (i-- > 0)
			dst[i] = sr[i];
	}
	else
		while (0 < n)
		{
			*dst++ = *sr++;
			n--;
		}
	return (dest);
}
