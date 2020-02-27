/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:01:17 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 18:35:09 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_link	*malloc_node(char **split)
{
	t_link	*link;
	t_node	*node;

	if ((link = (t_link*)malloc(sizeof(t_link)))
	&& (node = (t_node*)malloc(sizeof(t_node))))
	{
		link->lnk = (void*)node;
		link->next = NULL;
		node->name = ft_strdup(split[0]);
		node->x = ft_atoi(split[1]);
		node->y = ft_atoi(split[2]);
		node->cost = INT_MAX;
		node->parent = NULL;
		node->neig = NULL;
		node->main_node = NULL;
		node->in = NULL;
		node->out = NULL;
		node->status = 1;
	}
	else
	{
		if (link)
			free(link);
	}
	return (link);
}

t_param	*malloc_param(void)
{
	t_param	*pr;

	pr = NULL;
	if ((pr = (t_param*)malloc(sizeof(t_param))))
	{
		pr->color = 0;
		pr->input = 0;
		pr->move = 0;
		pr->paths = 0;
		pr->total_moves = 0;
		pr->help = 0;
	}
	return (pr);
}

t_link	*malloc_t_link(void)
{
	t_link	*lnk;

	if ((lnk = (t_link*)malloc(sizeof(t_link))))
	{
		lnk->lnk = NULL;
		lnk->next = NULL;
		lnk->prev = NULL;
		lnk->data = 0;
		lnk->data2 = 0;
		return (lnk);
	}
	else
		return (NULL);
}

t_graph	*malloc_graph(void)
{
	t_graph	*lst;

	if ((lst = (t_graph*)malloc(sizeof(t_graph))))
	{
		lst->count_ants = 0;
		lst->count_rooms = 0;
		lst->count_edges = 0;
		lst->count_steps = INT_MAX;
		lst->lst_nodes = NULL;
		lst->list_path = NULL;
		lst->list_all_paths = NULL;
		lst->start = NULL;
		lst->end = NULL;
		if ((lst->param = malloc_param()))
			return (lst);
		else
			free(lst);
	}
	return (NULL);
}
