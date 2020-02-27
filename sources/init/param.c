/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:32:08 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 17:12:19 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static int	check_param(t_graph *gh)
{
	if (!gh->param->color && !gh->param->input
	&& !gh->param->move && !gh->param->paths
	&& !gh->param->total_moves)
	{
		ft_printf("Usage ./lem-in [options] < file_name\n");
		ft_printf("Run <./lem-in -help> to see for list options\n");
		return (0);
	}
	return (1);
}

void		parsing(t_graph *gh, char **av, int ac)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], COLOR) == 0)
			gh->param->color = 1;
		else if (ft_strcmp(av[i], ALL_PATHS) == 0)
			gh->param->paths = 1;
		else if (ft_strcmp(av[i], TOTAL_MV) == 0)
			gh->param->total_moves = 1;
		else if (ft_strcmp(av[i], MOVE) == 0)
			gh->param->move = 1;
		else if (ft_strcmp(av[i], INPUT) == 0)
			gh->param->input = 1;
		else if (ft_strcmp(av[i], _HELP) == 0)
			gh->param->help = 1;
		i++;
	}
}

int			parse_param(t_graph *gh, char **av, int ac)
{
	if (ac > 1)
	{
		parsing(gh, av, ac);
		if (check_param(gh) && !(gh->param->help))
			return (1);
		else if (gh->param->help)
		{
			ft_printf("* Usage ./lem-in [options] < file_name\n\n");
			ft_printf("* The options that indicate what to print:\n");
			ft_printf("* -i    show input data\n");
			ft_printf("* -m    show the movement of every ant\n");
			ft_printf("* -t    show total number of moves\n");
			ft_printf("* -p    show all paths and distrubtion ants\n");
			ft_printf("* -c    move each ant in a separate color.");
			ft_printf(" correct works for up to 255 ants.\n");
		}
		return (0);
	}
	return (1);
}
