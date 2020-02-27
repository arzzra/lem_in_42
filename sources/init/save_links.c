/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:30:38 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 17:44:42 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

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

int		check_duplicate_edges(t_node *room1, t_node *room2)
{
	t_bond	*bn;

	bn = room1->neig;
	while (bn)
	{
		if (bn->node == room2)
			return (0);
		bn = bn->next;
	}
	bn = room2->neig;
	while (bn)
	{
		if (bn->node == room1)
			return (0);
		bn = bn->next;
	}
	return (1);
}

int		create_links_in_rooms(t_graph *gh, char *room1, char *room2)
{
	t_node	*room_1;
	t_node	*room_2;

	room_1 = search_node_by_name(gh, room1);
	room_2 = search_node_by_name(gh, room2);
	if (room_1 && room_2)
	{
		if (room_1 != room_2 && check_duplicate_edges(room_1, room_2)
		&& malloc_links(room_1, room_2))
			return (1);
		else
			return (0);
	}
	return (0);
}

int		get_link(t_graph *gh, char *line)
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
		gh->count_edges++;
		return (1);
	}
	else
	{
		free(room2);
		free(room1);
		return (0);
	}
}
