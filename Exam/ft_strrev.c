/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:35:37 by rrika             #+#    #+#             */
/*   Updated: 2019/04/18 18:27:23 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
    int i;
    int len;
    char src;

    i = 0;
    len = 0;
    while (str[len])
        len++;
    len -= 1;
    while (len > i)
    {
        src = str[i];
        str[i] = str[len];
        str[len] = src;
        i++;
        len--;
    }
    return (str);
}