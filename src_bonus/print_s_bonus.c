/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:30:27 by shogura           #+#    #+#             */
/*   Updated: 2022/05/03 17:49:27 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static void	print_no_precision(t_status **status, char *str)
{
	if ((*status)->minus)
	{
		(*status)->ret += ft_putstr(str);
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else
	{
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		(*status)->ret += ft_putstr(str);
	}
}

static void	print_is_precision(t_status **status, char *str)
{
	if ((*status)->minus)
	{
		(*status)->ret += ft_putnstr(str, (*status)->precision);
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else
	{
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		(*status)->ret += ft_putnstr(str, (*status)->precision);
	}
}

int	print_s(t_status *status, va_list *ap)
{
	long	precision;
	long	len;
	char	*str;

	precision = status->precision;
	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		status->ret += ft_putstr("(null)");
		return ((int)status->ret);
	}
	len = (long)ft_strlen(str);
	if ((precision > len || precision == 0) && precision != -1)
		status->width -= len;
	else if (precision != -1)
		status->width -= precision;
	if (precision)
		print_is_precision(&status, str);
	else
		print_no_precision(&status, str);
	return ((int)status->ret);
}
