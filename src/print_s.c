/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:45:24 by shogura           #+#    #+#             */
/*   Updated: 2022/04/30 15:01:11 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void print_s(t_status *status, va_list *ap)
{
	char	pd;
	char	*str;
	int		width;

	pd = ' ';
	if (status->zero)
		pd = '0';
	str = va_arg(*ap, char *);
	if (status->precision)
		width = status->width - status->precision;
	else
		width = status->width - ft_strlen(str);
	if (status->minus)
	{
		pd = ' ';
		if (status->precision)
			ft_putnstr(str, status->precision);
		else
			ft_putstr(str);
		while (width-- > 0)
			ft_putchar(pd);
	}
	else
	{
		while (width-- > 0)
			ft_putchar(pd);
		if (status->precision)
			ft_putnstr(str, status->precision);
		else
			ft_putstr(str);
	}
}
// NULLの処理→(null)
