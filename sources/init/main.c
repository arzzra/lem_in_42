/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:53:02 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/05 20:06:23 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(int ac, char **av)
{
	t_graph *gh;

	if (ac == 2 && (gh = malloc_graph()))
	{
		if (save(gh, av[1]))
			main_solve(gh);
//			main_solve(gh);
	}
	else
		exit(0);
}

