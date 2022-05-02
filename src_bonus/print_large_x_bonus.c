/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_large_x_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:43:46 by shogura           #+#    #+#             */
/*   Updated: 2022/05/02 19:35:12 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static void print_no_precision(t_status **status, unsigned int num)
{
	if ((*status)->minus)
	{
		print_flag_sharp(status, "0X", 0, num);
		ft_putnbr_base(num, 16, "0123456789ABCDEF");
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else if ((*status)->zero)
	{
		print_flag_sharp(status, "0X", 0, num);
		(*status)->ret += ft_putnchar('0', (*status)->width);
		ft_putnbr_base(num, 16, "0123456789ABCDEF");
	}
	else
	{
		print_flag_sharp(status, "0X", 0, num);
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		ft_putnbr_base(num, 16, "0123456789ABCDEF");
	}
}

static void print_is_precision(t_status **status, unsigned int num)
{
	if ((*status)->minus)
	{
		print_flag_sharp(status, "0X", 0, num);
		(*status)->ret += ft_putnchar('0', (*status)->precision - get_digits(num, 16));
		ft_putnbr_base(num, 16, "0123456789ABCDEF");
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else
	{
		if (print_flag_sharp(status, "0X", 1, num))
			(*status)->ret += ft_putnchar(' ', (*status)->width);
		(*status)->ret += ft_putnchar('0', (*status)->precision - get_digits(num, 16));
		ft_putnbr_base(num, 16, "0123456789ABCDEF");
	}
}

ssize_t print_X(t_status *status, va_list *ap)
{
	unsigned int num;

	num = va_arg(*ap, unsigned int);
	status->ret += get_digits(num, 16);
	if (get_digits(num, 16) > status->precision)
		status->width -= get_digits(num, 16);
	else if (status->precision > get_digits(num, 16))
		status->width -= status->precision;
	if (status->precision)
		print_is_precision(&status, num);
	else
		print_no_precision(&status, num);
	return (status->ret);
}
