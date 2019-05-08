/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:46:24 by mbernard          #+#    #+#             */
/*   Updated: 2019/05/07 15:31:53 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkmoveup(char **shape, char a, int i, int j)
{
	int f;
	int space;

	space = 0;
	f = 0;
	while (i < 4)
	{
		j = 0;
		f = 0;
		while (j < 4)
		{
			if (shape[i][j] == '.')
				f++;
			else if (shape[i][j] == a)
				return (space);
			j++;
		}
		if (f == 4)
			++space;
		i++;
	}
	return (space);
}

int		quantity(char **shape, char a)
{
	int i;
	int	j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (shape[i][j] == a)
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

void	moveup(char **shape, char a, int h)
{
	int s;

	s = checkmoveup(shape, a, 0, 0);
	if (s == 3)
	{
		ft_memcpy(shape[0], shape[3], 4);
		default_line(shape[3]);
	}
	else if (s == 2)
	{
		ft_memcpy(shape[0], shape[2], 4);
		ft_memcpy(shape[1], shape[3], 4);
		default_line(shape[2]);
		default_line(shape[3]);
	}
	else if (s == 1)
	{
		dots(shape, h);
	}
}

void	dots(char **shape, int h)
{
	if (h == 1)
	{
		ft_memcpy(shape[0], shape[1], 4);
		default_line(shape[1]);
	}
	else if (h == 2)
	{
		ft_memcpy(shape[0], shape[1], 4);
		default_line(shape[1]);
		ft_memcpy(shape[1], shape[2], 4);
		default_line(shape[2]);
	}
	else if (h == 3)
	{
		ft_memcpy(shape[0], shape[1], 4);
		default_line(shape[1]);
		ft_memcpy(shape[1], shape[2], 4);
		default_line(shape[2]);
		ft_memcpy(shape[2], shape[3], 4);
		default_line(shape[3]);
	}
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
