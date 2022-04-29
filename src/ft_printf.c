/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:07:10 by shogura           #+#    #+#             */
/*   Updated: 2022/04/29 20:21:58 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	init_status(t_status **status)
{
	(*status)->sharp = 0;
	(*status)->plus = 0;
	(*status)->minus = 0;
	(*status)->zero = 0;
	(*status)->space = 0;
	(*status)->width = 0;
	(*status)->precision = 0;
	(*status)->error = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_status *status;

	va_start(ap, format);
	status = malloc(sizeof(t_status));
	while (*format)
	{
		// status initialize
		init_status(&status);
		// format check
		if (scan_format(&format, &status, &ap))
		{
			while (*format != '%' && *format)
				ft_putchar(*format++);
		}
	}
	free(status);
	return (0);
}
