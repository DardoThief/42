/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:54:54 by rrika             #+#    #+#             */
/*   Updated: 2019/07/03 18:02:10 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     main(int argc, char **argv)
{
    int i;
    int j;
    int k;
    
    if (argc > 1)
    {
        i = 0;
        j = 0;
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        k = i;
        while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            i++;
        while (argv[1][i])
        {
            if (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t') \
            && (argv[1][i - 1] == ' ' || argv[1][i - 1] == '\t'))
            {
                while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
                    write(1, &argv[1][i++], 1);
                write(1, " ", 1);
            }
            i++;
        }
        while (argv[1][k] && (argv[1][k] != ' ' && argv[1][k] != '\t'))
            write(1, &argv[1][k++], 1);
    }
    write(1, "\n", 1);
    return (0);
}