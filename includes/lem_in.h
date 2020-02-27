/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:14:07 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/27 18:35:49 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <string.h>
# include <stdio.h>
# include <limits.h>
# define START "##start"
# define END "##end"

# define _IN_ "_in"
# define _OUT_ "_out"

# define COLOR "-c"
# define ALL_PATHS "-p"
# define TOTAL_MV "-t"
# define MOVE "-m"
# define INPUT "-i"
# define _HELP	"-help"

typedef struct		s_link
{
	void			*lnk;
	int				data;
	int				data2;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_param
{
	int				color;
	int				paths;
	int				total_moves;
	int				move;
	int				input;
	int				help;
}					t_param;

typedef struct		s_node
{
	char			*name;
	int				x;
	int				y;
	int				cost;
	int				status;
	struct s_node	*main_node;
	struct s_node	*in;
	struct s_node	*out;
	struct s_bond	*neig;
	struct s_node	*parent;
}					t_node;

typedef struct		s_bond
{
	int				weight;
	int				activ;
	struct s_node	*node;
	struct s_bond	*next;
}					t_bond;

typedef struct		s_graph
{
	struct s_link	*lst_nodes;
	int				count_ants;
	int				count_rooms;
	int				count_edges;
	int				count_steps;
	struct s_param	*param;
	struct s_link	*list_path;
	struct s_link	*list_all_paths;
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

int					main(int ac, char **av);

/*
** additional.c
*/

int					count_split(char **split);
int					is_digit_only(char *str);
void				add_to_list(t_graph *gh, t_link *node);
int					add_to_room_list(t_node *room, t_bond *lnk);
int					count_ants(t_graph *gh, char *line);

/*
** malloc.c
*/

t_link				*malloc_node(char **split);
t_param				*malloc_param(void);
t_link				*malloc_t_link(void);
t_graph				*malloc_graph(void);

/*
** malloc2.c
*/

t_bond				*malloc_bond(void);
int					malloc_links(t_node *room1, t_node *room2);
t_node				*malloc_inout_room(char *name, int f);
int					malloc_bonds_out(t_node *d_node, t_node *nxt, t_node *prev);

/*
** save.c
*/

int					save(t_graph *gh);
int					check_position(t_graph *gh, t_node *n_node);
int					check_maxminint(char **split);

/*
** free.c
*/

void				free_bonds_in_room(t_node *room);
void				free_rooms(t_link *lst);
void				free_everythings(t_graph *gh);
void				free_links(t_link *start, t_link *end);

/*
** free2.c
*/

void				free_bonds(t_node *rm);
void				free_split(char **split);
void				free_links2(t_link *lk);

/*
** save_links.c
*/

int					is_that_the_link(char *line);
int					get_link(t_graph *gh, char *line);
t_node				*search_node_by_name(t_graph *gh, char *name);
int					check_duplicate_edges(t_node *room1, t_node *room2);
int					create_links_in_rooms(t_graph *gh, char *room1, char *room2);

/*
** print_result.c
*/

void				print_result(t_graph *gh);

/*
** param.c
*/

int					parse_param(t_graph *gh, char **av, int ac);

/*
** save_rooms.c
*/

t_link				*get_room_coord(t_graph *gh, char **split);
char				**is_that_room(char *line);
int					save_start_end(t_graph *gh, t_link *sm, int is);
int					save_room(t_graph *gh, char **split, int is);
int					ft_read_start_end(t_graph *gh, char *line);

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

void				ford_bellman(t_graph *gh);

/*
** node_dividing.c
*/

int					node_dividing(t_graph *gh);
void				init_zero_bond(t_bond *bony, t_node *d_node);

/*
** restore_node.c
*/

void				restore_nodes(t_graph *gh);

/*
** combine_ways.c
*/

int					combine_ways(t_graph *gh);

/*
** extra_path.c
*/

int					need_a_way(t_graph *gh);
int					distribution_ants(t_link *lk, int ants);

/*
** extra_func.c
*/

int					distance_path(t_link *lk);
int					summ_paths(t_graph *gh);
int					count_paths(t_link *lk);
t_link				*last_list(t_link *lk);
void				reverse_edge(t_node *rm, t_node *rm2);


/*
** march_of_ants.c
*/

void				march_of_ants(t_graph *gh);

/*
** print_anthill.c
*/

void				print_anthill(t_graph *gh);

/*
** copy_paths.c
*/

int					path_needed(t_graph *gh);

/*
** save_way.c
*/

int					save_way(t_graph *gh);
void				reset_parents(t_graph *gh);

/*
** sort_paths.c
*/

void				sort_paths(t_graph *gh);

#endif
