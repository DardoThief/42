/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:13:06 by rrika             #+#    #+#             */
/*   Updated: 2019/10/25 19:20:03 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

inline void			count_ants(t_lem *r, char *line)
{
	int		i;
	char	*str;

	i = 0;
	r->step = 1;
	if (line[0] == '#')
	{
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
			ft_lem_del(&r);
		return ;
	}
	str = line;
	ft_max_min_int(str, &r);
	if ((r->ants = ft_atoi(str)) <= 0)
		ft_lem_del(&r);
	while (str[i] != '\n' && str[i] != 0)
	{
		if (!ft_isdigit(str[i++]))
			ft_lem_del(&r);
	}
}

void				ft_init(t_lem *r)
{
	r->step = 0;
	r->vertex = 0;
	r->start = -1;
	r->end = -1;
	r->room = NULL;
	r->rooms_list = ft_strnew(1);
	r->links_list = ft_strnew(1);
	r->links_start = NULL;
	r->buff_links = NULL;
	r->commun = NULL;
	r->ants = 0;
	r->links = NULL;
	r->ways.num_ways = 0;
	r->ways.sum_len = 0;
	r->ways.way = NULL;
	r->line = NULL;
	r->min_ways = NULL;
	r->peaks_visited = NULL;
}

inline void			links(t_lem *r, char *line)
{
	char *buff;

	if (r->step == 2)
		r->step = 3;
	buff = r->links_list;
	r->links_list = ft_strjoin(buff, line);
	free(buff);
	buff = r->links_list;
	r->links_list = ft_strjoin(buff, "\n");
	free(buff);
	if (!line[0])
		ft_lem_del(&r);
}

inline void			create_links(t_lem *r, int start, int end)
{
	int			i;
	int			flag;
	char		**l;
	char		**lines;
	t_st_end	s_e;

	s_e.end = end;
	s_e.start = start;
	lines = create_links_init(&i, &flag, r);
	while (lines[i] != 0)
	{
		if (create_links_1(r, &i, &flag, lines) == 0)
			break ;
		l = ft_strsplit(lines[i], '-');
		create_links_5(r, l, lines);
		create_links_4(r, l, &s_e);
		create_links_3(r, l, lines);
		free(l[0]);
		free(l[1]);
		free(l);
		l = NULL;
		i++;
	}
	create_links_st_end(r, l, lines, s_e);
}

int					main(int ac, char **av)
{
	t_lem	*r;

	r = (t_lem *)malloc(sizeof(*r));
	ft_init(r);
	ft_read(r, av);
	add_rooms(r);
	check_start_end(r);
	ft_init_links_st(r, av);
	algoritm(r);
	free(r->links);
	r->links = NULL;
	if (r->ways.way != NULL)
	{
		ft_distribution_ants(r);
		ft_putendl(r->line);
		ft_way_out(r);
		if (av && av[1] && (ft_strcmp(av[1], "-v") == 0))
			lem_im_sdl(r);
	}
	else
		free_mini(r);
	free_all(r);
	return (0);
}
