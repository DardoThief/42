/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:19:19 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 11:48:05 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*src;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
		i++;
	if (!(src = (char*)malloc(sizeof(*src) * (i + 1))))
		return (0);
	else
	{
		j = 0;
		while (str[j])
		{
			src[j] = str[j];
			j++;
		}
		src[j] = '\0';
	}
	return (src);
}
