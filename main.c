/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:40:38 by shogura           #+#    #+#             */
/*   Updated: 2022/05/02 17:47:13 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define F printf
#define U ft_printf
#include "include/ft_printf.h"

// void	test_va_arg(char *arg, ...)
//{
//	va_list	ap;

//	va_start(ap, arg);
//	printf("%s\n", arg);
//	printf("%s\n", va_arg(ap, char *));
//	printf("%d\n", va_arg(ap, int));
//	printf("%c\n", va_arg(ap, int));
//	va_end(ap);
//}

// int main(void)
//{
//	char	*ap1 = "shuta ogura hello world!";
//	char	*ap2 = "this is va_arg";
//	int		ap3 = 42;
//	char	ap4 = 'a';
//	test_va_arg(ap1, ap2, ap3, ap4);
//	return 0;
// }

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
	printf("[u]->[%u]\n", 1000);
	printf("[-10u]->[%-10u]\n", 1000);
	printf("[10u]->[%10u]\n", 1000);
	printf("[010u]->[%010u]\n", 1000);
	printf("[010.5u]->[%010.5u]\n", 1000);
	printf("[-10.5u]->[%-10.5u]\n", 1000);
	printf("[5.20u]->[%5.20u]\n", 1000);
	printf("[5.2u]->[%5.2u]\n", 1000);
	printf("------------------------------[user]\n");
	ft_printf("[u]->[%u]\n", 1000);
	ft_printf("[-10u]->[%-10u]\n", 1000);
	ft_printf("[10u]->[%10u]\n", 1000);
	ft_printf("[010u]->[%010u]\n", 1000);
	ft_printf("[010.5u]->[%010.5u]\n", 1000);
	ft_printf("[-10.5u]->[%-10.5u]\n", 1000);
	ft_printf("[5.20u]->[%5.20u]\n", 1000);
	ft_printf("[5.2u]->[%5.2u]\n", 1000);
	*/
	/*
		%x
	printf("[x]->[%x]\n", -1000);
	printf("[#015x]->[%#015x]\n", -1000);
	printf("[-#15x]->[%-#15x]\n", -1000);
	printf("[#x]->[%#x]\n", -1000);
	printf("[-#10x]->[%-#10x]\n", -1000);
	printf("[0#20.10x]->[%0#20.10x]\n", -1000);
	printf("[-#20.10x]->[%-#20.10x]\n", -1000);
	printf("[5.10x]->[%5.10x]\n", -1000);
	printf("------------------------------[user]\n");
	ft_printf("[x]->[%x]\n", -1000);
	ft_printf("[#015x]->[%#015x]\n", -1000);
	ft_printf("[-#15x]->[%-#15x]\n", -1000);
	ft_printf("[#x]->[%#x]\n", -1000);
	ft_printf("[-#10x]->[%-#10x]\n", -1000);
	ft_printf("[0#20.10x]->[%0#20.10x]\n", -1000);
	ft_printf("[-#20.10x]->[%-#20.10x]\n", -1000);
	ft_printf("[5.10x]->[%5.10x]\n", -1000);

	%X
	printf("[X]->[%X]\n", -1000);
	printf("[#015X]->[%#015X]\n", -1000);
	printf("[-#15X]->[%-#15X]\n", -1000);
	printf("[#X]->[%#X]\n", -1000);
	printf("[-#10X]->[%-#10X]\n", -1000);
	printf("[0#20.10X]->[%0#20.10X]\n", -1000);
	printf("[-#20.10X]->[%-#20.10X]\n", -1000);
	printf("[5.10X]->[%5.10X]\n", -1000);
	printf("------------------------------[user]\n");
	ft_printf("[X]->[%X]\n", -1000);
	ft_printf("[#015X]->[%#015X]\n", -1000);
	ft_printf("[-#15X]->[%-#15X]\n", -1000);
	ft_printf("[#X]->[%#X]\n", -1000);
	ft_printf("[-#10X]->[%-#10X]\n", -1000);
	ft_printf("[0#20.10X]->[%0#20.10X]\n", -1000);
	ft_printf("[-#20.10X]->[%-#20.10X]\n", -1000);
	ft_printf("[5.10X]->[%5.10X]\n", -1000);

		%p
	*/
	// char ad = 'a';
	// printf("[p]->[%p]\n", &ad);
	// printf("[15p]->[%15p]\n", &ad);
	// printf("[-15p]->[%-15p]\n", &ad);
	// printf("[p]->[%p]\n", &ad);
	// printf("[-10p]->[%-10p]\n", &ad);
	// printf("[20p]->[%20p]\n", &ad);
	// printf("[-20p]->[%-20p]\n", &ad);
	// printf("[5p]->[%5p]\n", &ad);
	// printf("------------------------------[user]\n");
	// ft_printf("[p]->[%p]\n", &ad);
	// ft_printf("[15p]->[%15p]\n", &ad);
	// ft_printf("[-15p]->[%-15p]\n", &ad);
	// ft_printf("[p]->[%p]\n", &ad);
	// ft_printf("[-10p]->[%-10p]\n", &ad);
	// ft_printf("[20p]->[%20p]\n", &ad);
	// ft_printf("[-20p]->[%-20p]\n", &ad);
	// ft_printf("[5p]->[%5p]\n", &ad);

	// Mandatory %d, i
	F("-----------------------d-------------------------\n");
	F(" [test] ret->[%d]\n", F("(%d)", 100));
	U(" [user] ret->[%d]\n\n", U("(%d)", 100));

	F(" [test] ret->[%d]\n", F("(%d)", -100));
	U(" [user] ret->[%d]\n\n", U("(%d)", -100));

	F(" [test] ret->[%d]\n", F("(%d)", 793274932));
	U(" [user] ret->[%d]\n\n", U("(%d)", 793274932));

	F(" [test] ret->[%d]\n", F("(%d)", INT_MAX));
	U(" [user] ret->[%d]\n\n", U("(%d)", INT_MAX));

	F(" [test] ret->[%d]\n", F("(%d)", INT_MIN));
	U(" [user] ret->[%d]\n", U("(%d)", INT_MIN));
	F("-------------------------------------------------\n");
	// Mandatory %c
	F("-----------------------c-------------------------\n");
	F(" [test] ret->[%d]\n", F("(%c)", 'a'));
	U(" [user] ret->[%d]\n\n", U("(%c)", 'a'));

	F(" [test] ret->[%d]\n", F("(%c)", ' '));
	U(" [user] ret->[%d]\n\n", U("(%c)", ' '));

	F(" [test] ret->[%d]\n", F("(%c)", '0'));
	U(" [user] ret->[%d]\n\n", U("(%c)", '0'));

	F(" [test] ret->[%d]\n", F("(%c)", 0));
	U(" [user] ret->[%d]\n", U("(%c)", 0));
	F("-------------------------------------------------\n");
	// Mandatory %s
	F("-----------------------s-------------------------\n");
	F(" [test] ret->[%d]\n", F("(%s)", "Hello World"));
	U(" [user] ret->[%d]\n\n", U("(%s)", "Hello World"));

	F(" [test] ret->[%d]\n", F("(%s)", "ååååååååååååå"));
	U(" [user] ret->[%d]\n\n", U("(%s)", "ååååååååååååå"));

	F(" [test] ret->[%d]\n", F("(%s)", NULL));
	U(" [user] ret->[%d]\n", U("(%s)", NULL));
	F("-------------------------------------------------\n");
	// Mandatory %u
	F("-----------------------u-------------------------\n");
	F(" [test] ret->[%d]\n", F("(%u)", 100));
	U(" [user] ret->[%d]\n\n", U("(%u)", 100));

	F(" [test] ret->[%d]\n", F("(%u)", -100));
	U(" [user] ret->[%d]\n\n", U("(%u)", -100));

	F(" [test] ret->[%d]\n", F("(%u)", 793274932));
	U(" [user] ret->[%d]\n\n", U("(%u)", 793274932));

	F(" [test] ret->[%d]\n", F("(%u)", INT_MAX));
	U(" [user] ret->[%d]\n\n", U("(%u)", INT_MAX));

	F(" [test] ret->[%d]\n", F("(%u)", INT_MIN));
	U(" [user] ret->[%d]\n\n", U("(%u)", INT_MIN));

	F(" [test] ret->[%d]\n", F("(%u)", UINT_MAX));
	U(" [user] ret->[%d]\n", U("(%u)", UINT_MAX));
	F("-------------------------------------------------\n");
	// Mandatory %x
	F("-----------------------x-------------------------\n");
	F(" [test] ret->[%d]\n", F("(%x)", 100));
	U(" [user] ret->[%d]\n\n", U("(%x)", 100));

	F(" [test] ret->[%d]\n", F("(%x)", -100));
	U(" [user] ret->[%d]\n\n", U("(%x)", -100));

	F(" [test] ret->[%d]\n", F("(%x)", 793274932));
	U(" [user] ret->[%d]\n\n", U("(%x)", 793274932));

	F(" [test] ret->[%d]\n", F("(%x)", INT_MAX));
	U(" [user] ret->[%d]\n\n", U("(%x)", INT_MAX));

	F(" [test] ret->[%d]\n", F("(%x)", INT_MIN));
	U(" [user] ret->[%d]\n\n", U("(%x)", INT_MIN));

	F(" [test] ret->[%d]\n", F("(%x)", UINT_MAX));
	U(" [user] ret->[%d]\n", U("(%x)", UINT_MAX));
	F("-------------------------------------------------\n");
	// Mandatory %X
	F("-----------------------X-------------------------\n");
	F(" [test] ret->[%d]\n", F("(%X)", 100));
	U(" [user] ret->[%d]\n\n", U("(%X)", 100));

	F(" [test] ret->[%d]\n", F("(%X)", -100));
	U(" [user] ret->[%d]\n\n", U("(%X)", -100));

	F(" [test] ret->[%d]\n", F("(%X)", 793274932));
	U(" [user] ret->[%d]\n\n", U("(%X)", 793274932));

	F(" [test] ret->[%d]\n", F("(%X)", INT_MAX));
	U(" [user] ret->[%d]\n\n", U("(%X)", INT_MAX));

	F(" [test] ret->[%d]\n", F("(%X)", INT_MIN));
	U(" [user] ret->[%d]\n\n", U("(%X)", INT_MIN));

	F(" [test] ret->[%d]\n", F("(%X)", UINT_MAX));
	U(" [user] ret->[%d]\n", U("(%X)", UINT_MAX));
	F("-------------------------------------------------\n");
	// Mandatory %p
	F("-----------------------p-------------------------\n");

	char ad = 'a';
	F(" [test] ret->[%d]\n", F("(%p)", &ad));
	U(" [user] ret->[%d]\n\n", U("(%p)", &ad));

	char *str = "shuta";
	F(" [test] ret->[%d]\n", F("(%p)", str));
	U(" [user] ret->[%d]\n\n", U("(%p)", str));

	int num = 16;
	F(" [test] ret->[%d]\n", F("(%p)", &num));
	U(" [user] ret->[%d]\n\n", U("(%p)", &num));

	unsigned long num1 = ULONG_MAX;
	unsigned long num2 = -ULONG_MAX;
	F(" [test] ret->[%d]\n", F("(%p %p)", &num1, &num2));
	U(" [user] ret->[%d]\n\n", U("(%p %p)", &num1, &num2));

	int nm = 10;
	F(" [test] ret->[%d]\n", F("(%p)", &nm));
	U(" [user] ret->[%d]\n\n", U("(%p)", &nm));

	char *ret = NULL;
	F(" [test] ret->[%d]\n", F("(%p)", ret));
	U(" [user] ret->[%d]\n", U("(%p)", ret));
	F("-------------------------------------------------\n");
	F("%d\n", U("%p ", -ULONG_MAX));
	F("%d", U("%p ", ULONG_MAX));
	return 0;
}
