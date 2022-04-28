# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 18:43:16 by shogura           #+#    #+#              #
#    Updated: 2022/04/28 19:34:20 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=cc

CFLAG= #-Wall -Wextra -Werror

NR=norminette -R CheckForbiddenSourceHeader

SRCS= src/ft_printf.c src/ft_printf_utils.c src/output.c

HEADER= include/ft_printf.h

BONUS=ft_printf_bonus.c

all:${SRCS}
	${CC} ${CFLAG} $^ main.c

bonus:${BONUS}
	${CC} ${CFLAG} $^ main_bonus.c

nr:${SRCS} ${BONUS} ${HEADER}
	${NR} $^

fclean:
	rm -f ${NAME}

re: fclean all
