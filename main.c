/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:40:38 by shogura           #+#    #+#             */
/*   Updated: 2022/05/03 17:53:14 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define F printf
#define U ft_printf
#include "include/ft_printf.h"

int main(void)
{
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

	// F(" [test] ret->[%d]\n", F("(%s)", NULL));
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
	// F("%d\n", U("%p ", -ULONG_MAX));
	// F("%d", U("%p ", ULONG_MAX));
	return 0;
}
