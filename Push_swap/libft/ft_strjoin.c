/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:19:21 by rrika             #+#    #+#             */
/*   Updated: 2019/08/23 15:09:52 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*r;
// 	char	*c1;
// 	char	*c2;
// 	size_t	i;
// 	size_t	len;

// 	if (!s1 & !s2)
// 		return (0);
// 	if (!s1)
// 		return (ft_strdup(s2));
// 	if (!s2)
// 		return (ft_strdup(s1));
// 	len = (ft_strlen(s2) + 1);
// 	if (!(r = ft_memalloc(ft_strlen(s1) + len)))
// 		return (0);
// 	c1 = (char *)s1;
// 	c2 = (char *)s2;
// 	i = 0;
// 	while (*c1)
// 		r[i++] = *(c1++);
// 	while (*c2)
// 		r[i++] = *(c2++);
// 	r[i] = '\0';
// 	return (r);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (0);
	if (!(new = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	return (new);
}
