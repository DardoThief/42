/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:31:43 by rrika             #+#    #+#             */
/*   Updated: 2019/02/20 17:42:07 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char swap_bits(unsigned char c)
{
	unsigned char d;

	d = c;
	c = c << 4;
	d = d >> 4;
	return (c | d);
}

int	main(void)
{
	unsigned char c;
	unsigned char swoped_c;

	c = 'a';
	swoped_c = swap_bits(c);
	printf("Was: %d, Be: %d\n", (int)c, (int)swoped_c);
	return (0);
}
