# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 18:43:16 by shogura           #+#    #+#              #
#    Updated: 2022/05/13 20:16:11 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=cc

CFLAGS =	-Wall -Werror -Wextra

NR=norminette -R CheckForbiddenSourceHeader

SRCS= src/ft_printf.c src/ft_printf_utils.c src/output_utils.c\
	src/format_scan.c src/print_d_i.c src/print_u.c\
	src/print_xX.c src/print_p.c src/print_s.c src/print_c_per.c

SRCS_B= src_bonus/ft_printf_bonus.c src_bonus/ft_printf_utils_bonus.c src_bonus/output_utils_bonus.c\
				src_bonus/format_scan_bonus.c src_bonus/print_d_i_bonus.c src_bonus/print_u_bonus.c\
				src_bonus/print_xX_bonus.c src_bonus/print_p_bonus.c src_bonus/print_s_bonus.c\
				src_bonus/print_c_per_bonus.c

OBJS_M= ${SRCS:.c=.o}
OBJS_B= ${SRCS_B:.c=.o}

ifdef BONUS_FLAG
	OBJS = ${OBJS_B}
	HEADER = include/ft_printf_bonus.h
else
	OBJS = ${OBJS_M}
	HEADER= include/ft_printf.h
endif

all: ${NAME}

${NAME}:${OBJS}
	ar -rc $(NAME) ${OBJS}

.o:.c
	${CC} ${CFLAGS} $^ $@ -I ${HEADER}

xx:${SRCS}
	${CC} ${CFLAGS} $^ main.c

bx:${SRCS_B}
	${CC} ${CFLAGS} $^ main_bonus.c

bonus:
	@make BONUS_FLAG=1 all

nr:${SRCS} ${SRCS_B} ${HEADER} ${HEADER_B}
	${NR} $^

clean:
	rm -f ${OBJS_B} ${OBJS_M}

fclean: clean
	rm -f ${NAME}

re: fclean all
