/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:07:10 by shogura           #+#    #+#             */
/*   Updated: 2022/05/09 19:41:30 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

void	init_status(t_status **status)
{
	(*status)->sharp = 0;
	(*status)->plus = 0;
	(*status)->minus = 0;
	(*status)->zero = 0;
	(*status)->space = 0;
	(*status)->width = 0;
	(*status)->precision = 0;
	(*status)->ret = 0;
}

int	error_func(t_status **status, va_list *ap)
{
	if (*status == NULL)
	{
		va_end(*ap);
		return (0);
	}
	free(*status);
	va_end(*ap);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	long		tmp;
	long		ret;
	va_list		ap;
	t_status	*status;

	tmp = 0;
	ret = 0;
	va_start(ap, format);
	status = (t_status *)malloc(sizeof(t_status));
	if (status == NULL)
		return (error_func(&status, &ap));
	while (*format)
	{
		init_status(&status);
		tmp = scan_format(&format, &status, &ap);
		if (tmp == -1)
			return (error_func(&status, &ap));
		ret += tmp;
		if (ret > INT_MAX)
			return (error_func(&status, &ap));
	}
	va_end(ap);
	free(status);
	return (ret);
}
