/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:13:53 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 17:11:20 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		without_tlink(t_link *head, t_link *lk)
{
	while (head)
	{
		if (head == lk)
			return (0);
		head = head->prev;
	}
	return (1);
}

t_link	*sort_paths2(t_link *lk, t_link *curr)
{
	t_link	*ret;
	int		f;

	ret = NULL;
	f = INT_MAX;
	while (lk)
	{
		if (without_tlink(curr, lk) && lk->data >= curr->data && lk->data < f)
		{
			ret = lk;
			f = lk->data;
		}
		lk = lk->next;
	}
	return (ret);
}

t_link	*min_path(t_link *lk)
{
	int		minx;
	t_link	*sort;

	sort = NULL;
	minx = INT_MAX;
	while (lk)
	{
		if (lk->data < minx)
		{
			sort = lk;
			minx = lk->data;
		}
		lk = lk->next;
	}
	return (sort);
}

void	sort_paths(t_graph *gh)
{
	t_link	*sort;
	t_link	*pt;

	if ((sort = min_path(gh->list_path)))
	{
		sort->prev = NULL;
		while ((pt = sort_paths2(gh->list_path, sort)))
		{
			pt->prev = sort;
			sort = pt;
		}
		sort->next = NULL;
		while (sort)
		{
			if (sort->prev)
				sort->prev->next = sort;
			gh->list_path = sort;
			sort = sort->prev;
		}
	}
}
