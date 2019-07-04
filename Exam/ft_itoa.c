/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:57:14 by rrika             #+#    #+#             */
/*   Updated: 2019/07/03 15:36:04 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    *ft_itoa(int nbr)
{
    int        len;
    int    n;
    char    *str;

    if (nbr == -2147483648)
        return ("-2147483648");
    len = 0;
    n = nbr;
    while (n != 0)
    {
        n /= 10;
        len += 1;
    }
    n = nbr;
    if (nbr < 0)
    {
        len += 1;
        n *= -1;
    }
    if (!(str = (char *)malloc(sizeof(char) * len + 1)))
        return (NULL);
    str[len] ='\0';
    while (n != 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    if (nbr < 0)
      str[0] = '-';
    return (str);
}

int main()
{
  int nbr = -123;
  
  printf("%s\n", ft_itoa(nbr));
  return (0);
}
