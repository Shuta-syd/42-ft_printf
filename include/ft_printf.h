/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:06:56 by shogura           #+#    #+#             */
/*   Updated: 2022/04/29 14:30:15 by shogura          ###   ########.fr       */
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
	char	flags;
	int			width;
	size_t	precision;
	size_t	error;
} t_status;

size_t	ft_strlen(const char *s);
int		get_digits(int num);
int		ft_atoi(const char *str);
int		ft_printf(const char *format, ...);
void	ft_putstr(char const *s);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putnbr_base(size_t n, int base, char *base_s);
int		scan_format(const char **format, t_status **status, va_list *ap);
#endif
