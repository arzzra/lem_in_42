/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:41:08 by cdemetra          #+#    #+#             */
/*   Updated: 2019/06/26 18:15:26 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_lst_fd_search(t_list **lst, const int fd)
{
	t_list	*list;

	list = *lst;
	while (list)
	{
		if (list->content_size == (size_t)fd)
			return (list);
		list = list->next;
	}
	list = ft_lstnew(NULL, 0);
	list->content_size = (size_t)fd;
	list->content = NULL;
	ft_lstadd(lst, list);
	return (list);
}

static	int		ft_end_of_file(char **line, char *str, t_list *list)
{
	char	*endofline;
	size_t	i;

	if (!(endofline = ft_strchr(str, '\n')))
	{
		*line = str;
		list->content = NULL;
		return (1);
	}
	*endofline = '\0';
	*line = ft_strdup(str);
	i = (endofline - str) + 1;
	if (str[i] != '\0')
		list->content = (char*)ft_strdup(&(str[i]));
	else
		list->content = NULL;
	free(str);
	return (1);
}

static	int		ft_copy_of_buffer(char **line, char *buffer,
		t_list *list, char *endofline)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)list->content;
	*endofline = '\0';
	if (str)
	{
		*line = ft_strjoin(str, buffer);
		free(str);
		i = (endofline - &buffer[0]) + 1;
		list->content = (buffer[i] != '\0') ?
		(char*)ft_strdup(&(buffer[i])) : NULL;
		return (1);
	}
	else
	{
		*line = ft_strdup(buffer);
		i = (endofline - &buffer[0]) + 1;
		list->content = (buffer[i] != '\0') ?
		(char*)ft_strdup(&(buffer[i])) : NULL;
		return (1);
	}
}

static	int		ft_reader(const int fd, t_list *list, char **line)
{
	int		countread;
	char	*str;
	char	*endofline;
	char	buffer[BUFF_SIZE + 1];

	if (list->content && ft_strchr((char*)list->content, '\n'))
		return (ft_end_of_file(line, list->content, list));
	while ((countread = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[countread] = '\0';
		if ((endofline = ft_strchr(buffer, '\n')))
			return (ft_copy_of_buffer(line, buffer, list, endofline));
		else
		{
			str = (char*)list->content;
			list->content = (list->content == NULL) ? ft_strdup(buffer) :
			ft_strjoin(list->content, buffer);
			if (str)
				free(str);
		}
	}
	if (list->content)
		return (ft_end_of_file(line, (char*)list->content, list));
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	t_list	*fd_buffer;
	t_list			*list;
	char			x;
	int				erro;

	if (fd < 0 || read(fd, &x, 0) < 0 || !line ||
	!(list = ft_lst_fd_search(&fd_buffer, fd)))
		return (-1);
	erro = ft_reader(fd, list, line);
	if (*line == NULL)
		return (-1);
	if (erro == 0)
		return (0);
	if (erro == 1)
		return (1);
	else
		return (-1);
}
