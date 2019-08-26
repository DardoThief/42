/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:49:45 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 11:49:41 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t i;
	size_t j;

	if (lit[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (lit[j])
		{
			if (i + j >= len || big[i + j] != lit[j])
				break ;
			j++;
		}
		if (lit[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
