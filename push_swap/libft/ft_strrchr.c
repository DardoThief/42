/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:14:44 by rrika             #+#    #+#             */
/*   Updated: 2019/04/15 17:40:45 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	if (ch == 0)
		return ((char *)str + i);
	while (i > 0)
	{
		i--;
		if (str[i] == (char)ch)
			return ((char *)str + i);
	}
	return (0);
}
