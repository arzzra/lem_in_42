# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/16 16:33:59 by cdemetra          #+#    #+#              #
#    Updated: 2019/09/29 12:25:00 by bcharity         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = ft_printf.c convercions.c length.c\
		parser.c print_format_csp.c print_int.c\
		print_int2.c print_ox.c print_ox2.c\
		print_u.c additional.c\
		some_function.c\
		save_int_part_e.c solve_e.c solve_f.c\
		save_frac_part.c fill_res.c long_operation.c\
		long_operation_2.c\
		div_mod_l.c div_mod_l_2.c convert_mantiss.c print_int_part.c\
		buffer.c start.c convert_bin_frac_part.c\
		itoa2.c print_g.c save_frac_part_e.c\
		fill_e_end.c conver_parts.c round_line.c\
		get_totallen.c convert_bin_frac_part.c\
		itoa2.c print_g.c print_b.c\
		additional2.c


SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
