# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 16:23:46 by bcharity          #+#    #+#              #
#    Updated: 2020/02/27 21:10:47 by cdemetra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror
LIB_DIR = libft/
HEADER_DIR = includes/

LIB = -L ./libft -lft
LIBPATH = libft/
################ INIT FILES ########################
SRC_INIT = 	main.c \
			free.c \
			free2.c \
			param.c \
			additional.c \
			malloc.c \
			malloc2.c \
			save.c \
			save_rooms.c \
			print_result.c \
			save_links.c

SRC_DIR_INIT =	sources/init/
#################### SOLVE FILES ####################
SRC_SOLVE = solve.c \
			ford_bellman.c \
			save_way.c \
			restore_node.c \
			node_dividing.c \
			march_of_ants.c \
			extra_path.c \
			extra_func.c \
			combine_ways.c \
			print_anthill.c \
			sort_paths.c \
			copy_paths.c


SRC_DIR_SOLVE = sources/solve/
######################################################


OBJ_SOLVE = $(patsubst %.c,%.o,$(SRC_SOLVE))
OBJ_INIT = $(patsubst %.c, %.o, $(SRC_INIT))

OBJ_DIR = obj/
OBJ_DIR_SOLVE = $(OBJ_DIR)o_solve/
OBJ_DIR_INIT = obj/o_init/

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR_SOLVE)%.o: $(SRC_DIR_SOLVE)%.c
	@mkdir -p $(OBJ_DIR_SOLVE)
	@gcc $(FLAGS) -c $< -o $@ -I $(HEADER_DIR)

$(OBJ_DIR_INIT)%.o: $(SRC_DIR_INIT)%.c
		@mkdir -p $(OBJ_DIR_INIT)
		@gcc $(FLAGS) -c $< -o $@ -I $(HEADER_DIR)

$(NAME): $(addprefix $(OBJ_DIR_SOLVE),$(OBJ_SOLVE)) $(addprefix $(OBJ_DIR_INIT),$(OBJ_INIT))
	@make -C $(LIBPATH)
	@gcc $(FLAGS) $(addprefix $(OBJ_DIR_SOLVE),$(OBJ_SOLVE)) $(addprefix $(OBJ_DIR_INIT),$(OBJ_INIT)) $(LIB)  -o $(NAME)

clean:
		@make -C $(LIBPATH) clean
		@rm -Rf $(OBJ_DIR)

fclean: clean
		@make -C $(LIBPATH) fclean
		@rm -f $(NAME)

re: fclean all
