/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:40:13 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/20 14:45:52 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int     checker2(t_graph *gh, t_node *nd, t_link *kl)
{
    t_link  *iter1;
    t_link  *iter2;

    iter1 = gh->list_all_paths;
    while (iter1)
    {
        if (iter1 != kl)
        {
            iter2 = iter1->lnk;
            while (iter2)
            {
                if (iter2->lnk == nd)
                    return (1);
                iter2 = iter2->next;
            }
        }
        iter1= iter1->next;
    }
    return (0);
}

int     checker(t_graph *gh)
{
    t_link  *iter1;
    t_link  *iter2;

    iter1 = gh->list_all_paths;
    while (iter1)
    {
        iter2 = iter1->lnk;
        while (iter2)
        {
            if (iter2->lnk != gh->start && iter2->lnk != gh->end && checker2(gh, (t_node*)iter2->lnk, iter1))
                return (1);
            iter2 = iter2->next;
        }
        iter1= iter1->next;
    }
    return (0);
}

int		main_solve(t_graph *gh)
{
	int		best;

	best = 1;
	while (best)
	{
		node_dividing(gh);
		ford_bellman(gh);
		restore_nodes(gh);
		if (!(save_way(gh)))
			break ;
        best = need_a_way(gh);
		if (best == -1)
			break ;
	}
    march_of_ants(gh);
	print_path(gh);
	if (checker(gh))
	    printf("есть пересечение");
    else
        printf ("its OK");
	checker(gh);
	return (1);
}
