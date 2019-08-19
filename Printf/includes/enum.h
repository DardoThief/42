/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:15:46 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 14:37:03 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum	e_spec1
{
	NOTYPE,
	H,
	L,
	HH,
	LL,
	Z,
	J,
	LF,
	SPECFCOUNT
}				t_spec;
typedef enum	e_colors
{
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	EOC
}				t_color;

#endif
