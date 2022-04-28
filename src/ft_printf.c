/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:07:10 by shogura           #+#    #+#             */
/*   Updated: 2022/04/28 19:56:45 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	init_status(t_status **status)
{
	(*status)->flags = 0;
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
	//while (*format)
	//{
		// status initialize
		init_status(&status);
		// format check
		if (scan_format(&format, &status, &ap))
		{
			// func other than %
		}
	//}
	free(status);
	return (0);
}
