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

<<<<<<< HEAD:sources/solve/save_way.c
void	reset_parents(t_graph *gh)
=======
void	reset_way(t_node *end)
>>>>>>> 0c884fd6597d243c1ec66e7cb8baa0ad0a6317ec:sources/solve/save_way.c
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
<<<<<<< HEAD:sources/solve/save_way.c
	}
	else
		gh->list_path = reverse_save_way(gh->end);
	reset_parents(gh);
	return (1);
=======
		reset_way(gh->end);
	}
	else
		gh->list_path = reverse_save_way(gh->end);
    return (1);
>>>>>>> 0c884fd6597d243c1ec66e7cb8baa0ad0a6317ec:sources/solve/save_way.c
}
