/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:27:25 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 15:29:41 by cdemetra         ###   ########.fr       */
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

void	free_split(char **split)
{
	int		k;

	if (split)
	{
		k = 0;
		while (split[k])
		{
			free(split[k]);
			k++;
		}
		free(split);
		split = NULL;
	}
}

void	free_links2(t_link *lk)
{
	t_link	*fr;

	if (lk)
	{
		while (lk)
		{
			fr = lk;
			lk = lk->next;
			free(fr);
		}
	}
}
