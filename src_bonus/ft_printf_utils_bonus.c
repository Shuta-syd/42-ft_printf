/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:31:25 by shogura           #+#    #+#             */
/*   Updated: 2022/05/02 18:04:18 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	get_digits(long num, int base)
{
	int digits;

	digits = 1;
	while (num / base != 0)
	{
		num /= base;
		digits++;
	}
	return (digits);
}

static int ft_overflow(int minus)
{
	if (minus > 0)
		return ((int)LONG_MAX);
	return ((int)LONG_MIN);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long long	num;

	i = 0;
	num = 0;
	minus = 1;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = 10 * num + (str[i] - '0');
		if (num < 0)
			return (ft_overflow(minus));
		i++;
	}
	return ((int)num * minus);
}
