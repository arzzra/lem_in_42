/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:22:54 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/29 15:01:59 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "ft_printf.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include <float.h>
# include <string.h>

# include <stdio.h>
# define TYPES "cspdiouxXegfC%SbEGF"
# define ALLFLG "#0-+ "
# define SPACE " "
# define ADDRESS "0x"
# define ADDRESS2 "0X"
# define ZERO "0"
# define PLUS "+"
# define MINUS "-"
# define NULLPRINT "(null)"
# define BASE 1000000000
# define BASELEN 9

typedef struct				s_qualfrs
{
	int						countchr;
	int						signum;
	int						typs;
	int						width;
	int						prcs;
	char					*num;
	char					*sformat;
	int						countnum;
	struct s_float			*ld;
	struct s_flag			*flg;
	struct s_length			*len;
	va_list					ap;
}							t_qualfrs;

typedef struct				s_float
{
	short					newmem;
	long long				intlen;
	long long				sf_index;
	int						iflg;
	int						fflg;
	char					tmp;
	unsigned				ovrld;
	int						delta;
	short					carry;
	long long				totallen;
	long long				realprec;
	long long				count_0;
	long double				d;
	long long				e;
	long long				exp;
	short					sign_exp;
}							t_float;

typedef struct				s_flag
{
	int						sharp;
	int						zero;
	int						minus;
	int						plus;
	int						space;
}							t_flag;

typedef struct				s_length
{
	int						l;
	int						h;
	int						bigl;
}							t_length;

typedef	union
{
	long double				d;
	struct
	{
		uint64_t			mantissa	: 64;
		uint64_t			exponent	: 15;
		uint64_t			sign		: 1;
	}						bits;
}							t_ld;

typedef struct				s_div_coef
{
	long					n;
	uint64_t				m;
	uint64_t				scale;
	uint64_t				qguess;
	uint64_t				temp1;
	uint64_t				r;
	long long				temp;
	long long				temp2;
	long long				carry;
	long long				vj;
	long					uj;
	long					i;
	short					borrow;
}							t_div_coef;

/*
**save_frac_part_e.c
*/

void						after_round(char *sf, t_qualfrs *fmt);
void						before_round(char *sf, t_qualfrs *fmt);
void						fill_last_part(char *sf, uint64_t *p_frac,
							t_qualfrs *fmt);
int							fill_int_part(char *sf, uint64_t *p_int,
							t_qualfrs *fmt);
char						*save_fp_e(char *sf, uint64_t *p_int,
							uint64_t *p_frac, t_qualfrs *fmt);

/*
**fill_e_end.c
*/

char						*get_end_index(char *s_full, t_qualfrs *fmt);
char						*put_e_sig(char *p, t_qualfrs *fmt);
void						fill_e_end(char *s_full, t_qualfrs *fmt);

/*
**conver_parts.c
*/

void						correct_prec(t_qualfrs *fmt);
char						minlen_type(uint64_t *p_int, t_qualfrs *fmt);
void						solve_type(uint64_t *p_int,
							uint64_t *p_frac, t_qualfrs *fmt);
void						conver_parts(char *s_int,
							char *s_frac, t_qualfrs *fmt);

/*
** round_line.c
*/

void						round_line(char *s_full, t_qualfrs *fmt);
int							check_last_dig(char *s);
void						replace_dig(char *s_base_i, short *f);

/*
** get_totallen.c
*/

long long					baselen(t_qualfrs *fmt);
long long					get_totallen_e(uint64_t *p_int, t_qualfrs *fmt);
long long					get_totallen_e(uint64_t *p_int, t_qualfrs *fmt);
long long					get_totallen_f(uint64_t *p_int, t_qualfrs *fmt);

/*
**save_int_part_e.c
*/

char						*save_int_part_e(char *res_str, t_qualfrs *fmt);
void						nzero_nminus_e(char **p, t_qualfrs *fmt);
void						zero_nminus_e(char **p, t_qualfrs *fmt);
long						fill_left_part(char *res_str, t_qualfrs *fmt);

/*
**solve_e.c
*/
char						*solve_e(uint64_t *p_i,
							uint64_t *p_f, char **res_s, t_qualfrs *fmt);
uint64_t					*cut_buf(uint64_t *buf, long long len);
int							fill_right_part(char *res_str, t_qualfrs *fmt);
long long					number_pow(long long num);

/*
**solve_f.c
*/

char						*solve_f(uint64_t *p_i, uint64_t *p_f,
							char **res_s, t_qualfrs *fmt);
char						*save_int_part(char *res_str,
							uint64_t *buf, t_qualfrs *fmt);
char						*zero_nminus(char *p, t_qualfrs *fmt);
void						put_first_simbol(char **p, t_qualfrs *fmt);
long long					get_buflen(uint64_t *buf);

/*
**save_frac_part.c
*/

void						zero_prec(char *s_full,
							uint64_t *buf, t_qualfrs *fmt);
int							nozero_prec(t_qualfrs *fmt,
							char *s_full, uint64_t *p_frac);
char						*save_fp(char *res_s, uint64_t *p_frac,
							uint64_t *p_int, t_qualfrs *fmt);
void						fill_prec(char *s_full, uint64_t *buf,
							t_qualfrs *fmt);
long long					get_start_index(char *s_full, uint64_t *buf,
							t_qualfrs *fmt);

/*
**fill_res.c
*/

char						*fill_res_f(char *res_str, char *s_full,
							t_qualfrs *fmt);
char						*fill_res_e(char *res_str, t_qualfrs *fmt);

/*
**long_operation_2.c
*/

void						div_mod_s(uint64_t *buf_a, uint64_t b,
							uint64_t *res, uint64_t *rem);
uint64_t					*mul_l(uint64_t *buf1, uint64_t *buf2,
							uint64_t *res);
uint64_t					*div_s(uint64_t *buf, unsigned dig, uint64_t *res);
uint64_t					*mul_s(uint64_t *buf, unsigned dig);
void						pow_of_two(uint64_t *buf_2n, unsigned long exp);

/*
**long_operation.c
*/

void						zero_ceil(uint64_t *buf, unsigned maxlen);
uint64_t					*add_s(uint64_t *buf, uint64_t dig);
uint64_t					*add(uint64_t *buf1, uint64_t *buf2);
void						print_bits(size_t size, void *ptr, char space);

/*
**div_mod_l.c
*/

void						div_mod_l(uint64_t *ba, uint64_t *bb,
							uint64_t *res);
void						cicle(t_div_coef *coef, uint64_t *ba,
							uint64_t *bb, uint64_t *res);
void						check_b(t_div_coef *coef, uint64_t *ba,
							uint64_t *bb, uint64_t *res);
long long					buf_b_cicle(t_div_coef *coef, uint64_t *ba,
							uint64_t *bb);
void						some_actns(t_div_coef *coef, uint64_t *ba,
							uint64_t *bb, unsigned i);

/*
**div_mod_l_2.c
*/

short						get_borrow(long long temp2, long long vj,
							unsigned i, uint64_t *ba);
int							simple_case_div_mod(uint64_t *buf_a,
							uint64_t *buf_b, uint64_t *res);
void						buf_normalize(uint64_t *scale, uint64_t *buf_a,
							uint64_t *buf_b);
void						g_stab(uint64_t *r, uint64_t *qguess, uint64_t next,
							uint64_t *buf_b);
void						get_zero_buf(uint64_t *buf, uint64_t m);

/*
**convert_mantiss.c
*/

void						replace_bit_max(void *src, char *int_part,
							char *frac_part, t_qualfrs *fmt);
void						replace_bit_min(void *src, char *frac_part,
							size_t size, long long exp);
void						frac_to_str(void *src, char *frac_part,
							int *ind, t_qualfrs *fmt);

/*
**print_int_part.c
*/

char						*lead_zeros(long long exp, char *part, char flag);
void						solve_int_part(char *s_int);
uint64_t					*convert_integer(uint64_t *buf, char *s_int);
void						check_len_fmt(long long *count,
							t_qualfrs *fmt);

/*
**print_frac_partv2.c
*/

void						pow_of_num(uint64_t *buf_n, uint64_t exp,
							unsigned num);
void						print_last_zero(int prec);
void						copy_buf_ull(const uint64_t *src, uint64_t *dst);
uint64_t					*convert_fraction(char *s_frac, uint64_t *buf,
							t_qualfrs *fmt_feature);
void						keep_mod(unsigned long *buf, unsigned long base,
							unsigned baselen, long long exp);
void						div_mod(unsigned long *buf, unsigned long *res,
							unsigned long base, unsigned baselen,
							long long exp);
void						convert_string(uint64_t *buf, char *s_part);

/*
**buffer.c
*/

void						print_buf(unsigned long *buf, unsigned count_0,
							char c, t_qualfrs *fmt_feature);
void						buf_to_str(uint64_t *buf, char *s_full);

/*
**start.c
*/

void						divide_and_conquer(t_ld *un, t_qualfrs *fmt);
char						*ft_itoa_base_ll(uint64_t dig, int radix);
uint64_t					count_zero_after_point(long double d,
							t_qualfrs *fmt);
void						ft_print_floats(t_qualfrs *ql);

int							ft_printf(const char *format, ...);
int							ft_flags(char *format, t_qualfrs *ql);
int							ft_width(char *frm, t_qualfrs *ql);
int							ft_precision(char *frm, t_qualfrs *ql);
int							ft_length(char *frm, t_qualfrs *ql);
char						*ft_types(char *frm, t_qualfrs *ql);

void						ft_print_di(t_qualfrs *ql);
void						ft_print_di_2(t_qualfrs *ql);
void						ft_print_di_neg(t_qualfrs *ql);
void						ft_print_di_neg2(t_qualfrs *ql);
void						ft_print_di_neg3(t_qualfrs *ql);
void						ft_print_di_neg4(t_qualfrs *ql);
void						ft_print_di_pos(t_qualfrs *ql);
void						ft_print_di_pos2(t_qualfrs *ql);
void						ft_print_di_pos3(t_qualfrs *ql);
void						ft_print_di_pos4(t_qualfrs *ql);
void						ft_print_number(t_qualfrs *ql);
int							ft_zd(char *frm, t_qualfrs *ql);

char						*ft_sign_lenchoose(t_qualfrs *ql);
char						*ft_sign_lenchoose2(t_qualfrs *ql);

char						*ft_unsign_lenchoose(t_qualfrs *ql);
char						*ft_unsign_lenchoose2(t_qualfrs *ql);

void						ft_print_ox(t_qualfrs *ql);
char						*ft_len_ox2(unsigned long long numb, t_qualfrs *ql);
char						*ft_len_ox(unsigned long long numb, t_qualfrs *ql);
void						ft_print_sharp(t_qualfrs *ql);
void						ft_print_ox2(t_qualfrs *ql);
void						ft_print_xo(t_qualfrs *ql);
void						ft_print_xo2(t_qualfrs *ql);
void						ft_print_xo3(t_qualfrs *ql);
void						ft_print_xo4(t_qualfrs *ql);

void						ft_print_u(t_qualfrs *ql);
void						ft_print_u2(t_qualfrs *ql);
void						ft_print_u_1(t_qualfrs *ql);
void						ft_print_u_2(t_qualfrs *ql);
void						ft_print_u_3(t_qualfrs *ql);

char						*ft_itoa2(unsigned long long int n, int *x);
void						ft_print_space(int	a, t_qualfrs *ql);
void						ft_print_zero(int	a, t_qualfrs *ql);
char						*ft_10_to_8(unsigned long long x, t_qualfrs *ql);
char						*ft_10_to_16(unsigned long long x, t_qualfrs *ql);
void						ft_search_syntax(char *format, t_qualfrs *qual);
void						ft_print_pointer(t_qualfrs *ql);
void						ft_print_pointer2(t_qualfrs *ql);
void						ft_print_pointer2_1(t_qualfrs *ql);
void						ft_print_str(t_qualfrs *ql);
void						ft_print_str2(t_qualfrs *ql);
void						ft_printwchar(wchar_t c, t_qualfrs *ql);
size_t						ft_wstrlen(const char *str);
int							ft_putwchar(int c);
void						ft_print_char(t_qualfrs *ql);
char						*ft_print_format(char *as, t_qualfrs *qual);

void						ft_how_to_print2(t_qualfrs *ql);
void						ft_how_to_print(t_qualfrs *ql);

void						ft_color(t_qualfrs *ql);
void						ft_zero_struct(t_qualfrs *ql);
void						ft_zero_struct2(t_qualfrs *ql);
void						ft_without_typs(t_qualfrs *ql);
void						ft_print_percent(t_qualfrs *ql);
void						ft_print_str_uni(t_qualfrs *ql);

int							ft_inf_nan(t_qualfrs *ql);
void						print_bits2(void *ptr, char *frac, int i);
void						ft_print_b(t_qualfrs *ql);
#endif
