/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:56:37 by shogura           #+#    #+#             */
/*   Updated: 2022/04/29 20:23:13 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void scan_flags(char const **format, t_status **status)
{
	while (**format == '#' || **format == '+' || **format == '-' || **format == ' ' || **format == '0')
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

void	output_status(t_status *status)
{
	printf("\nsharp -> %d\n", status->sharp);
	printf("plus -> %d\n", status->plus);
	printf("minus -> %d\n", status->minus);
	printf("zero -> %d\n", status->zero);
	printf("space -> %d\n", status->space);
	printf("width -> %d\n", status->width);
	printf("precision -> %zu\n", status->precision);
	printf("error -> %zu\n", status->error);
}

void scan_types(char const **format, t_status *status, va_list *ap)
{
	if (**format == 'i' || **format == 'd')
	 print_i_d(status, ap);
	else if (**format == 'c')
		print_c_per(status, ap, 'c');
	else if (**format == 's')
		print_s(status, ap);
	else if (**format == 'u')
		print_u(status, ap);
	else if (**format == 'x')
		print_x(status, ap);
	else if (**format == 'X')
		print_X(status, ap);
	else if (**format == 'p')
		print_p(status, ap);
	else if (**format == '%')
		print_c_per(status, ap, '%');
	(*format)++;
}

int	scan_error(const char *format)
{
	if (!(*format == '#' || *format == '+' || *format == '-' || *format == ' ' ||
				*format == '0' || *format == 'i' || *format == 'd' || *format == 'c' ||
				*format == 's' || *format == 'u' || *format == 'x' || *format == 'X' ||
				*format == 'p' || *format == '%') && !('0' <= *format && *format <= '9'))
	{
		return (1);
	}
	return (0);
}

int scan_format(const char **format, t_status **status, va_list *ap)
{
	size_t i;

	i = 0;
	if (**format == '%')
	{
		(*format)++;
		//check error
		if(scan_error(*format))
			return (1);
		// check flags
		scan_flags(format, status);
		// check width
		scan_width(format, status);
		//  check precision
		scan_precision(format, status);
		// check types and output args
		scan_types(format, *status, ap);
		// output_status(*status);
		return (0);
	}
	return (1);
}
