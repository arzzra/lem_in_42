/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:37:37 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/04 17:39:38 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_ants(t_graph *gh, char *line)
{
	int		x;

	if (is_digit_only(line))
	{
		x = 0;
		x = ft_atoi(line);
		gh->count_ants = x;
		if (x)
			return (x);
		else
			return (0);
	}
	return (0);
}


int		is_that_the_link(char *line)
{
	if (!(ft_strchr(line, '#')) && ft_strchr(line, '-'))
		return (1);
	else
		return (0);
}

t_node	*search_node_by_name(t_graph *gh, char *name)
{
	t_link *lnk;
	t_node *room;

	lnk = gh->lst_nodes;
	while (lnk && lnk->lnk)
	{
		room = lnk->lnk;
		if (ft_strcmp(room->name, name) == 0)
			return (room);
		lnk = lnk->next;
	}
	return (NULL);
}



int		create_links_in_rooms(t_graph *gh, char *room1, char *room2)
{
	t_node	*room_1;
	t_node	*room_2;
	t_link	*lnk;

	if ((room_1 = search_node_by_name(gh, room1)) && (room_2 = search_node_by_name(gh, room2)))
	{
		if (room_1 != room_2 && malloc_links(room_1, room_2))
			return (1);
		else
			return (0);
	}
	return (2);
}

int 	get_link(t_graph *gh, char *line)
{
	char	*defis;
	char	*room1;
	char	*room2;

	defis = ft_strchr(line, '-');
	*defis = '\0';
	room1 = ft_strdup(line);
	defis++;
	room2 = ft_strdup(defis);
	if (create_links_in_rooms(gh, room1, room2))
	{
		free(room2);
		free(room1);
		return (1);
	}
	else
	{
		free(room2);
		free(room1);
		return (0);
	}
}

t_link	*get_room_coord(t_graph *gh, char **split)
{
	t_link	*room;

	if ((room = malloc_node(split)))
	{
		add_to_list(gh, room);
		return (room);
	}
	else
		return (NULL);
}

int		is_that_room(t_graph *gh, char *line, int is)
{
	char	**split;
	t_link	*sm;

	if (line[0] != 'L' && line[0] != '#')
	{
		if ((split = ft_strsplit(line, ' ')) && (count_split(split)) == 3 && (sm = get_room_coord(gh, split)))
		{
			free_split(split);
			if (is == 1)
			{
				gh->start = sm->lnk;
				gh->start->cost = 0;
			}
			else if (is == 2)
				gh->end = sm->lnk;
			return (1);
		}
		else
		{
			return (0);
			free_split(split);
		}
	}
	return (0);
}

int		ft_read_start_end(t_graph *gh, char *line, int fd)
{
	int		k;
	char	*buff;
	char	*line2;

	if ((!(ft_strcmp(line, START)) || !(ft_strcmp(line, END)))
	&& (buff = ft_strdup(&(line)[2])) && get_next_line(fd, &line2))
	{
		k = ft_strcmp(line, START) == 0 ? 1 : 2;
		if (is_that_room(gh, line2, k))
		{
			free(line2);
			free(buff);
			return (1);
		}
		else
		{
			free(line2);
			free(buff);
			return (0);
		}
	}
	else
		return (0);
}

int		save(t_graph *gh, char *name_file)
{
	int		fd;
	char	*line;

	fd = open(name_file, O_RDONLY);

	while (get_next_line(fd, &line))
	{
		if (line[0] == '#' && line[1] == '#')
			ft_read_start_end(gh, line, fd);
		else if (gh->count_ants == 0)
			count_ants(gh, line);
		else if (is_that_the_link(line))
			get_link(gh, line);
		else if (is_that_room(gh, line, 0))
			gh->count_rooms++;
		free(line);
	}
	return (1);
}
