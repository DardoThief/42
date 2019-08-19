/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:03:39 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 15:38:58 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	эта функция
**	реверсирует строку
*/

char	*ft_strrevers(char *str)
{
	int		i;
	int		len;
	char	chr;

	i = 0;
	if (str == NULL || str[0] == 0)
		return (NULL);
	len = ft_strlen(str);
	while (i < len / 2)
	{
		chr = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = chr;
		i++;
	}
	return (str);
}
