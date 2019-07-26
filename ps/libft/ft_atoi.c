/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:24:58 by rrika             #+#    #+#             */
/*   Updated: 2019/04/15 16:03:53 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((ft_is_space(str[i])))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] != '\0') && str[i] >= '0' && (str[i] <= '9'))
	{
		if ((result > 922337203685477580 || (result == 922337203685477580
						&& (str[i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((result > 922337203685477580 || (result == 922337203685477580
						&& (str[i] - '0') > 8)) && sign == -1)
			return (0);
		result = (result * 10) + (str[i++] - '0');
	}
	return ((int)(result * sign));
}
