/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:14:34 by shogura           #+#    #+#             */
/*   Updated: 2022/04/30 18:59:25 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	print_pattern2_precision(t_status *status, int num, int width)
{
	char	pad;

	pad = ' ';
	if (status->space || status->width)
		width--;
	while (width-- > 0)
		ft_putchar(pad);
	if (status->plus)
		ft_putchar('+');
	else if (status->space)
		ft_putchar(' ');
	while (status->precision-- - get_digits(num, 10) > 0)
		ft_putchar('0');
	ft_putnbr(num);
}

// pattern 3 (+ ' 'のみ)
static void	print_pattern3(t_status *status, int num, int width)
{
	char	pad;

	pad = ' ';
	if (status->zero)
		pad = '0';
	width -= 1;
	while (width-- > 0)
		ft_putchar(pad);
	while (status->precision-- - get_digits(num, 10) > 0)
		ft_putchar('0');
	if (status->plus)
		ft_putchar('+');
	else if (status->space)
		ft_putchar(' ');
	ft_putnbr(num);
}

// patter 1 (左詰め)	// pattern 2 (0 + ' ')の共存 // ノーマル
static void	print_pattern124(t_status *status, int num, int width, int pattern)
{
	char	pad;

	if (status->precision && status->zero && (status->plus || status->space))
	{
		print_pattern2_precision(status, num, width);
		return;
	}
	pad = ' ';
	if (status->zero)
		pad = '0';
	if (status->plus)
		ft_putchar('+');
	else if (status->space)
		ft_putchar(' ');
	width--;
	if (pattern == 2)
	{
		while (width--)
			ft_putchar(pad);
		while (status->precision-- - get_digits(num, 10) > 0)
			ft_putchar('0');
		ft_putnbr(num);
		return ;
	}
	pad = ' ';
	while (status->precision-- - get_digits(num, 10) > 0)
		ft_putchar('0');
	ft_putnbr(num);
	while (width-- > 0)
		ft_putchar(pad);
}

void	print_i_d(t_status *status, va_list *ap)
{
	int	width;
	int	num;

	num = va_arg(*ap, int);
	if (get_digits(num, 10) > status->precision)
		width = status->width - (get_digits(num, 10) - status->precision);
	else if (status->precision > get_digits(num, 10))
		width = status->width - status->precision;
	if (status->minus)
		print_pattern124(status, num, width, 1);
	else if (status->zero && (status->plus || status->space))
		print_pattern124(status, num, width, 2);
	else if (status->plus || status->space)
		print_pattern3(status, num, width);
	else
		print_pattern124(status, num, width, 4);
}

/*
 If there are 0 + ' ' && precision
 0 function is ignored
 + - ' ' signs are located after paddings
 after it, put 0 for precision - strlen(str)
*/
