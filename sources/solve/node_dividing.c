/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_dividing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:45:44 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 17:09:51 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	init_zero_bond(t_bond *bony, t_node *d_node)
{
	bony->node = d_node->in;
	bony->weight = 0;
	add_to_room_list(d_node->out, bony);
}

void	relink_inout(t_node *d_node, t_node *nxt, t_node *prev)
{
	d_node->status = 0;
	if (d_node->in->neig)
	{
		d_node->in->neig->node = prev;
		d_node->in->neig->weight = -1;
		d_node->in->status = 1;
	}
	if (d_node->out)
	{
		free_bonds(d_node->out);
		malloc_bonds_out(d_node, nxt, prev);
	}
}

int		dividing_room(t_node *d_node, t_node *nxt, t_node *prev)
{
	if (!(d_node->in) && !(d_node->out))
	{
		if ((d_node->in = malloc_inout_room(d_node->name, 1)) &&
		(d_node->in->neig = malloc_bond()))
		{
			d_node->in->neig->node = prev;
			d_node->in->neig->weight = -1;
			d_node->in->main_node = d_node;
			d_node->in->status = 1;
		}
		else
			return (0);
		if ((d_node->out = malloc_inout_room(d_node->name, 0)))
			malloc_bonds_out(d_node, nxt, prev);
		else
			return (0);
		d_node->status = 0;
	}
	else
		relink_inout(d_node, nxt, prev);
	return (1);
}

int		node_dividing_2(t_graph *gh, t_link *links_room)
{
	t_node	*nod;
	t_node	*prev;

	prev = NULL;
	if (links_room)
	{
		while (links_room)
		{
			nod = (t_node*)links_room->lnk;
			if (links_room->next)
			{
				reverse_edge(nod, (t_node*)links_room->next->lnk);
				if (nod != gh->start && nod != gh->end)
					if (!(dividing_room(nod,
					(t_node*)links_room->next->lnk, prev)))
						return (0);
			}
			prev = nod;
			links_room = links_room->next;
		}
	}
	return (1);
}

int		node_dividing(t_graph *gh)
{
	t_link	*lnk;

	if (gh->list_path)
	{
		lnk = gh->list_path;
		while (lnk)
		{
			if (!(node_dividing_2(gh, (t_link*)lnk->lnk)))
			{
				free_everythings(gh);
				return (0);
			}
			lnk = lnk->next;
		}
	}
	return (1);
}
