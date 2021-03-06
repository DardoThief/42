/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:25:35 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 15:38:03 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	if (dst[i] == '\0' && i < size)
	{
		while (src[j] != '\0' && i + j + 1 < size)
		{
			if (i + j + 1 < size)
				dst[i + j] = src[j];
			j++;
		}
		if (i + j == size || src[j] == '\0' || j > 0)
			dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
