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
<<<<<<< HEAD:sources/init/main.c
//			main_solve(gh);
=======
>>>>>>> 0c884fd6597d243c1ec66e7cb8baa0ad0a6317ec:sources/init/main.c
	}
	else
		exit(0);
}

