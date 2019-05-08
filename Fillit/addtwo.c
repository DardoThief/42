/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtwo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:03:31 by mbernard          #+#    #+#             */
/*   Updated: 2019/05/07 13:10:10 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		moveleft(char **shape, char a)
{
	int		i;
	int		j;
	int		move;

	i = 0;
	j = 0;
	move = 0;
	move = needtomove(shape, a, 0, 0);
	if (move == 0)
		return ;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (shape[i][j] == a)
			{
				shape[i][j - move] = shape[i][j];
				shape[i][j] = '.';
			}
			j++;
		}
		i++;
	}
}

int			needtomove(char **shape, char a, int i, int j)
{
	int n;
	int space;

	i = 0;
	j = 0;
	n = 0;
	space = 0;
	while (j < 4)
	{
		i = 0;
		n = 0;
		while (i < 4)
		{
			if (shape[i][j] == '.')
				n++;
			else if (shape[i][j] == a)
				return (space);
			i++;
		}
		if (n == 4)
			++space;
		j++;
	}
	return (space);
}

void		printdesk(char **desk, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			write(1, &desk[i][j++], 1);
		}
		i++;
		write(1, "\n", 1);
	}
}
