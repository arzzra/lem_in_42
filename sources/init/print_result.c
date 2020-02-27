/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:24:34 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 15:39:56 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	abs_march_2(t_graph *gh, int leaver)
{
	t_link	*iter1;
	t_link	*iter2;

	iter1 = gh->list_all_paths;
	while (iter1 && leaver)
	{
		iter2 = (t_link*)iter1->lnk;
		iter2 = iter2->next;
		if (iter2->data == 0 || iter2->lnk == gh->end)
		{
			leaver--;
			iter1->data2 = iter1->data2 + 1;
		}
		iter1 = iter1->next;
	}
}

void	abs_march(t_graph *gh)
{
	int		ants;
	int		leaver;

	if (gh->list_all_paths)
	{
		ants = gh->count_ants;
		leaver = 0;
		while (ants)
		{
			leaver = distribution_ants(gh->list_all_paths, ants);
			abs_march_2(gh, leaver);
			ants = ants - leaver;
		}
	}
}

void	print_path(t_graph *gh)
{
	t_link	*lk;
	t_link	*lk2;
	t_node	*nod;

	lk = gh->list_all_paths;
	if (!lk)
		return ;
	abs_march(gh);
	printf("*\n* Total paths:%d\n*\n", count_paths(gh->list_all_paths));
	while (lk)
	{
		lk2 = lk->lnk;
		printf("* %d ants to path. Length paths: %d {",
		lk->data2, lk->data);
		while (lk2)
		{
			nod = lk2->lnk;
			printf("%s", nod->name);
			lk2 = lk2->next;
			if (lk2)
				printf(", ");
		}
		printf("}\n");
		lk = lk->next;
	}
}

void	print_total_mov(t_graph *gh)
{
	ft_printf("*\n* Total moves: %d\n*\n", gh->count_steps);
}

void	print_result(t_graph *gh)
{
	if (gh->param->paths == 0 && gh->param->total_moves == 0
	&& gh->param->move == 0 && gh->param->input == 0)
	{
		print_anthill(gh);
		march_of_ants(gh);
	}
	else
	{
		if (gh->param->input)
			print_anthill(gh);
		if (gh->param->move)
			march_of_ants(gh);
		if (gh->param->paths)
			print_path(gh);
		if (gh->param->total_moves)
			print_total_mov(gh);
	}
}
