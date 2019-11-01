/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:41:00 by smanhack          #+#    #+#             */
/*   Updated: 2019/10/25 17:14:23 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf_git/ft_printf.h"

typedef struct		s_lis
{
	int				x;
	int				y;
	char			*name;
}					t_lis;

typedef struct		s_brez
{
	int				deltax;
	int				deltay;
	int				signx;
	int				signy;
	int				error;
	int				error2;
}					t_brez;

typedef struct		s_st_end
{
	int				start;
	int				end;
}					t_st_end;

typedef struct		s_add
{
	int				i;
	int				j;
	int				g;
	char			**line;
	char			**w;
}					t_add_r;

typedef struct		s_ants
{
	int				len_way;
	int				index;
	int				x;
	int				y;
	t_brez			*brez;
}					t_ants;

typedef struct		s_way
{
	int				len;
	int				ants;
	t_ants			*param_ant;
	int				*index_ways;
	int				num_ant;
	struct s_way	*next;
}					t_way;

typedef struct		s_proc
{
	int				*way_1;
	int				*way_2;
	int				len_1;
	int				len_2;
	int				len_1_new;
	int				len_2_new;
	int				*buff;
	char			fl;
	int				g;
	t_way			*lst;
	int				i;
	int				j;
}					t_proc;

typedef struct		s_way_out
{
	int				num_ant;
	char			fl;
	char			fl_1;
	int				ants;
}					t_way_out;

typedef struct		s_ways
{
	int				sum_len;
	int				num_ways;
	t_way			*way;
}					t_ways;

typedef struct		s_lem
{
	int				start;
	int				end;
	char			*line;
	int				ants;
	int				step;
	char			*links;
	char			*buff_links;
	char			*links_start;
	char			*commun;
	long long		vertex;
	t_lis			*room;
	char			*rooms_list;
	char			*links_list;
	int				*min_ways;
	int				*peaks_visited;
	int				num_steps;
	t_ways			ways;
}					t_lem;

char				*ft_strcut(char *line, char c);
int					ft_dijkstra(t_lem *m, int begin_index, int end);
void				ft_distribution_ants(t_lem *m);
void				ft_way_out(t_lem *m);
void				ft_suurballe(t_lem *m);
void				ft_path_processing(t_lem *m);
void				lem_im_sdl(t_lem *m);
void				free_array(char **array, t_lem *m, int error);
void				ft_max_min_int(char *buff, t_lem **r);
void				ft_dijkstra_init(t_lem *m, int begin_index);
void				ft_search_min_ways(t_lem *m);
void				ft_min_way(t_lem *m, int end, int begin_index, int *k_len);
void				ft_search_min_ways_2(t_lem *m, int end,
					int begin_index, int k_len);
void				ft_com_links(t_lem *m, int k_len);
void				ft_fill_ways(t_lem *m, int len);
void				ft_suurballe_cpy(t_lem *m);
void				ft_wat_out_print_2_bonus(t_way *lst, t_way_out *w, int i);
void				ft_lem_del(t_lem **r);
char				**create_links_init(int *i, int *flag, t_lem *r);
int					create_links_1(t_lem *r, int *i, int *flag, char **lines);
void				create_links_5(t_lem *r, char **l, char **lines);
void				create_links_4(t_lem *r, char **l, t_st_end *s_e);
void				create_links_3(t_lem *r, char **l, char **lines);
void				create_links_st_end(t_lem *r, char **l,
					char **lines, t_st_end s_e);
void				ft_read(t_lem *r, char **av);
void				add_rooms(t_lem *r);
void				check_start_end(t_lem *r);
void				ft_init_links_st(t_lem *r, char **av);
void				algoritm(t_lem *r);
void				free_mini(t_lem *r);
void				free_all(t_lem *r);
void				is_number(char **m, t_lem *r, char *str);
void				count_ants(t_lem *r, char *line);
void				links(t_lem *r, char *line);
void				rooms_line(t_lem *r, char *line);
void				create_links(t_lem *r, int start, int end);
int					room_index(t_lem *r, char *room_name, int start);
int					check_links(t_lem **r, int x, int y);
void				coordinates(t_lem **r, t_lis *room, char **w, int g);
void				checking_names(t_lem *r, char *name, int g);
void				add_rooms_init(t_lem *r, t_add_r *a);
void				ft_error(void);
void				create_links_2(t_lem *r, int j, char **lines, char **l);

#endif
