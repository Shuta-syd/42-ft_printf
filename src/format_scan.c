/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:56:37 by shogura           #+#    #+#             */
/*   Updated: 2022/04/29 14:35:58 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void scan_flags(char const **format, t_status **status)
{
	if (**format == '#' || **format == '+' || **format == '-' || **format == ' ' || **format == '0')
	{
		(*status)->flags = **format;
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

void	output_status(t_status *status)
{
	printf("flags -> %c\n", status->flags);
	printf("width -> %d\n", status->width);
	printf("precision -> %zu\n", status->precision);
	printf("error -> %zu\n", status->error);
}

void	print_i_d(t_status *status, va_list *ap)
{
	char pad;
	int width;
	int	num;

	if (status->flags == '0')
		status->flags = '0';
	num = va_arg(*ap, int);
	width = status->width - get_digits(num);
	while (width-- > 0)
		ft_putchar(status->flags);
	if (status->flags == '+')
		ft_putchar('+');
	ft_putnbr(num);
}

void print_c_p(t_status *status, va_list *ap, char type)
{
	char	ch;
	int		width;

	if (type == '%')
		ch = '%';
	else
		ch = va_arg(*ap, int);
	width = status->width - 1; // digits
	while (width-- > 0)
		ft_putchar(' ');
	ft_putchar(ch);
}

void print_s(t_status *status, va_list *ap)
{
	char *str;
	int width;

	str = va_arg(*ap, char *);
	width = status->width - ft_strlen(str);
	while (width-- > 0)
		ft_putchar(' ');
	ft_putstr(str);
}

void print_u(t_status *status, va_list *ap) //マイナス数値が来た時widthズレる
{
	unsigned int num;
	int  width;

	num = va_arg(*ap, unsigned int);
	width = status->width - get_digits(num);
	while (width-- > 0)
		ft_putchar(' ');
	ft_putnbr_base(num, 10, "0123456789");
}

void print_x(t_status *status, va_list *ap) //16進数に直した後の桁数を引かないとズレる
{
	unsigned int num;
	int width;

	num = va_arg(*ap, unsigned int);
	width = status->width - get_digits(num);
	while (width-- > 0)
		ft_putchar(' ');
	ft_putnbr_base(num, 16, "0123456789abcdef");
}

void print_X(t_status *status, va_list *ap) // 16進数に直した後の桁数を引かないとズレる
{
	unsigned int num;
	int width;

	num = va_arg(*ap, unsigned int);
	width = status->width - get_digits(num);
	while (width-- > 0)
		ft_putchar(' ');
	ft_putnbr_base(num, 16, "0123456789ABCDEF");
}

void print_p(t_status *status, va_list *ap) // 16進数に直した後の桁数を引かないとズレる
{
	uintptr_t	address;
	int width;

	address = va_arg(*ap, uintptr_t);
	width = status->width - get_digits(address);
	while (width-- > 0)
		ft_putchar(' ');
	ft_putstr("0x");
	ft_putnbr_base(address, 16, "0123456789abcdef");
}

void scan_types(char const **format, t_status *status, va_list *ap)
{
	output_status(status);
	if (**format == 'i' || **format == 'd')
		print_i_d(status, ap);
	else if (**format == 'c')
		print_c_p(status, ap, 'c');
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
		print_c_p(status, ap, '%');
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
		// check types and output args
		scan_types(format, *status, ap);
		return (0);
	}
	return (1);
}
