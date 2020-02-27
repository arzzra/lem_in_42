/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:22:22 by bcharity          #+#    #+#             */
/*   Updated: 2020/02/27 17:11:59 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	free_bonds_in_room(t_node *room)
{
	if (room)
	{
		free_bonds(room);
		free(room->name);
		free(room);
	}
}

void	free_rooms(t_link *lst)
{
	t_node	*nd;

	if (lst)
	{
		while (lst)
		{
			nd = (t_node*)lst->lnk;
			if (nd->in && nd->out)
			{
				free_bonds_in_room(nd->in);
				free_bonds_in_room(nd->out);
			}
			free_bonds_in_room(nd);
			lst = lst->next;
		}
	}
}

void	free_everythings(t_graph *gh)
{
	t_link	*lk;

	if (gh)
	{
		free_rooms(gh->lst_nodes);
		free_links2(gh->lst_nodes);
		lk = gh->list_path;
		while (lk)
		{
			free_links2((t_link*)lk->lnk);
			lk = lk->next;
		}
		free_links2(gh->list_path);
		lk = gh->list_all_paths;
		while (lk)
		{
			free_links2((t_link*)lk->lnk);
			lk = lk->next;
		}
		free_links2(gh->list_all_paths);
		free(gh->param);
		free(gh);
	}
}

void	free_links(t_link *start, t_link *end)
{
	t_link	*iter;

	while (start)
	{
		iter = start;
		start = start->next;
		if (iter == end)
			return ;
		else
			free(iter);
	}
}
