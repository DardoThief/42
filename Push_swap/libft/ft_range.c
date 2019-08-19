/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:51:25 by rrika             #+#    #+#             */
/*   Updated: 2019/04/14 12:09:19 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int *arr;
	int i;

	if (!(arr = (int *)malloc(sizeof(int) * (max - min + 1))))
		return (0);
	i = 0;
	while (max >= min)
		arr[++i] = --max;
	return (arr);
}
