/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:32:12 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/25 16:59:23 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putwchar(int c)
{
	return (write(1, &c, 1));
}

void	ft_printwchar(wchar_t c, t_qualfrs *ql)
{
	if (c <= 0x7F)
	{
		ql->countchr += ft_putwchar(c);
	}
	else if (c <= 0x7FF)
	{
		ql->countchr += ft_putwchar((c >> 6) + 0xC0);
		ql->countchr += ft_putwchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ql->countchr += ft_putwchar((c >> 12) + 0xE0);
		ql->countchr += ft_putwchar(((c >> 6) & 0x3F) + 0x80);
		ql->countchr += ft_putwchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ql->countchr += ft_putwchar((c >> 18) + 0xF0);
		ql->countchr += ft_putwchar(((c >> 12) & 0x3F) + 0x80);
		ql->countchr += ft_putwchar(((c >> 6) & 0x3F) + 0x80);
		ql->countchr += ft_putwchar((c & 0x3F) + 0x80);
	}
}

size_t	ft_wstrlen(const char *str)
{
	size_t	i;
	wchar_t	*x;

	x = (wchar_t*)str;
	i = 0;
	while (x[i] != '\0')
		i++;
	return (i);
}

void	ft_print_str2(t_qualfrs *ql)
{
	if (ql->width > 0)
	{
		if (ql->flg->minus > 0)
		{
			ft_print_str_uni(ql);
			ft_print_space(ql->width - ql->countnum, ql);
		}
		else
		{
			if (ql->flg->zero)
				ft_print_zero(ql->width - ql->countnum, ql);
			else
				ft_print_space(ql->width - ql->countnum, ql);
			ft_print_str_uni(ql);
		}
	}
	else
		ft_print_str_uni(ql);
}
