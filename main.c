/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:40:38 by shogura           #+#    #+#             */
/*   Updated: 2022/05/01 15:49:33 by shogura          ###   ########.fr       */
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
	/*
		%d, %i
	printf("------------------------------['-'flag]\n");
	printf("[-d]->[%-d]\n", -1000);
	printf("[-10d]->[%-10d]\n", -1000);
	printf("[-.10d]->[%-.10d]\n", -1000);
	printf("[-15.10d]->[%-15.10d]\n", -1000);
	printf("------------------------------[user]\n");
	ft_printf("[-d]->[%-d]\n", -1000);
	ft_printf("[-10d]->[%-10d]\n", -1000);
	ft_printf("[-.10d]->[%-.10d]\n", -1000);
	ft_printf("[-15.10d]->[%-15.10d]\n", -1000);
	printf("\n------------------------------[0+ or 0 ' ' precisionなし]\n");
	printf("[+0d]->[%+0d]\n", -1000);
	printf("[+010d]->[%+010d]\n", -1000);
	printf("[+015d]->[%+015d]\n", -1000);
	printf("------------------------------[user]\n");
	ft_printf("[+0d]->[%+0d]\n", -1000);
	ft_printf("[+010d]->[%+010d]\n", -1000);
	ft_printf("[+015d]->[%+015d]\n", -1000);
	printf("\n------------------------------[0+ or 0 ' ' precisionあり]\n");
	printf("[+0.10d]->[%+0.10d]\n", -1000);
	printf("[+015.10d]->[%+015.10d]\n", -1000);
	printf("------------------------------[user]\n");
	ft_printf("[+0.10d]->[%+0.10d]\n", -1000);
	ft_printf("[+015.10d]->[%+015.10d]\n", -1000);
	printf("\n------------------------------[' ' +のみ]\n");
	printf("[+d]->[%+d]\n", -1000);
	printf("[+10d]->[%+10d]\n", -1000);
	printf("[+.10d]->[%+.10d]\n", -1000);
	printf("[+15.10d]->[%+15.10d]\n", -1000);
	printf("------------------------------[user]\n");
	ft_printf("[+d]->[%+d]\n", -1000);
	ft_printf("[+10d]->[%+10d]\n", -1000);
	ft_printf("[+.10d]->[%+.10d]\n", -1000);
	ft_printf("[+15.10d]->[%+15.10d]\n", -1000);
	printf("\n------------------------------[others]\n");
	printf("[d]->[%d]\n", -1000);
	printf("[10d]->[%10d]\n", -1000);
	printf("[.10d]->[%.10d]\n", -1000);
	printf("[15.10d]->[%15.10d]\n", -1000);
	printf("------------------------------[user]\n");
	ft_printf("[d]->[%d]\n", -1000);
	ft_printf("[10d]->[%10d]\n", -1000);
	ft_printf("[.10d]->[%.10d]\n", -1000);
	ft_printf("[15.10d]->[%15.10d]\n", -1000);
	*/
	/*
		%c %%
		printf("[c]->[%c]\n", 'a');
		printf("[10c]->[%10c]\n", 'a');
		printf("[-10c]->[%-10c]\n", 'a');
		printf("------------------------------[user]\n");
		ft_printf("[c]->[%c]\n", 'a');
		ft_printf("[10c]->[%10c]\n", 'a');
		ft_printf("[-10c]->[%-10c]\n", 'a');
	*/
	/*
		%s
	printf("[s]->[%s]\n", "hello world");
	printf("[10s]->[%10s]\n", "hello world");
	printf("[-10s]->[%-10s]\n", "hello world");
	printf("[10.5s]->[%10.5s]\n", "hello world");
	printf("[10.20s]->[%10.20s]\n", "hello world");
	printf("[-10.5s]->[%-10.5s]\n", "hello world");
	printf("------------------------------[user]\n");
	ft_printf("[s]->[%s]\n", "hello world");
	ft_printf("[10s]->[%10s]\n", "hello world");
	ft_printf("[-10s]->[%-10s]\n", "hello world");
	ft_printf("[10.5s]->[%10.5s]\n", "hello world");
	ft_printf("[10.20s]->[%10.20s]\n", "hello world");
	ft_printf("[-10.5s]->[%-10.5s]\n", "hello world");
	*/

	/*
		%u
	*/
	printf("[u]->[%u]\n", 1000);
	printf("[-u]->[%-u]\n", 1000);
	printf("[10u]->[%10u]\n", 1000);
	printf("[10.5u]->[%10.5u]\n", 1000);
	printf("[-10.5u]->[%-10.5u]\n", 1000);
	printf("[5.20u]->[%5.20u]\n", 1000);
	return 0;
}
