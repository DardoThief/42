/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:30:37 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 11:49:41 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str2, const char *str1)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	j = 0;
	len = 0;
	while (str1[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)str2);
	while (str2[i])
	{
		while (str1[j] == str2[i + j])
		{
			if (j == len - 1)
				return ((char *)str2 + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
