/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:21:39 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/20 18:21:16 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	add_to_tlink_list(t_link *head, t_link *lst)
{
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = lst;
		lst->prev = head;
	}
}


t_link	*copy_t_link_link(t_link *list)
{
	t_link	*ret;
	t_link	*ret2;

	ret = NULL;
	if (list)
	{
		while (list)
		{
			if (!ret && (ret = malloc_t_link()))
			{
				ret->lnk = list->lnk;
			}
			else if ((ret2 = malloc_t_link()))
			{
				ret2->lnk = list->lnk;
				add_to_tlink_list(ret, ret2);
			}
			list = list->next;
		}
	}
	return (ret);
}


int		path_needed(t_graph *gh)
{
	t_link	*iter;
	t_link	*rtrn;
	t_link	*lk;

	if (gh->list_path)
	{
		rtrn = NULL;
		iter = gh->list_path;
		while (iter)
		{
			if (!rtrn && (rtrn = malloc_t_link()))
			{
				rtrn->data = iter->data;
				rtrn->lnk = (void*)copy_t_link_link((t_link*)iter->lnk);
			}
			else if ((lk = malloc_t_link()))
			{
				lk->data = iter->data;
				lk->lnk = (void*)copy_t_link_link((t_link*)iter->lnk);
				add_to_tlink_list(rtrn, lk);
			}
			iter = iter->next;
		}
		if (!gh->list_all_paths)
			gh->list_all_paths = rtrn;
		else
		{
			lk = gh->list_all_paths;
			while (lk)
			{
				free_links2((t_link*)lk->lnk);
				lk = lk->next;
			}
			free_links2(gh->list_all_paths);
			gh->list_all_paths = rtrn;
		}
	}
	return (1);
}

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

void	sort_paths(t_graph *gh)
{
	t_link	*lk;
	t_link	*sort;
	t_link	*pt;
	int		minx;

	lk = gh->list_path;
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
	int		y;

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
		    path_needed(gh);
		    return (1);
        }
		else
			return (-1);
	}
	else
		return (0);
}