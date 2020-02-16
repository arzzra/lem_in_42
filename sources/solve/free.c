/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:22:22 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/14 18:25:50 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	free_bonds(t_node *rm)
{
	t_bond	*bn;
	t_bond	*bon;

	if (rm->neig)
	{
		bn = rm->neig;
		while (bn)
		{
			bon = bn;
			bn = bn->next;
			free(bon);
		}
		rm->neig = NULL;
	}
}
