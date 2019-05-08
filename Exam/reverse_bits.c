/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:35:55 by rrika             #+#    #+#             */
/*   Updated: 2019/02/21 12:04:29 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char octet_2;
	
	octet_2 = octet;
	octet = octet << 4;
	octet_2 = octet_2 >> 4;
	octet_2 = octet_2 << 1;
	return (octet | octet_2);
}

int		main(void)
{
	unsigned char c;
	unsigned char d;

	c = 38;
	d = reverse_bits(c);
	printf("Was: %d, become: %d\n", (int)c, (int)d);
	return (0);
}
