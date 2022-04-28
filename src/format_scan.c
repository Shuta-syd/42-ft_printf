/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:56:37 by shogura           #+#    #+#             */
/*   Updated: 2022/04/28 20:45:03 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void scan_flags(char const **format, t_status **status)
{
	if (**format == '#' || **format == '+' || **format == '-' || **format == ' ')
	{
		if (**format == '#')
			(*status)->flags = 1;
		else if (**format == '+')
			(*status)->flags = 2;
		else if (**format == '-')
			(*status)->flags = 3;
		else if (**format == ' ')
			(*status)->flags = 4;
		(*format)++;
		return;
	}
	(*status)->error++;
}

void scan_width(char const **format, t_status **status)
{
	if ('0' <= **format && **format <= '9')
		(*status)->width = ft_atoi(*format);
	while ('0' <= **format && **format <= '9')
		(*format)++;
}

void scan_precision(char const **format, t_status **status)
{
	if (**format == '.')
	{
		(*format)++;
		if ('0' <= **format && **format <= '9')
			(*status)->width = ft_atoi(*format);
		while ('0' <= **format && **format <= '9')
			(*format)++;
	}
}

void scan_types(char const **format, t_status *status, va_list *ap)
{
	uintptr_t address;

	address = 0;
	if (**format == 'i' || **format == 'd')
		ft_putnbr(va_arg(*ap, int));
	else if (**format == 'u' || **format == 'x' || **format == 'X')
	{
		// base system
		printf("base system");
	}
	else if (**format == 'c')
		ft_putchar(va_arg(*ap, int));
	else if (**format == 's')
		ft_putstr(va_arg(*ap, char *));
	else if (**format == 'p')
	{
		address = va_arg(*ap, uintptr_t);
		printf("base system");
	}
	else if (**format == '%')
		ft_putchar('%');
}

int scan_format(const char **format, t_status **status, va_list *ap)
{
	size_t i;

	i = 0;
	if (**format == '%')
	{
		(*format)++;
		// check flags
		scan_flags(format, status);
		// check width
		scan_width(format, status);
		//  check precision
		scan_precision(format, status);
		// check types
		scan_types(format, *status, ap);
		return (0);
	}
	return (1);
}
