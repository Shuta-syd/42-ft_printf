/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_scan_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:56:37 by shogura           #+#    #+#             */
/*   Updated: 2022/05/03 17:50:24 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

void	scan_flags(char const **format, t_status **status)
{
	while (**format == '#' || **format == '+' || **format == '-'
		|| **format == ' ' || **format == '0')
	{
		if (**format == '#')
			(*status)->sharp++;
		else if (**format == '+')
			(*status)->plus++;
		else if (**format == '-')
			(*status)->minus++;
		else if (**format == '0')
			(*status)->zero++;
		else if (**format == ' ')
			(*status)->space++;
		(*format)++;
	}
}

void	scan_width(char const **format, t_status **status)
{
	if ('0' <= **format && **format <= '9')
		(*status)->width = ft_atoi(*format);
	while ('0' <= **format && **format <= '9')
		(*format)++;
}

void	scan_precision(char const **format, t_status **status)
{
	if (**format == '.')
	{
		(*format)++;
		if ('0' <= **format && **format <= '9')
			(*status)->precision = ft_atoi(*format);
		else
			(*status)->precision = -1;
		while ('0' <= **format && **format <= '9')
			(*format)++;
	}
}

int	scan_types(char const **format, t_status *status, va_list *ap)
{
	int	ret;

	ret = 0;
	if (**format == 'i' || **format == 'd')
		ret = print_d_i(status, ap);
	else if (**format == 'c')
		ret = print_c_per(status, ap, 'c');
	else if (**format == 's')
		ret = print_s(status, ap);
	else if (**format == 'u')
		ret = print_u(status, ap);
	else if (**format == 'x')
		ret = print_x(status, ap);
	else if (**format == 'X')
		ret = print_X(status, ap);
	else if (**format == 'p')
		ret = print_p(status, ap);
	else if (**format == '%')
		ret = print_c_per(status, ap, '%');
	(*format)++;
	return (ret);
}

int	scan_format(const char **format, t_status **status, va_list *ap)
{
	int	ret;

	ret = 0;
	if (**format == '%')
	{
		(*format)++;
		scan_flags(format, status);
		scan_width(format, status);
		scan_precision(format, status);
		ret += scan_types(format, *status, ap);
	}
	else
	{
		while (**format != '%' && **format)
			ret += ft_putnchar(*(*format)++, 1);
	}
	return (ret);
}
