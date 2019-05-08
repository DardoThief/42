/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:13:01 by rrika             #+#    #+#             */
/*   Updated: 2019/04/15 18:54:28 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_strscpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static size_t	ft_count_words(const char *str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (!str[i])
			break ;
		words++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (words);
}

static size_t	ft_cut_words(const char *str, size_t words, char **r, char c)
{
	size_t	w;
	size_t	start;
	size_t	end;

	w = 0;
	start = 0;
	while (w < words && str[start])
	{
		while (str[start] == c)
			start++;
		end = start;
		while (str[end] && str[end] != c)
			end++;
		if (!(r[w] = (char *)malloc(end - start + 1)))
		{
			while (w > 0)
				free(r[--w]);
			free(r);
			return (0);
		}
		ft_strscpy(r[w], (char *)str + start, end - start);
		start = end + 1;
		w++;
	}
	return (1);
}

char			**ft_strsplit(char const *str, char c)
{
	size_t	words;
	char	**r;

	if (!str)
		return (0);
	words = ft_count_words(str, c);
	if (!words)
	{
		if (!(r = (char *)malloc(sizeof(*r))))
			return (0);
		r[0] = 0;
		return (r);
	}
	if (!(r = malloc((words + 1) * sizeof(*r))))
		return (0);
	if (!ft_cut_words(str, words, r, c))
		return (0);
	r[words] = 0;
	return (r);
}
