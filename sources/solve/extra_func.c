/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:37:57 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 16:09:51 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		distance_path(t_link *lk)
{
	int		x;

	x = 0;
	if (lk)
	{
		while (lk->next)
		{
			x++;
			lk = lk->next;
		}
	}
	return (x);
}

int		summ_paths(t_graph *gh)
{
	t_link	*iter;
	int		paths_len;

	paths_len = 0;
	if (gh->list_path)
	{
		iter = gh->list_path;
		while (iter)
		{
			iter->data = distance_path(iter->lnk);
			paths_len += iter->data;
			iter = iter->next;
		}
		return (paths_len);
	}
	return (0);
}

int		count_paths(t_link *lk)
{
	int		count;

	if (lk)
	{
		count = 0;
		while (lk)
		{
			count++;
			lk = lk->next;
		}
		return (count);
	}
	return (1);
}

t_link	*last_list(t_link *lk)
{
	if (lk)
	{
		while (lk->next)
			lk = lk->next;
	}
	return (lk);
}

void	reverse_edge(t_node *rm, t_node *rm2)
{
	t_bond	*ed;

	ed = rm->neig;
	while (ed)
	{
		if (ed->node == rm2)
		{
			ed->activ = 0;
			break ;
		}
		ed = ed->next;
	}
}
