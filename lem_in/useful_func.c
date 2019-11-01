/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:04:31 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 17:32:30 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_max_min_int(char *buff, t_lem **r)
{
	if (*buff != '-' && ft_strlen(buff) == ft_strlen("2147483647"))
	{
		if (ft_strcmp(buff, "2147483647") > 0)
			ft_lem_del(r);
	}
	else if (*buff != '-' && ft_strlen(buff) > ft_strlen("2147483647"))
	{
		ft_lem_del(r);
	}
	else if (ft_strlen(buff) == ft_strlen("-2147483648"))
	{
		if (ft_strcmp(buff, "-2147483648") > 0)
			ft_lem_del(r);
	}
	else if (ft_strlen(buff) > ft_strlen("-2147483648"))
	{
		ft_lem_del(r);
	}
}

int		ft_strcmp_line(char *str1, char *str2, char c)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return ((*str1 == '\0' ? 0 : (int)*str1) -
					(*str2 == '\0' ? 0 : (int)*str2));
		}
		str1++;
		str2++;
	}
	if (!*str2 && *str1 == c)
		return (0);
	return (1);
}

void	is_number(char **m, t_lem *r, char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || ft_isdigit(str[0]))
	{
		while (str[++i])
		{
			if (!ft_isdigit(str[i]))
				free_array(m, r, 1);
		}
	}
	else
		free_array(m, r, 1);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_lem_del(t_lem **r)
{
	int i;

	i = 0;
	if ((*r)->step > 1)
		while (i < (*r)->vertex)
		{
			if ((*r)->room != NULL && (*r)->room[i].name != NULL)
				free((*r)->room[i].name);
			i++;
		}
	if ((*r)->links != NULL)
		free((*r)->links);
	if ((*r)->room != NULL)
		free((*r)->room);
	if ((*r)->rooms_list != NULL)
		free((*r)->rooms_list);
	if ((*r)->links_list != NULL)
		free((*r)->links_list);
	if ((*r)->line != NULL)
		free((*r)->line);
	free(*r);
	*r = NULL;
	ft_error();
}
