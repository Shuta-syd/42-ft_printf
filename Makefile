# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 18:43:16 by shogura           #+#    #+#              #
#    Updated: 2022/05/02 18:38:34 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=cc

CFLAG= -Wall -Wextra -Werror

NR=norminette -R CheckForbiddenSourceHeader

SRCS= src/ft_printf.c src/ft_printf_utils.c src/output_utils.c src/format_scan.c src/print_d_i.c\
			src/print_u.c src/print_large_x.c src/print_small_x.c src/print_p.c src/print_s.c\
			src/print_c_per.c src/print_c_per.c

SRCS_B= src_bonus/ft_printf_bonus.c src_bonus/ft_printf_utils_bonus.c src_bonus/output_utils_bonus.c\
				src_bonus/format_scan_bonus.c src_bonus/print_d_i_bonus.c src_bonus/print_u_bonus.c src_bonus/print_large_x_bonus.c\
				src_bonus/print_small_x_bonus.c src_bonus/print_p_bonus.c src_bonus/print_s_bonus.c\
				src_bonus/print_c_per_bonus.c src_bonus/print_c_per_bonus.c

OBJS_M= ${SRCS:.c=.o}

OBJS_B= ${SRCS_B:.c=.o}

HEADER= include/ft_printf.h

all: ${NAME}

${NAME}:${OBJS_M}
		ar -rc $(NAME) ${OBJS_M}
		rm -f ${OBJS_M}

xx:${SRCS}
	${CC} ${CFLAG} $^ main.c

bx:${SRCS_B}
	${CC} ${CFLAG} $^ main_bonus.c

bonus:${OBJS_B}
	ar -rc $(NAME) ${OBJS_B}
	rm -f ${OBJS_B}

nr:${SRCS} ${SRCS_B} ${HEADER}
	${NR} $^

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all
