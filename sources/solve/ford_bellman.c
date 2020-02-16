/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_bellman.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:07:06 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/14 16:51:08 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		ford_bellman(t_graph *gh)
{
	int		n;
	t_link	*lk;
	int		boool;
	t_node	*rm;

	n = gh->count_rooms;
	while (n > 1)
	{
		boool = 0;
		lk = gh->lst_nodes;
		while (lk)
		{
			rm = (t_node*)lk->lnk;
			if (rm->in && rm->out && !rm->status)
			{
				if (ford_relaxing(rm->out) || ford_relaxing(rm->in))
					boool = 1;
			}
			else if (ford_relaxing(rm))
				boool = 1;
			lk = lk->next;
		}
//		if (boool == 0)
//			break ;
		n--;
	}
	if (gh->end->parent)
		return (1);
	else
		return (0);
}

int		ford_relaxing(t_node *room)
{
	t_bond	*bn;
	t_node	*nod;
	int		boool;

	boool = 0;
	if (room->cost == INT_MAX)
		return (0);
	bn = room->neig;
	while (bn)
	{
		if (bn->activ)
		{
			if (bn->weight == 1 && bn->node->in && bn->node->out)
				nod = bn->node->in;
			else if (bn->weight == -1 && bn->node->in && bn->node->out)
				nod = bn->node->out;
			else
				nod = bn->node;
			if ((room->cost + bn->weight) < nod->cost)
			{
				nod->cost = room->cost + bn->weight;
				nod->parent = room;
				boool = 1;
			}
		}
		bn = bn->next;
	}
	return (boool);
}

