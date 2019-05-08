/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:44:37 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 11:47:11 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char *dest;

	dest = (unsigned char *)memptr;
	while (dest < (unsigned char *)memptr + num)
		*(dest++) = (unsigned char)val;
	return (memptr);
}
