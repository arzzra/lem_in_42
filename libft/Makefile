# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/21 23:08:55 by cdemetra          #+#    #+#              #
#    Updated: 2020/02/22 15:45:20 by cdemetra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

FT_PRINTF =	 ft_printf.c convercions.c length.c\
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
LIBFT =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	ft_strcmp.c ft_strncmp.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c \
	ft_itoa.c ft_atoi.c \
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	ft_lstiter.c ft_lstmap.c \
	ft_lst_size.c ft_lstnpoint.c ft_sort_wordtab.c ft_strlowcase.c ft_str_reverse.c ft_strupcase.c 		ft_lst_contentsearch.c get_next_line.c \

.PHONY: all clean fclean re

RED			=	\033[0;31m
YELLOW		=	\x1B[93m
GREEN		=	\033[0;32m
NC			=	\033[0m
NC1			=	\033[5m
COOL		=	\033[38;5;206;48;5;57m
ANTS		=	\033[38;05;107m
COOL2		=	\033[01;38;05;97m
LAGUNA		=	\033[01;38;05;51m
ORANGE		=	\x1B[38;5;208m
PURPLE		= 	\033[01;38;05;129m

OBJSFD = objects

FT_PRINTF_SRCS = $(addprefix srcs/ft_printf/,$(FT_PRINTF))

LIBFT_SRCS = $(addprefix srcs/,$(LIBFT))

SRCS = $(LIBFT_SRCS) $(FT_PRINTF_SRCS)

OBJECTS = $(LIBFT:.c=.o) $(FT_PRINTF:.c=.o)

OBJS = $(addprefix $(OBJSFD)/, $(OBJECTS))

VPATH =	srcs:srcs/ft_printf

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $(OBJS)
	@ranlib $@
	@echo "✅  $(GREEN)libft.a Created!$(NC) ✅							       $(COOL2)❒$(NC)"
$(OBJSFD):
	@mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	@$(CC) $(CFLAGS) $(HDR) -c $< -o $@

HDR = -I./includes

clean:
	@echo "$(RED)deleting libft object files...$(NC) ✔"
	@echo "$(RED)------------------------------$(NC)"
	@/bin/rm -f $(OBJS)
	@rm -rf $(OBJSFD)

fclean: clean
	@echo "$(RED)deleting libft.a archive...$(NC) ✔"
	@echo "$(RED)---------------------------$(NC)"
	@/bin/rm -f $(NAME)

re: fclean all
