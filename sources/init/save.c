/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:37:37 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 19:49:08 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		check_position(t_graph *gh, t_node *n_node)
{
	t_link	*lk;
	t_node	*hh;

	if (n_node)
	{
		lk = gh->lst_nodes;
		while (lk)
		{
			hh = lk->lnk;
			if (hh->x == n_node->x && hh->y == n_node->y)
				return (0);
			lk = lk->next;
		}
	}
	return (1);
}

int		check_maxminint(char **split)
{
	if (split && is_digit_only(split[1]) && is_digit_only(split[2]))
	{
		if (ft_strlen(split[1]) > 1 && ft_atoi(split[1]) == -1)
			return (0);
		else if (ft_strlen(split[2]) > 1 && ft_atoi(split[2]) == -1)
			return (0);
		else
			return (1);
	}
	return (0);
}

int		save(t_graph *gh)
{
	char	*line;
	int		error;
	char	**split;

	error = 1;
	line = NULL;
	while (error && (get_next_line(0, &line)) > 0)
	{
		if (is_digit_only(line) && gh->count_ants == 0)
			error = count_ants(gh, line);
		else if (line[0] == '#' && line[1] == '#'
		&& ((ft_strcmp(line, START) == 0) || (ft_strcmp(line, END) == 0)))
			error = ft_read_start_end(gh, line);
		else if ((split = is_that_room(line)) && gh->count_edges == 0)
			error = save_room(gh, split, 0);
		else if (is_that_the_link(line))
			error = get_link(gh, line);
		else if (line[0] == '#')
			error = 1;
		else
			break ;
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	if (error && gh->start && gh->end && gh->count_ants)
		return (1);
	else
		return (0);
}
