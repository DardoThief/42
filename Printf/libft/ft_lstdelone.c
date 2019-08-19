/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:01:37 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 15:34:04 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst == 0 || *alst == 0 || del == 0)
		return ;
	del((*alst)->content, (*alst)->content_size);
	(*alst)->content = 0;
	(*alst)->content_size = 0;
	free(*alst);
	*alst = 0;
}
