/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:32:59 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/03 18:50:36 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_link	*reverse_save_way(t_node *end)
{
	t_link	*lstk;
	t_link	*lstn;
	t_node	*room;

	lstk = NULL;
	room = end;
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
		room = room->parent;
	}
	return (lstk);
}

//ИСПРАВЬ на ПОЛНЫЙ ГРАФ

void	reset_way(t_node *end)
{
	t_node	*lst;

	while (end)
	{
		lst = end;
		end = end->parent;
		lst->parent = NULL;
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
		reset_way(gh->end);
	}
	else
		gh->list_path = reverse_save_way(gh->end);
    return (1);
}
