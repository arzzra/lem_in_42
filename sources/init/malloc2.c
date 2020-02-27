/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:40:33 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 18:26:53 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

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

	if ((bond1 = malloc_bond())
	&& (bond2 = malloc_bond()))
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
		init_zero_bond(bony, d_node);
	else
		return (0);
	d_node->out->main_node = d_node;
	d_node->out->status = 1;
	return (1);
}
