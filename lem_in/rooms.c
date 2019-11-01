/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:50:54 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 13:51:42 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_room(t_lem *r, char *line)
{
	int		i;
	char	**m;

	i = 0;
	m = ft_strsplit(line, ' ');
	if (m[0][0] == 'L' || m[3] != NULL)
		free_array(m, r, 1);
	is_number(m, r, m[1]);
	is_number(m, r, m[2]);
	free_array(m, r, 0);
}

void	rooms_line(t_lem *r, char *line)
{
	char *buff;

	r->step = 2;
	buff = r->rooms_list;
	r->rooms_list = ft_strjoin(buff, line);
	free(buff);
	buff = r->rooms_list;
	r->rooms_list = ft_strjoin(buff, "\n");
	free(buff);
	if (line[0] == '#')
		return ;
	if (!line[0])
		ft_lem_del(&r);
	check_room(r, line);
	r->vertex++;
}
