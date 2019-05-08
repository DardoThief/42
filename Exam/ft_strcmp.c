/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:22:27 by rrika             #+#    #+#             */
/*   Updated: 2019/02/21 21:07:35 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	int r;
	int i;

	r = 0;
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			r = s1[i] - s2[i];
			break ;
		}
		i++;
	}
	return (r);
}

int		main()
{
	char *s1 = "HeLlo";
	char *s2 = "Hell";

	printf("%d\n", ft_strcmp(s1, s2));
	return (0);
}
