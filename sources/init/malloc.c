/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:01:17 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/13 14:54:10 by cdemetra         ###   ########.fr       */
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
		node->in = NULL;
		node->out = NULL;
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

	if ((lnk = (t_link*)malloc(sizeof(t_link))))
	{
		lnk->lnk = NULL;
		lnk->next = NULL;
		lnk->data = 0;
		return (lnk);
	}
	else
		return (NULL);
}


int		add_to_room_list(t_node *room, t_bond *lnk)
{
	t_bond	*itr;

	itr = room->neig;
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

	if ((lst = (t_graph*)malloc(sizeof(t_graph))))
	{
		lst->count_ants = 0;
		lst->count_rooms = 0;
		lst->lst_nodes = NULL;
		lst->list_path = NULL;
		lst->start = NULL;
		lst->end = NULL;
		return (lst);
	}
	else
		return (NULL);
}

t_bond	*malloc_bond(void)
{
	t_bond	*bn;

	bn = NULL;
	if ((bn = (t_bond*)malloc(sizeof(t_bond))))
	{
		bn->weight = 1;
		bn->next = NULL;
		bn->activ = 1;
		bn->node = NULL;
	}
	return (bn);
}

int		malloc_links(t_node *room1, t_node *room2)
{
	t_bond	*bond1;
	t_bond	*bond2;

	if ((bond1 = malloc_bond()) && (bond2 = malloc_bond()))
	{
		bond1->node = room2;
		bond2->node = room1;
		if (add_to_room_list(room1, bond1) && add_to_room_list(room2, bond2))
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
