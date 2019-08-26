/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:09:47 by rrika             #+#    #+#             */
/*   Updated: 2019/08/26 17:34:05 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stdbool.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# define ERROR_CHECK(x) if (x) return (-1)
# define BREAK_CHECK(x) if (x) break

int					get_next_line(const int fd, char **line);

typedef struct		s_link
{
	long			num;
	struct s_link	*next;
}					t_link;

typedef struct		s_flags
{
	bool			v;
	bool			c;
}					t_flags;

typedef struct		s_stack
{
	t_link			*a;
	t_link			*b;
	t_flags			flags;
}					t_stack;

void				get_flags(int k, char *av, t_stack *stack);
int					check_mod(char *str, int n);
t_flags				init_flags();

void				ft_lstfree(t_link **s);
int					ft_lstsize(t_link *a);
int					ft_lstmax(t_link *s);
int					ft_lstmin(t_link *s);
int					ft_lstsorted(t_link *s);

t_link				*parse_args(int k, int ac, char **av);
void				ft_lstprint(t_link *a);

void				dupe_check(t_link *s, int n);
void				ft_lstend(t_link **a, int num);
int					ft_placevalue(int n);

void				sa_ra_sort(t_stack *stack);
void				pa_pb_sort(t_stack *stack);
void				pb_ra_sort(t_stack *stack, int lmax);
void				sorting_hat(t_stack *stack);

void				fdis(char *cmd, t_link **a, t_link **b, char prog);
void				print_status(char *cmd, t_link **a, t_link **b, \
		t_flags flags);
void				action(char *cmd, t_link **a, t_link **b, t_flags flags);
int					is_sorted(t_link *s);

void				fix_a(t_stack *stack);
void				fix_b(t_stack *stack);
void				prep_a(t_stack *stack);
void				prep_b(t_stack *stack);

void				rot_loop(char s, t_stack *stack, int c, t_flags flags);
void				revrot_loop(char s, t_stack *stack, int c, t_flags flags);
void				loop_n(char s, t_stack *stack, int c, t_flags flags);
void				back_to_a(t_link **a, t_link **b, t_flags flags);
int					stack_contains(t_link *s, int lmax);

void				sa(t_link **a, char prog);
void				sb(t_link **b, char prog);
void				ss(t_link **a, t_link **b, char prog);
void				pa(t_link **a, t_link **b, char prog);
void				pb(t_link **a, t_link **b, char prog);

void				ra(t_link **a, char prog);
void				rb(t_link **b, char prog);
void				rr(t_link **a, t_link **b, char prog);
void				ft_lstrot(t_link **stack);
void				ft_lstswp(t_link **stack);

void				rra(t_link **a, char prog);
void				rrb(t_link **b, char prog);
void				rrr(t_link **a, t_link **b, char prog);
void				ft_lstrevrot(t_link **stack);
void				ft_lstpush(t_link **a, t_link **b);

#endif
