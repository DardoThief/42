/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:49:56 by rrika             #+#    #+#             */
/*   Updated: 2019/02/21 11:35:23 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *s1, char *s2)
{
	char *start_s1;

	start_s1 = s1;
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return (start_s1);
}

int		main()
{
	char *s1;
	char *s2;

	s1 = "Hello!";
	s2 = (char*)malloc(7);
	s2 = ft_strcpy(s2, s1);
	printf("%s\n", s2);
	return (0);
}
