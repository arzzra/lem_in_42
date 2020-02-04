/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:14:07 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/02 17:08:20 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <limits.h>
# define START "##start"
# define END "##end"


typedef struct		s_link
{
	void			*lnk;
	struct s_link	*next;
}					t_link;


typedef struct		s_node
{
	char			*name;
	int				x;
	int				y;
	int				cost;
	struct s_link	*neig;
	struct s_node	*parent;
}					t_node;

typedef struct		s_bond
{
	int				weight;
	struct s_node	*node;
}					t_bond;

typedef struct		s_graph
{
	struct s_link	*lst_nodes;
	int				count_ants;
	int				count_rooms;
	int				count_edges;
	struct s_link	*list_path;
	struct s_node	*start;
	struct s_node	*end;

}					t_graph;


#endif
