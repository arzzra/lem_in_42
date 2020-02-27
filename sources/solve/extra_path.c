/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:21:39 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 20:54:09 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		zero_fantasy(t_link *lk)
{
	int		curr;
	int		ret;

	ret = 0;
	if (lk)
	{
		curr = lk->data;
		lk = lk->prev;
		while (lk)
		{
			ret = ret + (curr - lk->data);
			lk = lk->prev;
		}
	}
	return (ret);
}

int		distribution_ants(t_link *lk, int ants)
{
	int		g;
	int		leaver;

	leaver = 0;
	if (lk && ants > 0)
	{
		while (lk)
		{
			g = zero_fantasy(lk);
			if (ants > g)
			{
				leaver++;
				ants--;
			}
			else
				return (leaver);
			lk = lk->next;
		}
		return (leaver);
	}
	return (0);
}

int		calculate(t_graph *gh)
{
	int		counter_steps;
	int		ants;

	ants = gh->count_ants;
	counter_steps = 0;
	while (ants)
	{
		ants = ants - distribution_ants(gh->list_path, ants);
		counter_steps++;
	}
	counter_steps += (gh->list_path->data - 1);
	return (counter_steps);
}

int		need_a_way(t_graph *gh)
{
	int		g;

	if (gh->list_path)
	{
		combine_ways(gh);
		summ_paths(gh);
		sort_paths(gh);
		g = calculate(gh);
		if (g <= gh->count_steps)
		{
			gh->count_steps = g;
			if (path_needed(gh))
				return (1);
		}
		else
			return (-1);
	}
	return (0);
}
