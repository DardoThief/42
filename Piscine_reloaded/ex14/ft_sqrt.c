/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:45:15 by rrika             #+#    #+#             */
/*   Updated: 2019/04/02 17:53:45 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int n;

	n = 1;
	while (n * n < nb)
		n++;
	if (n * n > nb)
		return (0);
	return (n);
}
