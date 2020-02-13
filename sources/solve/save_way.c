/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:32:59 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/13 14:58:15 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_link	*reverse_save_way(t_node *end)
{
	t_link	*lstk;
	t_link	*lstn;
	t_node	*room;
	int		path_len;

	lstk = NULL;
	room = end;
	path_len = 0;
	while (room)
	{
		if (!lstk && (lstk = malloc_t_link()))
		{
			lstk->lnk = (void*)room;
		}
		else if ((lstn = malloc_t_link()))
		{
			lstn->lnk = (void*)room;
			lstn->next = lstk;
			lstk = lstn;
		}
		else
			return (NULL);
		path_len++;
		room = room->parent;
	}
	if ((lstn = malloc_t_link()))
	{
		lstn->lnk = (void*)lstk;
		lstn->data = path_len;
		return (lstn);
	}
	else
		return (NULL);
}

//ИСПРАВЬ на ПОЛНЫЙ ГРАФ

void	reset_parents(t_graph *gh)
{
	t_node	*nod;
	t_link	*lk;

	lk = gh->lst_nodes;
	while (lk)
	{
		nod = (t_node*)lk->lnk;
		if (nod != gh->start)
		{
			nod->cost = INT_MAX;
			nod->parent = NULL;
		}
		lk = lk->next;
	}
}

int		save_way(t_graph *gh)
{
	t_link	*lst;

	if (gh->list_path)
	{
		lst = gh->list_path;
		while (lst->next)
			lst = lst->next;
		lst->next = reverse_save_way(gh->end);
	}
	else
		gh->list_path = reverse_save_way(gh->end);
	reset_parents(gh);
	return (1);
}
