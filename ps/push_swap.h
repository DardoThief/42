/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:09:47 by rrika             #+#    #+#             */
/*   Updated: 2019/07/26 16:50:13 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFF_SIZE 42

# include "stdbool.h"
# include "../libft/libft.h"

typedef struct      s_link
{
    long            num;
    struct s_link	*next;
    
}					t_link;

typedef struct		s_flags
{
	bool			v;
	bool			c;
}					t_flags;

typedef struct 		s_stack
{
	t_link			*a;
	t_link			*b;
	t_flags			flags;
}					t_stack;

char				*g_optarg;
int					g_optind;
int					g_optopt;

t_flags				get_flags(int ac, char **av);

#endif