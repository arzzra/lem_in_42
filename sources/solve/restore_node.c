/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:31:48 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/14 17:12:57 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	restore_nodes(t_graph *gh)
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
				prev->parent = current->main_node;
				prev = current->main_node;
				if (current->main_node->in == current->parent || current->main_node->out == current->parent)
					current =  current->parent->parent;
				else
					current = current->parent;
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
