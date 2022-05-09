/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:07:10 by shogura           #+#    #+#             */
/*   Updated: 2022/05/09 19:33:48 by shogura          ###   ########.fr       */
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
	int			ret;
	va_list		ap;
	t_status	*status;

	ret = 0;
	va_start(ap, format);
	status = (t_status *)malloc(sizeof(t_status));
	if (status == NULL)
		return (0);
	while (*format)
	{
		init_status(&status);
		ret += scan_format(&format, &status, &ap);
		if (ret == 0)
		{
			while (*format != '%' && *format)
				ret += ft_putnchar(*format++, 1);
		}
	}
	free(status);
	va_end(ap);
	return (ret);
}
