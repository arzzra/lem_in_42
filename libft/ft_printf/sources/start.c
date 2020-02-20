/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:00:17 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 15:01:50 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_float(t_qualfrs *fmt, t_ld *un)
{
	long double	d;

	fmt->ld->sign_exp = 1;
	if (fmt->len->bigl)
		d = (long double)va_arg(fmt->ap, long double);
	else
		d = (long double)va_arg(fmt->ap, double);
	un->d = d;
	fmt->ld->d = d;
	fmt->ld->exp = un->bits.exponent - 16383;
	if (fmt->ld->exp < 0)
	{
		fmt->ld->sign_exp = -1;
		fmt->ld->exp *= -1;
	}
	if (un->bits.sign == 1)
		fmt->flg->plus = -1;
	else if (fmt->flg->plus && un->bits.sign == 0)
		fmt->flg->plus = 1;
	else
		fmt->flg->plus = 0;
	if (fmt->prcs == -1)
		fmt->prcs = 6;
	fmt->ld->newmem = 0;
}

void		ft_print_floats(t_qualfrs *fmt)
{
	t_ld	un;
	t_float	ldbl;

	fmt->ld = &ldbl;
	init_float(fmt, &un);
	if (ft_inf_nan(fmt))
		return ;
	divide_and_conquer(&un, fmt);
}

void		divide_and_conquer(t_ld *un, t_qualfrs *fmt)
{
	char		s_int[64 + fmt->ld->exp + 1];
	char		s_frac[64 + fmt->ld->exp + 1];
	uint64_t	tmp;

	s_frac[0] = '\0';
	s_int[0] = '\0';
	tmp = un->bits.mantissa;
	fmt->ld->d = un->d;
	if (fmt->ld->sign_exp > 0)
		replace_bit_max(&tmp, s_int, &(s_frac[0]), fmt);
	else
		replace_bit_min(&tmp, s_frac, 8, fmt->ld->exp);
	conver_parts(s_int, s_frac, fmt);
}

uint64_t	count_zero_after_point(long double d, t_qualfrs *fmt)
{
	size_t		part_int;
	uint64_t	count_0;

	fmt->ld->carry = 0;
	part_int = (size_t)d;
	count_0 = 0;
	if ((d -= part_int) == 0)
		return (count_0);
	while (d < 1)
	{
		d *= 10;
		count_0++;
	}
	if ((size_t)d == 9)
		fmt->ld->carry = 1;
	count_0 -= 1;
	return (count_0);
}

char		*ft_itoa_base_ll(uint64_t dig, int radix)
{
	char		*s;
	static char	res[8 * 8 + 1];
	int			i;

	s = "0123456789abcdef";
	i = 0;
	res[8 * 8] = '\0';
	if (dig == 0)
	{
		res[8 * 8 - 1] = '0';
		return (&(res[8 * 8 - 1]));
	}
	while (dig != 0)
	{
		res[8 * 8 - 1 - i] = s[dig % radix];
		dig /= radix;
		i++;
	}
	return (&(res[8 * 8 - i]));
}
