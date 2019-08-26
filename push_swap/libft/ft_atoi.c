/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:24:58 by rrika             #+#    #+#             */
/*   Updated: 2019/08/26 19:10:24 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_error(void)
{
	write(2, "\033[31mError\n\033[0m", 15);
	exit(1);
}

int			ft_atoi(const char *str)
{
	int		i;
	long	n;
	int		s;

	i = 0;
	n = 0;
	s = 1;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			s = -1;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		n = n * 10 + (str[i] - '0');
		if (n * s > 2147483647 || n * s < -2147483648)
			ft_error();
		i++;
	}
	if (!ft_is_space(str[i]) && str[i] >= 32 && str[i] <= 126)
		ft_error();
	return ((unsigned long)n * s);
}
