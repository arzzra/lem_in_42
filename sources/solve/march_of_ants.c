/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   march_of_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:45:36 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 19:12:25 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	write_move(int id, t_node *dist, int color)
{
	if (id && dist)
	{
		if (color)
		{
			ft_printf("\033[38;05;%dmL%d-%s \033[0m", id, id, dist->name);
		}
		else
			ft_printf("L%d-%s ", id, dist->name);
	}
}

int		print_ants_on_way2(t_graph *gh, t_link *iter2)
{
	int		ret;

	ret = 0;
	while (iter2)
	{
		if (iter2->lnk != gh->start && iter2->lnk != gh->end)
		{
			if (iter2->data > 0 && (iter2->next->data == 0
			|| iter2->next->lnk == gh->end))
			{
				write_move(iter2->data, (t_node*)iter2->next->lnk,
				gh->param->color);
				iter2->next->data = iter2->data;
				iter2->data = 0;
				ret++;
			}
		}
		iter2 = iter2->prev;
	}
	return (ret - 1);
}

int		print_ants_on_way(t_graph *gh)
{
	t_link	*iter1;
	t_link	*iter2;
	int		ret;
	int		cr;

	iter1 = gh->list_all_paths;
	ret = 0;
	cr = 0;
	while (iter1)
	{
		iter2 = last_list((t_link*)iter1->lnk);
		cr = print_ants_on_way2(gh, iter2);
		if (cr > ret)
			ret = cr;
		iter1 = iter1->next;
	}
	return (ret);
}

void	print_ants_start(t_graph *gh, int leaver, int *id)
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
			iter2->data = *id;
			write_move(*id, (t_node*)iter2->lnk, gh->param->color);
			leaver--;
			iter1->data2 = iter1->data2 + 1;
			*id = *id + 1;
		}
		iter1 = iter1->next;
	}
}

void	march_of_ants(t_graph *gh)
{
	int		ants;
	int		steps;
	int		going;
	int		leaver;
	int		id;

	if (gh->list_all_paths)
	{
		steps = 0;
		ants = gh->count_ants;
		id = 1;
		while (ants || going > 0)
		{
			going = print_ants_on_way(gh);
			if ((leaver = distribution_ants(gh->list_all_paths, ants)))
				going = 1;
			print_ants_start(gh, leaver, &id);
			write(1, "\n", 1);
			ants = ants - leaver;
			steps++;
		}
		gh->count_steps = steps;
	}
}
