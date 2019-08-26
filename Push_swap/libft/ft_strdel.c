/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:41:59 by rrika             #+#    #+#             */
/*   Updated: 2019/08/26 16:30:52 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as && *as)
		ft_memdel((void **)as);
}

char		**ft_free_table(char **str)
{
	int		n;

	n = 0;
	while (str[n])
	{
		free(str[n]);
		n++;
	}
	free(str[n]);
	free(str);
	return (0);
}