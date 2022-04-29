/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_per.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:43:23 by shogura           #+#    #+#             */
/*   Updated: 2022/04/29 18:36:47 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_c_per(t_status *status, va_list *ap, char type)
{
	char	pd;
	char	ch;
	int		width;

	pd = ' ';
	if (status->zero)
		pd = '0';
	if (type == '%')
		ch = '%';
	else
		ch = va_arg(*ap, int);
	width = status->width - 1;
	if (status->minus)
	{
		pd = ' ';
		ft_putchar(ch);
		while (width-- > 0)
			ft_putchar(pd);
	}
	else
	{
		while (width-- > 0)
			ft_putchar(pd);
		ft_putchar(ch);
	}
}
