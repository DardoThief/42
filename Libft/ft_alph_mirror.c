/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alph_mirror.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:52:15 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 12:06:45 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_alph_mirror(char f)
{
	int	index;

	if ('a' <= f && f <= 'z')
	{
		index = f - 'a';
		ft_putchar('z' - index);
	}
	else if ('A' <= f && f <= 'Z')
	{
		index = f - 'A';
		ft_putchar('Z' - index);
	}
	else
		ft_putchar(f);
}
