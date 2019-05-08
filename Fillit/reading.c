/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:31:35 by mbernard          #+#    #+#             */
/*   Updated: 2019/05/07 17:16:57 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*reading(const int fd)
{
	t_list	*list;
	t_list	*head;
	int		ret;
	char	buf[21];
	char	a;

	a = 'A';
	list = NULL;
	while ((ret = read(fd, buf, 21)) && ret != -1)
	{
		buf[ret] = '\0';
		if (buf[0] == '\n')
			stop();
		if (a > 'Z')
			stop();
		if (buf[ret - 1] != '\n')
			stop();
		head = createtr(buf, a++, ret);
		push_end(&list, head);
	}
	if (list == NULL || buf[20] == '\n')
		stop();
	return (list);
}

void		push_end(t_list **list, t_list *head)
{
	t_list	*new;

	new = *list;
	if (new == NULL)
	{
		*list = head;
	}
	else
	{
		while (new->next)
		{
			new = new->next;
		}
		new->next = head;
	}
}

int			check_connection(const char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

void		check_counts(const char *str, const int count)
{
	int i;
	int blocks;

	blocks = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				stop();
			if (str[i] == '#' && ++blocks > 4)
				stop();
		}
		else if (str[i] != '\n')
			stop();
		i++;
	}
	if (count == 21 && str[20] != '\n')
		stop();
	if (!check_connection(str))
		stop();
}

void		freeshape(char **shape)
{
	int i;

	i = 0;
	while (i < 5)
		free(shape[i++]);
	free(shape);
}
