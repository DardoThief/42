/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:12:53 by rrika             #+#    #+#             */
/*   Updated: 2019/08/23 15:06:27 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = (t_list *)malloc(sizeof(*elem))))
		return (0);
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		if (!(elem->content = malloc(sizeof(content_size))))
		{
			free(elem);
			return (NULL);
		}
		ft_memcpy((elem->content), content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
