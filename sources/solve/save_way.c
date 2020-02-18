/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:32:59 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/18 17:00:42 by cdemetra         ###   ########.fr       */
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
			lstk->prev = lstn;
			lstk = lstn;
		}
		else
			return (NULL);
		path_len++;
		room = room->parent;
	}
	room = (t_node*)lstk->lnk;
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
			nod->status = 1;
			if (nod->in && nod->out)
			{
				nod->in->parent = NULL;
				nod->out->parent = NULL;
				nod->in->cost = INT_MAX;
				nod->out->cost = INT_MAX;
				nod->in->status = 0;
				nod->out->status = 0;
			}
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
		lst->next->prev = lst;
	}
	else
		gh->list_path = reverse_save_way(gh->end);
	reset_parents(gh);
	return (1);
}
