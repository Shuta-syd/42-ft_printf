/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:42:03 by shogura           #+#    #+#             */
/*   Updated: 2022/04/29 18:58:59 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void print_u(t_status *status, va_list *ap)
{
	unsigned int	num;
	int				width;
	char			pad;

	pad = ' ';
	if (status->zero)
		pad = '0';
	num = va_arg(*ap, unsigned int);
	width = status->width - get_digits(num, 10);
	if (status->minus)
	{
		pad = ' ';
		ft_putnbr_base(num, 10, "0123456789");
		while (width--)
			ft_putchar(pad);
	}
	else
	{
		while (width--)
			ft_putchar(pad);
		ft_putnbr_base(num, 10, "0123456789");
	}
}
