/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_small_x_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:43:46 by shogura           #+#    #+#             */
/*   Updated: 2022/05/02 18:04:45 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	print_flag_sharp(t_status **status, int sharp, char *x, int flag)
{
	if (sharp && !flag)
	{
		(*status)->width -= 2;
		(*status)->ret += ft_putstr(x);
		return (0);
	}
	else if (sharp && flag)
	{
		(*status)->width -= 2;
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		(*status)->ret += ft_putstr(x);
		return (0);
	}
	return (1);
}

static void print_no_precision(t_status **status, unsigned int num)
{
		if ((*status)->minus)
		{
			print_flag_sharp(status, (*status)->sharp, "0x", 0);
			ft_putnbr_base(num, 16, "0123456789abcdef");
			(*status)->ret += ft_putnchar(' ', (*status)->width);
		}
		else if ((*status)->zero)
		{
			print_flag_sharp(status, (*status)->sharp, "0x", 0);
			(*status)->ret += ft_putnchar('0', (*status)->width);
			ft_putnbr_base(num, 16, "0123456789abcdef");
		}
		else
		{
			print_flag_sharp(status, (*status)->sharp, "0x", 0);
			(*status)->ret += ft_putnchar(' ', (*status)->width);
			ft_putnbr_base(num, 16, "0123456789abcdef");
		}
}

static void print_is_precision(t_status **status, unsigned int num)
{
	if ((*status)->minus)
	{
		print_flag_sharp(status, (*status)->sharp, "0x", 0);
		(*status)->ret += ft_putnchar('0', (*status)->precision - get_digits(num, 16));
		ft_putnbr_base(num, 16, "0123456789abcdef");
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else
	{
		if (print_flag_sharp(status, (*status)->sharp, "0x", 1))
			(*status)->ret += ft_putnchar(' ', (*status)->width);
		(*status)->ret += ft_putnchar('0', (*status)->precision - get_digits(num, 16));
		ft_putnbr_base(num, 16, "0123456789abcdef");
	}
}

ssize_t	print_x(t_status *status, va_list *ap)
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
