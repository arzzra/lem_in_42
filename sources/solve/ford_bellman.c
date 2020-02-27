/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_bellman.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:07:06 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 21:10:05 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_node	*choosing_node(t_bond *bn)
{
	if (bn)
	{
		if (bn->weight == 1 && bn->node->in && bn->node->out)
			return (bn->node->in);
		else if (bn->weight == -1 && bn->node->in && bn->node->out)
			return (bn->node->out);
		else
			return (bn->node);
	}
	return (NULL);
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
			nod = choosing_node(bn);
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

void	ford_bellman(t_graph *gh)
{
	int		n;
	t_link	*lk;
	int		boool;
	t_node	*rm;

	n = gh->count_rooms;
	while (n-- > 1)
	{
		boool = 0;
		lk = gh->lst_nodes;
		while (lk)
		{
			rm = (t_node*)lk->lnk;
			if (rm->in && rm->out && !rm->status)
			{
				boool = (ford_relaxing(rm->out) == 1) ? 1 : boool;
				boool = (ford_relaxing(rm->in) == 1) ? 1 : boool;
			}
			else if (ford_relaxing(rm))
				boool = 1;
			lk = lk->next;
		}
		if (boool == 0)
			break ;
	}
}
