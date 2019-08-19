/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 11:50:04 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 15:35:30 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst2;
	const char	*src2;

	i = -1;
	dst2 = dst;
	src2 = src;
	if (dst > src)
		while ((n--) > 0)
			dst2[n] = src2[n];
	if (dst < src)
		while ((++i) < n)
			dst2[i] = src2[i];
	return (dst);
}
