/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:11:36 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 16:18:51 by cdemetra         ###   ########.fr       */
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

void	free_and_save_new_paths(t_graph *gh, t_link *rtrn)
{
	t_link	*lk;

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

int		path_needed(t_graph *gh)
{
	t_link	*iter;
	t_link	*rtrn;
	t_link	*lk;

	if (!gh->list_path)
		return (0);
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
	free_and_save_new_paths(gh, rtrn);
	return (1);
}
