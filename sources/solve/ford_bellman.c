/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_bellman.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:07:06 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/03 19:22:31 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ford_bellman(t_graph *gh)
{
	int		n;

	n = gh->count_rooms;
	while (n > 1)
	{
		ford_relaxing(gh->start, NULL, 0);
		n--;
	}
	if (gh->end->parent)
		return (1);
	else
		return (0);
}

int		ford_relaxing(t_node *room, t_node *par, int cost)
{
	t_link	*lnk;
	t_node	*node;
	t_bond	*bon;

	lnk = room->neig;
	if (cost < room->cost)
	{
		room->cost = cost;
		room->parent = par;
	}
	while (lnk)
	{
		bon = (t_bond*)lnk->lnk;
		node = bon->node;
		if (node != par)
		{
			ford_relaxing(node, room, room->cost + bon->weight);
		}
		lnk = lnk->next;
	}
}

