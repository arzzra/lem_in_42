/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:14:07 by cdemetra          #+#    #+#             */
/*   Updated: 2020/02/20 17:25:53 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# include <string.h>
# include <stdio.h>
# include <limits.h>
# define START "##start"
# define END "##end"

# define _IN_ "_in"
# define _OUT_ "_out"

typedef struct		s_link
{
	void			*lnk;
	int				data;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;


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
t_bond				*malloc_bond(void);
int					add_to_room_list(t_node *room, t_bond *lnk);
t_graph				*malloc_graph(void);
int					malloc_links(t_node *room1, t_node *room2);
void				free_split(char **split);

/*
** save_way.c
*/
t_link				*reverse_save_way(t_node *end, t_node *start);
void				reset_way(t_graph *gh); //ИСПРАВЬ на ПОЛНЫЙ ГРАФ
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
** free.c
*/
void	free_bonds(t_node *rm);
void	free_links2(t_link *lk);

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
int					ford_relaxing(t_node *room);

/*
** node_dividing.c
*/

int 	node_dividing(t_graph *gh);

/*
** seacrh_way.c
*/



/*
** restore_node.c
*/

void	restore_nodes(t_graph *gh);

/*
** combine_ways.c
*/

int		combine_ways(t_graph *gh);

/*
** extra_path.c
*/

int		need_a_way(t_graph *gh);
int		distribution_ants(t_link *lk, int ants);

/*
** extra_func.c
*/

int		distance_path(t_link *lk);
int		summ_paths(t_graph *gh);
int		count_paths(t_graph *gh);
void	print_path(t_graph *gh);

/*
** extra_func.c
*/

void	march_of_ants(t_graph *gh);

#endif
