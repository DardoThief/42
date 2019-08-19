/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:17:47 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 15:33:57 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	list = *alst;
	if (alst == 0 || *alst == 0 || del == 0)
		return ;
	while ((*alst)->next != NULL)
	{
		list = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = list;
	}
	ft_lstdelone(alst, del);
}
