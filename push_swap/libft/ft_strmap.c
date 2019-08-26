/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:53 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 11:49:41 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*r;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	if ((r = ft_memalloc(len + 1)) == NULL)
		return (0);
	while (i < len)
	{
		r[i] = f(s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
