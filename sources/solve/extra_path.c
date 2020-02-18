/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:21:39 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/18 16:38:28 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"



t_link	*copy_t_link_link(t_link *list)
{
	t_link	*ret;
	t_link	*ret2;

	ret = NULL;
	ret2 = NULL;
	if (list)
	{
		while (list)
		{
			if (!ret)
			{
				if (!(ret = malloc_t_link()))
					return (NULL);
				ret->data = list->data;
			}
			else
			{
				if (!(ret2 = malloc_t_link()))
					return (NULL);
				ret2->data = list->data;
				ret->next = ret2;
				ret2->prev = ret;
				ret = ret2;
			}
			if (!(ret->lnk = (void*)copy_t_link_link((void*)list->lnk)))
				return (NULL);
			list = list->next;
		}
	}
}


int		path_needed(t_graph *gh)
{
	t_link	*ljk;
	t_link	*fr;

	if (gh->list_all_paths)
	{
		ljk = gh->list_all_paths;
		while (ljk)
		{
			fr = ljk;
			free_links((t_link*)fr->lnk);
			ljk = ljk->next;
		}
		free_links(gh->list_all_paths);
		if (!(gh->list_all_paths = copy_t_link_link(gh->list_path)))
			return (0);
		else
			return (1);
	}
	return (1);
}

int		need_a_way(t_graph *gh)
{
	int		g;

	if (gh->list_path)
	{
		combine_ways(gh);
		g = (gh->count_ants + summ_paths(gh)) / count_paths(gh);
		if (g < gh->count_steps)
			path_needed(gh);
		else
			return (-1);
	}
	else
		return (0);
}