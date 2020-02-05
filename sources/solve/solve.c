/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:40:13 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/05 20:06:24 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main_solve(t_graph *gh)
{
	int		best;

	best = 0;
	if (ford_bellman(gh))
		printf("solve\n");
	return (1);
}
