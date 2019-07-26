/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:08:41 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 11:49:41 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i] && num != 0)
	{
		i++;
		num--;
	}
	if (num == 0)
		return (0);
	return ((unsigned char)(str1[i]) - (unsigned char)(str2[i]));
}
