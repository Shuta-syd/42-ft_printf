/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:07:10 by shogura           #+#    #+#             */
/*   Updated: 2022/05/02 18:04:15 by shogura          ###   ########.fr       */
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

int	ft_printf(const char *format, ...)
{
	int	ret;
	va_list	ap;
	t_status *status;

	ret = 0;
	va_start(ap, format);
	status = (t_status *)malloc(sizeof(t_status));
	if (status == NULL)
		return (0);
	while (*format)
	{
		// status initialize
		init_status(&status);
		// format check
		ret += (int)scan_format(&format, &status, &ap);
		if (ret == 0)
		{
			while (*format != '%' && *format)
				ret += ft_putchar(*format++);
		}
	}
	free(status);
	return (ret);
}
