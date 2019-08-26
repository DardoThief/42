/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:19:21 by rrika             #+#    #+#             */
/*   Updated: 2019/08/26 19:08:14 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
