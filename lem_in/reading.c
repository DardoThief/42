/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:02:19 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 19:02:16 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	ft_read_bonus(t_lem *r, char *line)
{
	char *buff;

	buff = r->line;
	r->line = ft_strjoin(buff, line);
	free(buff);
	buff = r->line;
	r->line = ft_strjoin(buff, "\n");
	free(buff);
	if (r->ants == 0)
		count_ants(r, line);
	else if (ft_strchr(line, '-') || r->step == 3)
		links(r, line);
	else if (r->step == 1 || r->step == 2)
		rooms_line(r, line);
	else
	{
		free(line);
		ft_lem_del(&r);
	}
}

void				ft_read(t_lem *r, char **av)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = 0;
	if (av && av[1] && ft_strcmp(av[1], "-f") == 0 && av[2])
		fd = open(av[2], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_read_bonus(r, line);
		if (line != NULL)
			free(line);
		line = NULL;
	}
	if (fd != 0)
		close(fd);
	if (!r->ants)
	{
		free(line);
		ft_lem_del(&r);
	}
}
