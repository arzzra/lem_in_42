/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:53:02 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 17:03:47 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void	print_error(t_graph *gh)
{
	ft_printf("Error!\n");
	if (gh->count_ants <= 0)
		ft_printf("Invalid number of ants!\n");
	if (gh->count_rooms == 0 && gh->count_ants > 0)
		ft_printf("Invalid number of rooms!\n");
	if ((!gh->start || !gh->end) && gh->count_ants > 0)
		ft_printf("Invalid start or end!\n");
	else if (!gh->list_all_paths && gh->count_ants > 0 && gh->start)
		ft_printf("There is no path or incorrect input\n");
}

int			main(int ac, char **av)
{
	t_graph *gh;

	if ((gh = malloc_graph()))
	{
		if ((parse_param(gh, av, ac)))
		{
			if ((save(gh)) && (main_solve(gh)))
				print_result(gh);
			else
				print_error(gh);
		}
		free_everythings(gh);
		exit(0);
	}
	return (0);
}
