/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_dividing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:45:44 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/16 19:51:32 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	reverse_edge(t_node *rm, t_node *rm2)
{
	t_bond	*ed;

	ed = rm->neig;
	while (ed)
	{
		if (ed->node == rm2)
		{
			ed->activ = 0;
			break ;
		}
		ed = ed->next;
	}
}

t_node	*malloc_inout_room(char *name, int f)
{
	t_node	*room;

	room = NULL;
	if ((room = (t_node*)malloc(sizeof(t_node))))
	{
		room->x = 0;
		room->y = 0;
		if (f)
			room->name = ft_strjoin(name, _IN_);
		else
			room->name = ft_strjoin(name, _OUT_);
		room->parent = NULL;
		room->in = NULL;
		room->out = NULL;
		room->neig = NULL;
		room->cost = INT_MAX;
		room->main_node = NULL;
		room->status = 1;
	}
	return (room);
}


int		malloc_bonds_out(t_node *d_node, t_node *nxt, t_node *prev)
{
	t_bond	*bn;
	t_bond	*bony;

	bn = d_node->neig;
	while (bn)
	{
		if (bn->node != nxt && bn->node != prev)
		{
			if ((bony = malloc_bond()))
			{
				bony->node = bn->node;
				add_to_room_list(d_node->out, bony);
			}
		}
		bn = bn->next;
	}
	if ((bony = malloc_bond()))
	{
		bony->node = d_node->in;
		bony->weight = 0;
		add_to_room_list(d_node->out, bony);
	}
	else
		return (0);
	d_node->out->main_node = d_node;
	d_node->out->status = 1;
	return (1);
}

void	relink_inout(t_node *d_node, t_node *nxt, t_node *prev)
{
	t_bond	*bn;

	d_node->status = 0;
	if (d_node->in->neig)
	{
		d_node->in->neig->node = prev;
		d_node->in->neig->weight = -1;
	}
	if (d_node->out)
	{
		free_bonds(d_node->out);
		malloc_bonds_out(d_node, nxt, prev);
	}
}


int		dividing_room(t_node *d_node, t_node *nxt, t_node *prev)
{
	t_bond	*bn;
	t_bond	*bony;

	if (!(d_node->in) && !(d_node->out))
	{
		if ((d_node->in = malloc_inout_room(d_node->name, 1)) && (d_node->in->neig = malloc_bond()))
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
					if (!(dividing_room(nod, (t_node*)links_room->next->lnk, prev)))
						return (0);
			}
			prev = nod;
			links_room = links_room->next;
		}
	}
	return (1);
}

int 	node_dividing(t_graph *gh)
{
	t_node	*nod;
	t_link	*lnk;

	if (gh->list_path)
	{
		lnk = gh->list_path;
		while (lnk)
		{
			if (!(node_dividing_2(gh, (t_link*)lnk->lnk)))
			{
				//тут типа фришим
				write(1, "ggg", 3);
				return (0);
			}
			lnk = lnk->next;
		}
	}
	return (1);
}
