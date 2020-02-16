/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:31:37 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/16 20:36:55 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"


t_link	*matching_node(t_link *lk1, t_link *lk2)
{
	t_link	*iter;

	iter = (t_link*)lk1->lnk;
	while (iter)
	{
		if (iter->lnk == lk2->lnk)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
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

void	cut_and_paste(t_link *path1, t_link *path2)
{
	t_link	*iter1;
	t_link	*iter2;
	t_link	*buffer;

	iter1 = path1;
	iter2 = path2;
	while (iter1 && iter2 && iter1->prev && iter2->next
	&& iter1->prev->lnk == iter2->next->lnk)
	{
		iter1 = iter1->prev;
		iter2 = iter2->next;
	}
	buffer = iter2->next;
	free_links(path2->next, iter2->next);
	path2->next = path1->next;
	path2->next->prev = path2;
	free_links(iter1->next, path1->next);
	iter1->next = buffer;
	iter1->next->prev = iter1;
}



void	search_path_intersection(t_graph *gh, t_link *path)
{
	t_link	*iter;
	t_link	*iter2;
	t_link	*lnk_nods;

	iter = (t_link*)gh->list_path;
	while (iter)
	{
		if (iter != path)
		{
			iter2 = (t_link*)path->lnk;
			while (iter2)
			{
				if (iter2->lnk != gh->start && iter2->lnk != gh->end)
				{
					if ((lnk_nods = matching_node(iter, iter2)))
					{
						cut_and_paste(lnk_nods, iter2);
						return ;
					}
				}
				iter2 = iter2->next;
			}
		}
		iter = iter->next;
	}
}

int		combine_ways(t_graph *gh)
{
	t_link	*last_path;

	if (gh->list_path)
	{
		last_path = gh->list_path;
		while (last_path->next)
			last_path = last_path->next;
		while (last_path)
		{
			search_path_intersection(gh, last_path);
			last_path = last_path->prev;
		}
		return (1);
	}
	return (0);
}
