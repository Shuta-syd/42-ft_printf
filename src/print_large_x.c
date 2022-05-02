/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_large_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:43:46 by shogura           #+#    #+#             */
/*   Updated: 2022/05/01 14:31:54 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	print_pattern1(t_status *status, uintmax_t num, int width)
{
	char pad;

	pad = ' ';
	if (status->sharp)
	{
		width -= 2;
		ft_putstr("0X");
	}
	ft_putnbr_base(num, 16, "0123456789ABCDEF");
	while (width-- > 0)
		ft_putchar(pad);
}

static void	print_pattern2(t_status *status, uintmax_t num, int width)
{
	char pad;

	pad = ' ';
	if (status->zero)
		pad = '0';
	if (status->sharp)
	{
		width -= 2;
		ft_putstr("0X");
	}
	while (width-- > 0)
		ft_putchar(pad);
	ft_putnbr_base(num, 16, "0123456789ABCDEF");
}

void print_X(t_status *status, va_list *ap)
{
	unsigned int num;
	int width;

	num = va_arg(*ap, unsigned int);
	width = status->width - get_digits(num, 16);
	if (status->minus)
		print_pattern1(status, num, width);
	else
		print_pattern2(status, num, width);
}
