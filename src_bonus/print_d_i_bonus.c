/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:29:39 by shogura           #+#    #+#             */
/*   Updated: 2022/05/02 18:04:32 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	num -> arg引数
	width -> paddingを出力する長さ(len)

	出力パターン分け
	______________________________________________________________________
	1. '-'flagの場合 - + ' ' → precision → value → width
	______________________________________________________________________
	'-'flagのみ	(-1000)	printf("%-d\n", -1000);
	widthあり	(-1000      )	printf("%-10d\n", -1000);
	precisionあり(-0000001000)	printf("%-.10d\n", -1000);
	width precisionあり(-0000001000     )	printf("%-15.10d\n", -1000);
	______________________________________________________________________
	2. 0+ or 0' '(precisionなし)の場合 - + ' ' -> width -> value
	______________________________________________________________________
	'0+'flagのみ	(-1000)	printf("%+0d\n", -1000);
	widthあり	(-000001000)	printf("%+010d\n", -1000);
	'+0' width あり(-00000000001000)	printf("%+015d\n", -1000);
	______________________________________________________________________
	3. 0+ or 0' '(precisionあり)の場合 width -> + - ' ' -> precision -> value
	______________________________________________________________________
	precisionあり(-0000001000)	printf("%+0.10d\n", -1000);
	width precisionあり(    -0000001000)	printf("%+015.10d\n", -1000);
	______________________________________________________________________
	4. ' ' + のみの場合 width -> precision -> + - ' ' -> value
	______________________________________________________________________
	'+'flagのみ(-1000)	printf("%+d\n", -1000);
	widthあり(     -1000)	printf("%+10d\n", -1000);
	precisionあり(-0000001000)	printf("%+.10d\n", -1000);
	width precisionあり(    -0000001000)	printf("%+15.10d\n", -1000);
	______________________________________________________________________
	5. それ以外 width -> precision -> value
	______________________________________________________________________
	なにもなし(-1000)	printf("%d\n", -1000);
	widthのみ(     -1000)	printf("%10d\n", -1000);
	precisionのみ(-0000001000)	printf("%.10d\n", -1000);
	width precision(    -0000001000)	printf("%15.10d\n", -1000);
	______________________________________________________________________
*/

#include "../include/ft_printf_bonus.h"

static void	scan_signs(t_status **status, int *num, int *minus_sign)
{
	if (*num < 0)
	{
		(*status)->plus = -1;
		*minus_sign = 1;
		if (*num != -2147483648)
			*num *= -1;
	}
	if (num < 0 || (*status)->plus || (*status)->space)
		(*status)->width--;
}

static void	print_sign(t_status **status, int minus_sign)
{
	if (minus_sign)
		(*status)->ret += ft_putchar('-');
	else if ((*status)->plus)
		(*status)->ret += ft_putchar('+');
	else if ((*status)->space)
		(*status)->ret += ft_putchar(' ');
}

static	void	print_no_precision(t_status **status, int num, int minus_sign)
{
	if ((*status)->minus)
	{
		print_sign(status, minus_sign);
		ft_putnbr(num);
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else if ((*status)->zero)
	{
		print_sign(status, minus_sign);
		(*status)->ret += ft_putnchar('0', (*status)->width);
		ft_putnbr(num);
	}
	else
	{
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		print_sign(status, minus_sign);
		ft_putnbr(num);
	}
}

static void	print_is_precision(t_status **status, int num, int minus_sign)
{
	if ((*status)->minus)
	{
		print_sign(status, minus_sign);
		(*status)->ret += ft_putnchar('0', (*status)->precision - get_digits(num, 10));
		ft_putnbr(num);
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else
	{
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		print_sign(status, minus_sign);
		(*status)->ret += ft_putnchar('0', (*status)->precision - get_digits(num, 10));
		ft_putnbr(num);
	}
}

ssize_t	print_d_i(t_status *status, va_list *ap)
{
	int	num;
	int	minus_sign;

	minus_sign = 0;
	num = va_arg(*ap, int);
	scan_signs(&status, &num, &minus_sign);
	status->ret += get_digits(num, 10);
	if (get_digits(num, 10) > status->precision)
		status->width -= get_digits(num, 10);
	else if (status->precision > get_digits(num, 10))
		status->width -= status->precision;
	if (status->precision) // precisionある場合
		print_is_precision(&status, num, minus_sign);
	else	//precisionがない場合
		print_no_precision(&status, num, minus_sign);
	return (status->ret);
}

//atoi long超え return-1のときのエラー処理
