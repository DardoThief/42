/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:29:30 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 11:46:32 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sr;

	dest = (unsigned char *)dst;
	sr = (unsigned char *)src;
	while (n > 0)
	{
		*dest++ = *sr++;
		n--;
	}
	return (dst);
}
