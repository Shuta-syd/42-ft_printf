/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:06:56 by shogura           #+#    #+#             */
/*   Updated: 2022/05/01 15:32:19 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdio.h> // 削除
#include <string.h> // 削除
#include <inttypes.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
typedef struct s_status
{
	int		sharp;
	int		plus;
	int		minus;
	int		zero;
	int		space;
	int		width;
	int		precision;
	ssize_t	ret;
} t_status;

size_t	ft_strlen(const char *s);
int		get_digits(long num, int base);
int		ft_atoi(const char *str);
int		ft_printf(const char *format, ...);
ssize_t ft_putstr(char const *s);
ssize_t		ft_putnchar(int ch, int len);
ssize_t ft_putnstr(char const *s, int n);
void	ft_putnbr(int n);
ssize_t	ft_putchar(char c);
void	ft_putnbr_base(size_t n, size_t base, char *base_s);
int		scan_format(const char **format, t_status **status, va_list *ap);
ssize_t print_d_i(t_status *status, va_list *ap);
void print_u(t_status *status, va_list *ap);
void	print_s(t_status *status, va_list *ap);
void	print_c_per(t_status *status, va_list *ap, char type);
void	print_p(t_status *status, va_list *ap);
void	print_X(t_status *status, va_list *ap);
void	print_x(t_status *status, va_list *ap);
#endif
