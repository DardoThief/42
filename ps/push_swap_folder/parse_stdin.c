/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:45:25 by rrika             #+#    #+#             */
/*   Updated: 2019/07/26 16:42:37 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_getstdin()
{
	int		ret;
	char	*buf;
	char 	*str;
	char	*tmp;

	str = (char*)ft_memalloc(0);
	buf = (char*)ft_memalloc(65);
	while ((ret = read(0, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
	}
	free(buf);
	return (str);
}

void	dupe_check(t_link *s, int n)
{
	while (s)
	{
		if (s->num == n)
			ft_error();
		s = s->next;
	}
}

void	ft_lstend(t_link **a, int num)
{
	t_link	*tmp;
	t_link	*end;

	tmp = malloc(sizeof(t_link));
	tmp->num = num;
	tmp->next = NULL;
	if ((end = *a))
	{
		while (end->next)
			end = end->next;
		end->next = tmp;
	}
	else
		(*a) = tmp;	
}

int		ft_placevalue(int n)
{
	int count;

	count = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

t_link		*parse_stdin()
{
	t_link	*a;
	int		i;
	int		n;
	char	*s;
	char	*tmp;

	i = 0;
	a = NULL;
	s = ft_getstdin();
	tmp = s;
	ft_putendl(s);
	while (*s)
	{
		n = ft_atoi(s);
		dupe_check(a, n);
		ft_lstend(&a, n);
		s += ft_placevalue(n);
		if (ft_is_space(*s))
			s++;
	}
	free(tmp);
	return (a);
}