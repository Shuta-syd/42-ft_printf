/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:45:24 by shogura           #+#    #+#             */
/*   Updated: 2022/05/02 18:04:42 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

ssize_t print_s(t_status *status, va_list *ap)
{
	int	too_large;
	char	*str;

	too_large = 1;
	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		status->ret	+= ft_putstr("(null)");
		return (status->ret);
	}
	if (status->precision && status->width > status->precision)
	{
		too_large = 0;
		status->width -= status->precision;
	}
	else
		status->width -= ft_strlen(str);
	if (status->minus)
	{
		if (too_large == 0)
			status->ret += ft_putnstr(str, status->precision);
		else
			status->ret += ft_putstr(str);
		status->ret += ft_putnchar(' ', status->width);
	}
	else
	{
		status->ret += ft_putnchar(' ', status->width);
		if (too_large == 0)
			status->ret += ft_putnstr(str, status->precision);
		else
			status->ret += ft_putstr(str);
	}
	return (status->ret);
}
// NULLの処理→(null)
