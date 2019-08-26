/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:05:17 by rrika             #+#    #+#             */
/*   Updated: 2019/08/23 17:26:07 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memalloc(size_t size)
// {
// 	char	*r;
// 	size_t	i;

// 	if (!(r = (char*)malloc(size)))
// 		return (0);
// 	i = 0;
// 	while (i < size)
// 		r[i++] = '\0';
// 	return (r);
// }

void	*ft_memalloc(size_t size)
{
	void	*str;

	if (!(str = (void*)malloc(size)))
		return (0);
	ft_bzero(str, size);
	return (str);
}