/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_per.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:43:23 by shogura           #+#    #+#             */
/*   Updated: 2022/05/02 14:06:52 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t	print_c_per(t_status *status, va_list *ap, char type)
{
	char	ch;

	if (type == '%')
		ch = '%';
	else
		ch = va_arg(*ap, int);
	status->width -= 1;
	if (status->minus)
	{
		status->ret += ft_putchar(ch);
		status->ret += ft_putnchar(' ', status->width);
	}
	else
	{
		status->ret += ft_putnchar(' ', status->width);
		status->ret += ft_putchar(ch);
	}
	return (status->ret);
}