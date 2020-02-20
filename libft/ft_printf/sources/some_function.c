/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:43:28 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/29 16:34:08 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_space(int a, t_qualfrs *ql)
{
	while (a > 0)
	{
		write(1, &SPACE, 1);
		a--;
		ql->countchr++;
	}
}

void	ft_print_zero(int a, t_qualfrs *ql)
{
	while (a > 0)
	{
		write(1, &ZERO, 1);
		a--;
		ql->countchr++;
	}
}

void	ft_color(t_qualfrs *ql)
{
	const char	*s;

	s = va_arg(ql->ap, char*);
	if (!ft_strcmp(s, "RED"))
		write(1, "\x1b[31m", 5);
	if (!ft_strcmp(s, "GREEN"))
		write(1, "\x1b[32m", 5);
	if (!ft_strcmp(s, "YELLOW"))
		write(1, "\x1b[33m", 5);
	if (!ft_strcmp(s, "BLUE"))
		write(1, "\x1b[34m", 5);
	if (!ft_strcmp(s, "CYAN"))
		write(1, "\x1b[35m", 5);
	if (!ft_strcmp(s, "MAGENTA"))
		write(1, "\x1b[36m", 5);
	if (!ft_strcmp(s, "RESET"))
		write(1, "\x1b[0m", 4);
}

void	ft_zero_struct(t_qualfrs *ql)
{
	if (ql)
	{
		ql->typs = 0;
		ql->width = 0;
		ql->prcs = -1;
		ql->countnum = 0;
		ql->num = NULL;
		ql->signum = 0;
	}
	ft_zero_struct2(ql);
}

void	ft_zero_struct2(t_qualfrs *ql)
{
	t_flag		*fl;
	t_length	*len;

	fl = ql->flg;
	len = ql->len;
	if (fl)
	{
		fl->sharp = 0;
		fl->zero = 0;
		fl->plus = 0;
		fl->space = 0;
		fl->minus = 0;
	}
	len = ql->len;
	if (len)
	{
		len->l = 0;
		len->h = 0;
		len->bigl = 0;
	}
}
