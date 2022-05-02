/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:42:03 by shogura           #+#    #+#             */
/*   Updated: 2022/05/02 18:04:48 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static void	print_is_precision(t_status **status, unsigned int num)
{
	if ((*status)->minus)
	{
		(*status)->ret += ft_putnchar('0', (*status)->precision - get_digits(num, 10));
		ft_putnbr_base(num, 10, "0123456789");
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else
	{
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		(*status)->ret += ft_putnchar('0', (*status)->precision - get_digits(num, 10));
		ft_putnbr_base(num, 10, "0123456789");
	}
}

static void	print_no_precision(t_status **status, unsigned int num)
{
	if ((*status)->minus)
	{
		ft_putnbr_base(num, 10, "0123456789");
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else if ((*status)->zero)
	{
		(*status)->ret += ft_putnchar('0', (*status)->width);
		ft_putnbr_base(num, 10, "0123456789");
	}
	else
	{
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		ft_putnbr_base(num, 10, "0123456789");
	}
}

ssize_t	print_u(t_status *status, va_list *ap)
{
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	status->ret += get_digits(num, 10);
	if (get_digits(num, 10) > status->precision)
		status->width -= get_digits(num, 10);
	else if (status->precision > get_digits(num, 10))
		status->width -= status->precision;
	if (status->precision)
		print_is_precision(&status, num);
	else
		print_no_precision(&status, num);
	return (status->ret);
}
