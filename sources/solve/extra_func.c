/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:37:57 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/18 16:35:20 by cdemetra         ###   ########.fr       */
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

	lk = gh->list_all_paths;
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