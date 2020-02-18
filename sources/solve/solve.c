/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:40:13 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/18 16:36:38 by cdemetra         ###   ########.fr       */
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
		save_way(gh);
		if ((best = need_a_way(gh)) == -1);
			break ;
	}
	print_path(gh);
	return (1);
}
