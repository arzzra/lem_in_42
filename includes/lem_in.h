/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:14:07 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/04 19:30:47 by cdemetra         ###   ########.fr       */
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

/*
**************************INIT*************************
*******************************************************
*/

/*
** main.c
*/

/*
** additional.c
*/
int					count_split(char **split);
int					is_digit_only(char *str);

/*
** malloc.c
*/
t_link				*malloc_node(char **split);
t_link				*malloc_t_link(void);
int					add_to_room_list(t_node *room, t_link *lnk);
t_graph				*malloc_graph(void);
int					malloc_links(t_node *room1, t_node *room2);
void				free_split(char **split);

/*
** save_way.c
*/
t_link				*reverse_save_way(t_node *end);
void				reset_way(t_node *end); //ИСПРАВЬ на ПОЛНЫЙ ГРАФ
int					save_way(t_graph *gh);

/*
** save.c
*/
int					count_ants(t_graph *gh, char *line);
int					is_that_the_link(char *line);
t_node				*search_node_by_name(t_graph *gh, char *name);
int					create_links_in_rooms(t_graph *gh, char *room1, char *room2);
int				get_link(t_graph *gh, char *line);
t_link				*get_room_coord(t_graph *gh, char **split);
int					is_that_room(t_graph *gh, char *line, int is);
void				add_to_list(t_graph *gh, t_link *node);
int					ft_read_start_end(t_graph *gh, char *line, int fd);
int					save(t_graph *gh, char *name_file);


/*
**************************SOLVE************************
*******************************************************
*/

/*
** solve.c
*/
int					main_solve(t_graph *gh);

/*
** ford_bellman.c
*/
int					ford_bellman(t_graph *gh);
int					ford_relaxing(t_node *room, t_node *par, int cost);



/*
** seacrh_way.c
*/

#endif
