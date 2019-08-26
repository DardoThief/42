/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:19:19 by rrika             #+#    #+#             */
/*   Updated: 2019/08/26 19:08:29 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*src;
	size_t	i;

	if (!(src = (char*)ft_memalloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	i = 0;
	while (str[i])
	{
		src[i] = str[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
