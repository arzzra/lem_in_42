/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:50:17 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 18:31:02 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_link	*get_room_coord(t_graph *gh, char **split)
{
	t_link	*room;
	t_node	*n_room;

	if ((room = malloc_node(split)))
	{
		n_room = (t_node*)room->lnk;
		if (!(search_node_by_name(gh, n_room->name)) && check_position(gh, n_room))
		{
			add_to_list(gh, room);
			return (room);
		}
		else
		{
			free_rooms(room);
			free_links2(room);
		}
	}
	return (NULL);
}

char	**is_that_room(char *line)
{
	char	**split;

	split = NULL;
	if (line[0] != 'L' && line[0] != '#')
	{
		if ((split = ft_strsplit(line, ' ')) && (count_split(split)) == 3)
			return (split);
		else
		{
			if (split)
				free_split(split);
			return (NULL);
		}
	}
	return (NULL);
}

int		save_start_end(t_graph *gh, t_link *sm, int is)
{
	if (is == 0)
		return (1);
	else if (is == 1 && !gh->start)
	{
		gh->start = sm->lnk;
		gh->start->cost = 0;
		return (1);
	}
	else if (is == 2 && !gh->end)
	{
		gh->end = sm->lnk;
		return (1);
	}
	else
		return (0);
}

int		save_room(t_graph *gh, char **split, int is)
{
	t_link	*sm;

	if (split && gh)
	{
		if (check_maxminint(split) && (sm = get_room_coord(gh, split)))
		{
			free_split(split);
			gh->count_rooms++;
			if (save_start_end(gh, sm, is) == 0)
				return (0);
			return (1);
		}
		else
		{
			free_split(split);
			return (0);
		}
	}
	return (0);
}

int		ft_read_start_end(t_graph *gh, char *line)
{
	int		k;
	char	*buff;
	char	*line2;
	char	**split;

	if ((buff = ft_strdup(&(line)[2])) && get_next_line(0, &line2))
	{
		k = ft_strcmp(line, START) == 0 ? 1 : 2;
		if ((split = is_that_room(line2)) && save_room(gh, split, k))
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
	return (0);
}
