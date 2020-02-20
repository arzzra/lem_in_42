/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:37:57 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/20 17:26:53 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		distance_path(t_link *lk)
{
	int		x;

	x = 0;
	if (lk)
	{
		while(lk->next)
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

int		count_paths(t_graph *gh)
{
	int		count;
	t_link	*lk;

	if (gh->list_path)
	{
		count = 0;
		lk = gh->list_path;
		while (lk)
		{
			count++;
			lk = lk->next;
		}
		return (count);
	}
	return (1);
}

void	print_path(t_graph *gh)
{
	t_link	*lk;
	t_link	*lk2;
	t_node	*nod;
	int 	len;

	lk = gh->list_all_paths;
	if (lk)
	{
		while (lk)
		{
			lk2 = lk->lnk;
			len = distance_path((lk2));
			ft_printf("Dist: %d ", len);
			while (lk2)
			{
				nod = lk2->lnk;
				ft_printf("%s ", nod->name);
				lk2 = lk2->next;
			}
			ft_printf("\n");
			lk = lk->next;
		}
	}
}