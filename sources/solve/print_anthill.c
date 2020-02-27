/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_anthill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:29:39 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 17:11:12 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	print_all_edges(t_node *curr, t_node *prev)
{
	t_bond	*bn;

	if (curr && curr->status)
	{
		curr->status = 0;
		bn = curr->neig;
		while (bn)
		{
			if (prev != bn->node && bn->node->status)
			{
				ft_printf("%s-%s\n", curr->name, bn->node->name);
			}
			bn = bn->next;
		}
		bn = curr->neig;
		while (bn)
		{
			if (prev != bn->node && bn->node->status)
			{
				print_all_edges(bn->node, curr);
			}
			bn = bn->next;
		}
	}
}

void	print_anthill(t_graph *gh)
{
	t_link	*lk;
	t_node	*nod;

	if (gh->count_ants)
		ft_printf("%d\n", gh->count_ants);
	if (gh->start)
		ft_printf("##start\n%s %d %d\n", gh->start->name,
		gh->start->x, gh->start->y);
	if (gh->end)
		ft_printf("##end\n%s %d %d\n", gh->end->name, gh->end->x, gh->end->y);
	lk = gh->lst_nodes;
	while (lk)
	{
		if (lk->lnk != gh->start && lk->lnk != gh->end)
		{
			nod = (t_node*)lk->lnk;
			ft_printf("%s %d %d\n", nod->name, nod->x, nod->y);
		}
		lk = lk->next;
	}
	print_all_edges(gh->start, NULL);
	ft_printf("\n");
}
