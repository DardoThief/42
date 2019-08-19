/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 11:33:30 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 15:34:58 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)dst;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		str[i] = ((char *)(src + i))[0];
		if (str[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
