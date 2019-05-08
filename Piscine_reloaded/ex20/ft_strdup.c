/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:21:36 by rrika             #+#    #+#             */
/*   Updated: 2019/04/03 19:19:52 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (src[i] != '\0')
		i++;
	*str = (char*)malloc(sizeof(*str) * (i + 1));
	if (str != 0)
	{
		j = 0;
		while (src[j] != '\0')
		{
			str[j] = src[j];
			j++;
		}
		str[j] = '\0';
	}
	else
		return (0);
	return (*str);
}
