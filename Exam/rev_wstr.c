/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:23:19 by rrika             #+#    #+#             */
/*   Updated: 2019/07/03 16:47:58 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     main(int argc, char **argv)
{
    int i;
    int j;
    int num;
    char words[256][4096];

    if (argc == 2)
    {
        i = 0;
        j = 0;
        num = 0;
        while (argv[1][i])
        {
            if (argv[1][i] == ' ')
            {
                num++;
                i++;
                j = 0;
            }
            words[num][j] = argv[1][i];
            i++;
            j++;
        }
        j = 0;
        while (num >= 0)
        {
            if (words[num][j] == '\0')
            {
                if (num > 0)
                    write(1, " ", 1);
                if (num == 0 && words[num][j] == '\0')
                    break ;
                num--;
                j = 0;
            }
            write(1, &words[num][j], 1);
            j++;
        }
    }
    write(1, "\n", 1);
    return (0);
}