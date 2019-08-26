/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:13:01 by rrika             #+#    #+#             */
/*   Updated: 2019/08/26 17:58:48 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_lenword(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static	int		ft_words(char *str, char c)
{
	int		count;

	count = 0;
	while (str[0] != '\0')
	{
		while (str[0] == c)
			str++;
		if (str[0] != '\0' && str[0] != c)
			count++;
		while (str[0] != '\0' && str[0] != c)
			str++;
	}
	return (count);
}

static int		check(char c, char n, char **chr)
{
	if ((c == '-' || c == '+') && (n == ' ' || n == '\0'))
	{
		ft_strdel(chr);
		return (1);
	}
	return (0);
}

static	char	**ft_strsplit2(char *str, char c)
{
	char	**chr;
	char	*chr2;
	int		j;

	j = 0;
	if (!(chr = (char**)ft_memalloc(sizeof(chr) * (ft_words(str, c) + 1))))
		return (0);
	while (str[0] != '\0')
	{
		if (!(chr[j] = ft_strnew(ft_lenword(str, c))))
			return (ft_free_table(chr));
		chr2 = chr[j];
		while (str[0] != '\0' && str[0] != c)
		{
			if (check(str[0], str[1], chr) == 1)
				ft_error();
			chr2[0] = str[0];
			chr2++;
			str++;
		}
		j++;
		while (str[0] != '\0' && str[0] == c)
			str++;
	}
	return (chr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*str;

	str = (char *)s;
	if (str == NULL)
		return (NULL);
	while (str[0] == c)
		str++;
	return (ft_strsplit2(str, c));
}

