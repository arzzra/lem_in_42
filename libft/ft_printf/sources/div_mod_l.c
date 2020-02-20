/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_mod_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:15:54 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 14:17:26 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		some_actns(t_div_coef *coef, uint64_t *ba, uint64_t *bb, unsigned i)
{
	long long	t;

	coef->temp1 = bb[i + 1] * coef->qguess + coef->carry;
	coef->carry = coef->temp1 / BASE;
	coef->temp1 -= coef->carry * BASE;
	t = ba[coef->vj + i] - coef->temp1 + coef->borrow;
	coef->temp2 = t;
}

long long	buf_b_cicle(t_div_coef *coef, uint64_t *ba, uint64_t *bb)
{
	unsigned	i;
	unsigned	n;

	n = bb[0];
	i = 0;
	while (i < n)
	{
		some_actns(coef, ba, bb, i);
		if (coef->temp2 < 0)
		{
			ba[coef->vj + i] = coef->temp2 + BASE;
			coef->borrow = -1;
		}
		else
		{
			ba[coef->vj + i] = coef->temp2;
			coef->borrow = 0;
		}
		i++;
	}
	coef->temp2 = ba[coef->vj + i] - coef->carry + coef->borrow;
	return (get_borrow(coef->temp2, coef->vj, i, ba));
}

void		check_b(t_div_coef *coef, uint64_t *ba, uint64_t *bb, uint64_t *res)
{
	if (coef->borrow == 0)
		res[coef->vj] = coef->qguess;
	else
	{
		res[coef->vj] = coef->qguess - 1;
		coef->carry = 0;
		coef->i = 1;
		while (coef->i <= coef->n)
		{
			coef->temp = ba[coef->vj + coef->i] + bb[coef->i] + coef->carry;
			if (coef->temp >= BASE)
			{
				ba[coef->vj + coef->i] = coef->temp - BASE;
				coef->carry = 1;
			}
			else
			{
				ba[coef->vj + coef->i] = coef->temp;
				coef->carry = 0;
			}
			coef->i++;
		}
		ba[coef->vj + coef->i] = ba[coef->vj + coef->i] + coef->carry - BASE;
	}
}

void		cicle(t_div_coef *coef, uint64_t *ba, uint64_t *bb, uint64_t *res)
{
	long i;

	coef->vj = coef->m;
	coef->uj = coef->n + coef->vj;
	while (coef->vj > 0)
	{
		coef->qguess = (ba[coef->uj] * BASE + ba[coef->uj - 1]) / bb[coef->n];
		coef->r = (ba[coef->uj] * BASE + ba[coef->uj - 1]) % bb[coef->n];
		g_stab(&(coef->r), &(coef->qguess), ba[coef->uj - 2], bb);
		coef->carry = 0;
		coef->borrow = 0;
		coef->borrow = buf_b_cicle(coef, ba, bb);
		check_b(coef, ba, bb, res);
		i = ba[0];
		while ((i > 0) && (ba[i] == 0))
			i--;
		ba[0] = i;
		--coef->vj;
		--coef->uj;
	}
}

void		div_mod_l(uint64_t *ba, uint64_t *bb, uint64_t *res)
{
	uint64_t	tmp[2001];
	t_div_coef	coef;

	if (simple_case_div_mod(ba, bb, res))
		return ;
	buf_normalize(&(coef.scale), ba, bb);
	coef.n = (long)bb[0];
	coef.m = ba[0] - bb[0];
	get_zero_buf(res, coef.m);
	cicle(&coef, ba, bb, res);
	while ((coef.m > 0) && (tmp[coef.m] == 0))
		coef.m--;
	tmp[0] = coef.m + 1;
	if (coef.scale > 1)
	{
		div_s(bb, coef.scale, tmp);
		div_s(ba, coef.scale, tmp);
	}
}
