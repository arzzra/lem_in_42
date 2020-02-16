/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:40:13 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/16 20:05:05 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		distance_path(t_link *lk)
{
	int		x;

	x = 0;
	if (lk)
	{
		while(lk)
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
			paths_len += distance_path(iter->lnk);
			iter = iter->next;
		}
		return (paths_len);
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

void	print_path(t_graph *gh)
{
	t_link	*lk;
	t_link	*lk2;
	t_node	*nod;

	lk = gh->list_path;
	if (lk)
	{
		while (lk)
		{
			lk2 = lk->lnk;
			while (lk2)
			{
				nod = lk2->lnk;
				printf("%s - ", nod->name);
				lk2 = lk2->next;
			}
			printf("\n");
			lk = lk->next;
		}
	}
}

int		main_solve(t_graph *gh)
{
	int		best;
	int		best2;

	best = 0;
	best2 = 4;
	while (best2 > best)
	{
		node_dividing(gh);
		ford_bellman(gh);
		restore_nodes(gh);
		save_way(gh);
		combine_ways(gh);
		print_path(gh);
		best2--;
		// best2 = (summ_paths(gh) + gh->count_ants) / count_paths(gh);
	}
	return (1);
}
