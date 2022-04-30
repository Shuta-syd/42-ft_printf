/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:40:38 by shogura           #+#    #+#             */
/*   Updated: 2022/04/30 19:01:12 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

//void	test_va_arg(char *arg, ...)
//{
//	va_list	ap;

//	va_start(ap, arg);
//	printf("%s\n", arg);
//	printf("%s\n", va_arg(ap, char *));
//	printf("%d\n", va_arg(ap, int));
//	printf("%c\n", va_arg(ap, int));
//	va_end(ap);
//}

//int main(void)
//{
//	char	*ap1 = "shuta ogura hello world!";
//	char	*ap2 = "this is va_arg";
//	int		ap3 = 42;
//	char	ap4 = 'a';
//	test_va_arg(ap1, ap2, ap3, ap4);
//	return 0;
//}


int main(void)
{
	char num = 's';
	// ft_printf("%ragra0#20 %d %d %s", 100, 100, "hello world");
	// printf("\n%ragra0#20 %d %d %s", 100, 100, "hello world");
	// printf("%10.20s\n", "hello world");
	// ft_printf("%10.20s", "hello world");
	printf("%+020.10d\n", 1000);
	ft_printf("%+020.10d\n", 1000);
	return 0;
}
