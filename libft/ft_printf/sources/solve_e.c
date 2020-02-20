/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:28:48 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 16:16:52 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	number_pow(long long num)
{
	int			i;
	long long	d;

	d = num;
	if (d < 0)
		d *= -1;
	i = 0;
	while (d)
	{
		d /= 10;
		i++;
	}
	return (i);
}

char		*solve_e(uint64_t *p_i, uint64_t *p_f, char **res_s, t_qualfrs *fmt)
{
	char		*si;
	char		*sf;
	long long	totallen;

	if (fmt->typs == 'e' || fmt->typs == 'E')
		totallen = get_totallen_e(p_i, fmt);
	else
		totallen = fmt->ld->totallen;
	if (!(*res_s = ft_memalloc(totallen + 8 * sizeof(char))))
		return (NULL);
	(*res_s)[totallen - 1] = '\0';
	si = *res_s;
	sf = &(si[fmt->ld->sf_index]);
	save_fp_e(sf, p_i, p_f, fmt);
	save_int_part_e(si, fmt);
	write(1, (*res_s), totallen - 1);
	return (*res_s);
}

char		*put_e_sig(char *p, t_qualfrs *fmt)
{
	*p = (fmt->typs == 'E') ? 'E' : 'e';
	p++;
	if (fmt->ld->e >= 0)
		*(p) = '+';
	else
		*(p) = '-';
	p++;
	if (fmt->ld->e < 0)
		fmt->ld->e *= -1;
	return (p);
}
