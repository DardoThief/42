/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:42:08 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 15:38:43 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	if (size + 1 == 0)
		return (NULL);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (str);
}
