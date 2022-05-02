# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 18:43:16 by shogura           #+#    #+#              #
#    Updated: 2022/05/01 14:42:56 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=cc

CFLAG= -Wall -Wextra -Werror

NR=norminette -R CheckForbiddenSourceHeader

SRCS= src/ft_printf.c src/ft_printf_utils.c src/output_utils.c src/format_scan.c src/print_d_i.c\
			src/print_u.c src/print_large_x.c src/print_small_x.c src/print_p.c src/print_s.c\
			src/print_c_per.c src/print_c_per.c

OBJS_M= ${SRCS:.c=.o}

HEADER= include/ft_printf.h

BONUS=ft_printf_bonus.c

all: ${NAME}

${NAME}:${OBJS_M}
		ar -rc $(NAME) ${OBJS_M}
		rm -f ${OBJS_M}

xx:${SRCS}
	${CC} ${CFLAG} $^ main.c

x:
	${CC} ${CFLAG} main.c

bonus:${BONUS}
	${CC} ${CFLAG} $^ main_bonus.c

nr:${SRCS} ${BONUS} ${HEADER}
	${NR} $^

clean:
	rm -f ${OBJS_M}

fclean: clean
	rm -f ${NAME}

re: fclean all
