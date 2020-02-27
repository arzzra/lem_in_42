/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:31:48 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/26 19:17:30 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void	restore_nodes_1(t_node **current, t_node **prev)
{
	t_node	*cr;
	t_node	*pr;

	cr = *current;
	pr = *prev;
	pr->parent = cr->main_node;
	pr = cr->main_node;
	if (cr->main_node->in == cr->parent ||
	cr->main_node->out == cr->parent)
		cr = cr->parent->parent;
	else
		cr = cr->parent;
	*current = cr;
	*prev = pr;
}

void		restore_nodes(t_graph *gh)
{
	t_node	*current;
	t_node	*prev;

	current = gh->end;
	prev = NULL;
	if (current)
	{
		while (current)
		{
			if (current->main_node)
			{
				restore_nodes_1(&current, &prev);
			}
			else
			{
				if (prev && !prev->parent)
					prev->parent = current;
				prev = current;
				current = current->parent;
			}
		}
	}
}
