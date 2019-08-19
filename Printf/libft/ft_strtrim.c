/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:25:42 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 15:39:14 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*begin;
	int		i;

	if (s == NULL)
		return (NULL);
	begin = (char *)s;
	while (begin[0] == ' ' || begin[0] == '\n' || begin[0] == '\t')
		begin++;
	if (begin[0] == '\0')
		return (ft_strnew(0));
	str = begin;
	i = ft_strlen(begin);
	while (str[i - 1] == ' ' || str[i - 1] == '\n' || str[i - 1] == '\t')
		i--;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i > 0)
	{
		str[i - 1] = begin[i - 1];
		i--;
	}
	return (str);
}
