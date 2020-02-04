/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:01:17 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/02 17:08:20 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_link	*malloc_node(char **split)
{
	t_link	*link;
	t_node	*node;

	link = NULL;
	node = NULL;
	if ((link = (t_link*)malloc(sizeof(t_link))) && (node = (t_node*)malloc(sizeof(t_node))))
	{
		link->lnk = (void*)node;
		link->next = NULL;
		node->name = ft_strdup(split[0]);
		node->x = ft_atoi(split[1]);
		node->y = ft_atoi(split[2]);
		node->cost = INT_MAX;
		node->parent = NULL;
		node->neig = NULL;
	}
	else
	{
		if (link)
			free(link);
		return (NULL);
	}
	return (link);
}

t_link	*malloc_t_link(void)
{
	t_link	*lnk;

	if (lnk = (t_link*)malloc(sizeof(t_link)))
	{
		lnk->lnk = NULL;
		lnk->next = NULL;
		return (lnk);
	}
	else
		return (NULL);
}


int		add_to_room_list(t_node *room, t_link *lnk)
{
	t_link	*itr;

	if (!room->neig)
		room->neig = lnk;
	else
	{
		while (itr->next)
		{
			if (itr == lnk)
				return (0);
			itr = itr->next;
		}
		if (itr == lnk)
			return (0);
		itr->next = lnk;
	}
	return (1);
}

t_graph	*malloc_graph(void)
{
	t_graph	*lst;

	if (lst = (t_graph*)malloc(sizeof(t_graph)))
	{
		lst->count_ants = 0;
		lst->count_rooms = 0;
		lst->lst_nodes = NULL;
		lst->start = NULL;
		lst->end = NULL;
		return (lst);
	}
	else
		return (NULL);
}

int		malloc_links(t_node *room1, t_node *room2)
{
	t_link	*lnk;
	t_link	*lnk2;

	lnk = NULL;
	lnk2 = NULL;
	if (lnk = malloc_t_link(void) && lnk2 = malloc_t_link(void))
	{
		lnk->lnk = room2;
		lnk2->lnk = room1;
		if (add_to_room_list(room1, lnk) && add_to_room_list(room2, lnk2))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

void	free_split(char **split)
{
	int		k;

	if (split)
	{
		k = 0;
		while (split[k])
		{
			free(split[k]);
			k++;
		}
		free(split);
	}
}
