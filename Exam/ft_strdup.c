/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:06:56 by rrika             #+#    #+#             */
/*   Updated: 2019/04/18 16:35:30 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i;
    char *str;

    i = 0;
    while (src[i])
        i++;
    if (!(str = (char *)malloc(sizeof(i + 1))))
        return (0);
    else
    {
        i = 0;
        while (src[i])
        {
            str[i] = src[i];
            i++;
        }
    str[i] = '\0';
    }
    return (str);
}