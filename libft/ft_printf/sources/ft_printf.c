/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:53:04 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/29 13:56:35 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_how_to_print2(t_qualfrs *ql)
{
	if (ql->typs == TYPES[3] || ql->typs == TYPES[4])
		ft_print_di(ql);
	else if (ql->typs == TYPES[5] || ql->typs == TYPES[8]
	|| ql->typs == TYPES[7])
		ft_print_ox(ql);
	else if (ql->typs == TYPES[6])
		ft_print_u(ql);
	else if (ql->typs == TYPES[12])
		ft_color(ql);
	else if (ql->typs == TYPES[11] || ql->typs == TYPES[16] ||
	ql->typs == TYPES[10] || ql->typs == TYPES[9] ||
	ql->typs == TYPES[17] || ql->typs == TYPES[18])
		ft_print_floats(ql);
	else if (ql->typs == TYPES[15])
		ft_print_b(ql);
	return ;
}

void	ft_how_to_print(t_qualfrs *ql)
{
	if (ql->typs == 0 && (ql->width > 0 || ql->prcs >= 0 || ql->flg->space))
		ft_without_typs(ql);
	else if (ql->typs == TYPES[13])
		ft_print_percent(ql);
	else if (ql->typs == TYPES[0] || ql->typs == TYPES[1]
	|| ql->typs == TYPES[2] || ql->typs == TYPES[14])
	{
		if (ql->typs == TYPES[0])
			ft_print_char(ql);
		else if (ql->typs == TYPES[1] || ql->typs == TYPES[14])
			ft_print_str(ql);
		else if (ql->typs == TYPES[2])
			ft_print_pointer(ql);
	}
	ft_how_to_print2(ql);
	return ;
}

void	ft_create_and_free(t_qualfrs *ql, int f)
{
	if (f == 1)
	{
		ql->len = (t_length*)malloc(sizeof(t_length));
		ql->flg = (t_flag*)malloc(sizeof(t_flag));
		ft_zero_struct(ql);
	}
	else if (f == 2)
	{
		free(ql->flg);
		free(ql->len);
	}
}

void	ft_search_syntax(char *format, t_qualfrs *qual)
{
	char				*ser;
	size_t				i;
	size_t				fls;

	i = 0;
	fls = 0;
	ser = NULL;
	while (!ser && i >= fls && format[i])
	{
		i += ft_flags(&(format)[i], qual);
		i += ft_width(&(format)[i], qual);
		i += ft_precision(&(format)[i], qual);
		i += ft_length(&(format)[i], qual);
		i += ft_zd(&(format)[i], qual);
		if ((ser = ft_types(&(format)[i], qual)))
			i++;
		else
			fls++;
	}
	qual->sformat = &(format)[i];
}

int		ft_printf(const char *format, ...)
{
	t_qualfrs	qual;

	qual.countchr = 0;
	ft_create_and_free(&qual, 1);
	qual.sformat = (char*)format;
	va_start(qual.ap, format);
	while (qual.sformat != NULL && *(qual.sformat))
	{
		if (!(qual.sformat = ft_print_format(qual.sformat, &qual)))
			continue ;
		ft_search_syntax(qual.sformat, &qual);
		ft_how_to_print(&qual);
		ft_zero_struct(&qual);
	}
	ft_create_and_free(&qual, 2);
	va_end(qual.ap);
	return (qual.countchr);
}
