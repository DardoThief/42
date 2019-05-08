/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:39:30 by rrika             #+#    #+#             */
/*   Updated: 2019/04/18 17:04:16 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'm')
                argv[1][i] += 13;
            else if (argv[1][i] >= 'n' && argv[1][i] <= 'z')
                argv[1][i] -= 13;
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'M')
                argv[1][i] += 13;
            else if (argv[1][i] >= 'N' && argv[1][i] <= 'Z')
                argv[1][i] -= 13;
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}