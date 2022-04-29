/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:43:46 by shogura           #+#    #+#             */
/*   Updated: 2022/04/29 19:33:45 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void print_p(t_status *status, va_list *ap)
{
	uintptr_t address;
	int width;
	char pad;

	pad = ' ';
	if (status->zero)
		pad = '0';
	address = va_arg(*ap, uintptr_t);
	width = status->width - get_digits(address, 16) - 2;
	if (status->minus)
	{
		ft_putstr("0x");
		pad = ' ';
		ft_putnbr_base(address, 16, "0123456789abcdef");
		while (width-- > 0)
			ft_putchar(pad);
	}
	else
	{
		ft_putstr("0x");
		while (width-- > 0)
			ft_putchar(pad);
		ft_putnbr_base(address, 16, "0123456789abcdef");
	}
}
