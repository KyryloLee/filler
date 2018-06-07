/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:27:54 by klee              #+#    #+#             */
/*   Updated: 2017/12/19 15:34:38 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*correct_list(t_list **plus_str, int fd)
{
	t_list	*tmp;

	tmp = *plus_str;
	if (*plus_str == NULL)
	{
		ft_lstadd(plus_str, ft_lstnew("", fd));
		tmp = *plus_str;
	}
	else
	{
		while (tmp)
			if (tmp->content_size != (size_t)fd)
				tmp = tmp->next;
			else
				return (tmp);
		ft_lstadd(plus_str, ft_lstnew("", fd));
		tmp = *plus_str;
	}
	return (tmp);
}

int		read_file(char **tmlls, int fd)
{
	char				buf[BUFF_SIZE + 1];
	char				*str;
	int					ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		str = *tmlls;
		*tmlls = ft_strjoin(*tmlls, buf);
		free(str);
		if (ft_strchr(*tmlls, '\n'))
			break ;
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static t_list		*plus_str = NULL;
	t_list				*tmp;
	int					ret;
	char				*tmlls;
	int					count;

	count = 0;
	if (!line || (read(fd, "", 0) < 0))
		return (-1);
	tmp = correct_list(&plus_str, fd);
	tmlls = tmp->content;
	if (ft_strlen(tmlls) < BUFF_SIZE)
	{
		ret = read_file(&tmlls, fd);
		if (ret < BUFF_SIZE && !ft_strlen(tmlls))
			return (0);
	}
	count = ft_strchr(tmlls, '\n') ?
		(ft_strchr(tmlls, '\n') - tmlls) : ft_strlen(tmlls);
	tmp->content = ft_strchr(tmlls, '\n') ?
		ft_strdup(ft_strchr(tmlls, '\n') + 1) : 0;
	*line = ft_strsub(tmlls, 0, count);
	free(tmlls);
	return (1);
}
