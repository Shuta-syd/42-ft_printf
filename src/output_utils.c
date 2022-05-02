/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:24:50 by shogura           #+#    #+#             */
/*   Updated: 2022/05/01 15:34:25 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_putnchar(int ch, int  len)
{
	ssize_t	tmp;

	tmp = (ssize_t)len;
	if (len < 0)
		return (0);
	while (len--)
		ft_putchar(ch);
	return (tmp);
}

ssize_t	ft_putstr(char const *s)
{
	size_t len;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	write(1, s, len);
	return ((ssize_t)len);
}

ssize_t	ft_putnstr(char const *s, int n)
{
	ssize_t	ret;

	ret = (ssize_t)n;
	if (s == NULL)
		return (0);
	while (*s && n--)
		ft_putchar(*s++);
	return (ret);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("2147483648");
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n >= 0)
		ft_putchar(n + '0');
	return;
}

void	ft_putnbr_base(size_t n, size_t base, char *base_s)
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
	return ;
}
