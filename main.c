/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:40:38 by shogura           #+#    #+#             */
/*   Updated: 2022/04/22 22:13:30 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	test_va_arg(char *str, ...)
{
	va_list test;
	size_t	sum;
	size_t	len;

	sum = 0;
	len = 0;
	va_start(test, str);
	len = strlen(str);
	for (int i = 0; i < len; i++)
		sum += va_arg(test, size_t);
	va_end(test);
}

int main(void)
{
	char *str = "shuta ogura hello world!";
	test_va_arg(str);
	return 0;
}
