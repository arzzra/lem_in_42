/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:05:59 by bcharity          #+#    #+#             */
/*   Updated: 2020/02/27 18:23:01 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

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
		if ((str[i] >= '0' && str[i] <= '9')
		|| str[i] == '-' || str[i] == '+')
			i++;
		else
			return (0);
	}
	return (1);
}

int		add_to_room_list(t_node *room, t_bond *lnk)
{
	t_bond	*itr;

	itr = room->neig;
	if (!room->neig)
		room->neig = lnk;
	else
	{
		while (itr->next)
		{
			if (itr == lnk)
				return (0);
			itr = itr->next;
		}
		if (itr == lnk)
			return (0);
		itr->next = lnk;
	}
	return (1);
}

int		count_ants(t_graph *gh, char *line)
{
	int		x;

	if (gh->count_ants == 0)
	{
		x = 0;
		x = ft_atoi(line);
		gh->count_ants = x;
		if (x > 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
