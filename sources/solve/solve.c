/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:40:13 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/13 16:12:30 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		summ_paths(t_graph *gh)
{
	t_link	*iter;
	int		*paths_len;

	if (gh->list_path)
	{
		iter = gh->list_path;
		while (iter)
		{
			paths_len += iter->data;
			iter = iter->next;
		}
		return (paths_len)''
	}
	return (0);
}

int		count_paths(t_graph *gh)
{
	int		count;
	t_link	*lk;

	count = 0;
	if (gh->list_path)
	{
		lk = gh->list_path;
		while (lk)
		{
			count++;
			lk = lk->next;
		}
		return (count);
	}
	return (0);
}

int		main_solve(t_graph *gh)
{
	int		best;
	int		best2;

	best = 0;
	best2 = 0;
	while (best2 <= best)
	{
		node_dividing(gh);
		ford_bellman(gh);

		save_way(gh);

		best2 = (gh->count_ants + summ_paths(gh)) / count_paths(gh);
	}
	return (1);
}
