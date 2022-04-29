/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:24:50 by shogura           #+#    #+#             */
/*   Updated: 2022/04/29 13:02:13 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return;
}

void	ft_putstr(char const *s)
{
	size_t len;

	if (s == NULL)
		return;
	len = ft_strlen(s);
	write(1, s, len);
	return;
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n >= 0)
		ft_putchar(n + '0');
	return;
}

void ft_putnbr_base(size_t n, int base, char *base_s)
{
	if (n > base)
	{
		ft_putnbr_base(n / base, base, base_s);
		ft_putnbr_base(n % base, base, base_s);
	}
	else if (10 <= n && n <= 15)
		ft_putchar(base_s[n]);
	else if (0 <= n && n <= 9)
		ft_putchar(base_s[n]);
	return;
}
