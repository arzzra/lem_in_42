/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:40:13 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/25 19:01:34 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

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
	reset_parents(gh);
	if (gh->list_all_paths)
		return (1);
	else
		return (0);
}
