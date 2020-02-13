/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:05:59 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/10 17:28:22 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_split(char **split)
{
	int		x;

	x = 0;
	while (split[x])
		x++;
	return (x);
}

void	add_to_list(t_graph *gh, t_link *node)
{
	t_link *lst;

	if (!(gh->lst_nodes))
		gh->lst_nodes = node;
	else
	{
		lst = gh->lst_nodes;
		while (lst->next)
			lst = lst->next;
		lst->next = node;
	}
}

int		is_digit_only(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
