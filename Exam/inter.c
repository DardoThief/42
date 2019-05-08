/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:07:31 by rrika             #+#    #+#             */
/*   Updated: 2019/04/18 17:35:19 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check(char *str, char c, int pos)
{
    int i;

    i = 0;
    while (i < pos)
    {
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}

int    main(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (argc == 3)
    {
        while (argv[1][i])
        {
            if (argv[1][i] == argv[2][j])
            {
                if (check(argv[1], argv[1][i], i))
                    write(1, &argv[1][i], 1);
            }
            j++;
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}