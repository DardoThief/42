/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:45:09 by rrika             #+#    #+#             */
/*   Updated: 2019/08/09 14:45:13 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

static char			*ft_strccpy(char *dst, const char *src, char c)
{
	int				i;

	i = -1;
	while (src[++i] && (src[i] != c))
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

static t_list		*assign_save(t_list **save, int fd)
{
	t_list			*tmp;

	tmp = *save;
	while (tmp)
	{
		if ((int)(tmp->content_size) == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", 0);
	ft_lstadd(save, tmp);
	return (*save);
}

static void			cleanup(t_list *ptr)
{
	char			*tmp;

	if ((tmp = ft_strchr(ptr->content, '\n')))
	{
		tmp = ft_strdup(tmp + 1);
		free(ptr->content);
		ptr->content = tmp;
	}
	else
		ft_strclr(ptr->content);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				check;
	static t_list	*save;
	t_list			*ptr;

	ERROR_CHECK(fd < 0 || line == NULL || read(fd, buf, 0) < 0);
	ptr = assign_save(&save, fd);
	while ((check = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[check] = '\0';
		ERROR_CHECK(!(tmp = ft_strjoin(ptr->content, buf)));
		free(ptr->content);
		ptr->content = tmp;
		BREAK_CHECK((ft_strchr(ptr->content, '\n')));
	}
	if (!check && !ft_strlen(ptr->content))
	{
		ft_strclr(*line);
		return (0);
	}
	ERROR_CHECK(!(*line = ft_strnew(ft_strlen(ptr->content))));
	*line = ft_strccpy(*line, ptr->content, '\n');
	cleanup(ptr);
	return (1);
}
