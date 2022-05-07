/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_scan_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:56:37 by shogura           #+#    #+#             */
/*   Updated: 2022/05/07 20:05:54 by shogura          ###   ########.fr       */
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

int	scan_width(char const **format, t_status **status, va_list *ap)
{
	if ('0' <= **format && **format <= '9')
		(*status)->width = ft_atoi(*format);
	else if (**format == '*')
		(*status)->width = va_arg(*ap, int);
	while (('0' <= **format && **format <= '9') || **format == '*')
		(*format)++;
	if ((*status)->width >= INT_MAX || (*status)->width == INT_MIN)
		return (-1);
	else if ((*status)->width < 0)
		(*status)->width *= -1;
	return (0);
}

int	scan_precision(char const **format, t_status **status, va_list *ap)
{
	if (**format == '.')
	{
		(*format)++;
		if ('0' <= **format && **format <= '9')
			(*status)->precision = ft_atoi(*format);
		else if (**format == '*')
			(*status)->precision = va_arg(*ap, int);
		while (('0' <= **format && **format <= '9') || **format == '*')
			(*format)++;
	}
	if ((*status)->precision >= INT_MAX && **format != 's')
		return (-1);
	else if ((*status)->precision < 0)
		(*status)->precision = 0;
	return (0);
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
	int	error;
	int	ret;

	ret = 0;
	error = 0;
	if (**format == '%')
	{
		(*format)++;
		scan_flags(format, status);
		error += scan_width(format, status, ap);
		error += scan_precision(format, status, ap);
		if (error != -1 && error != -2)
		{
			ret += scan_types(format, *status, ap);
			return (ret);
		}
	}
	else
	{
		while (**format != '%' && **format)
			ret += ft_putnchar(*(*format)++, 1);
		return (ret);
	}
	return (error);
}
