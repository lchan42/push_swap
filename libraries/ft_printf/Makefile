# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 20:57:58 by lchan             #+#    #+#              #
#    Updated: 2022/01/23 18:17:27 by lchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	utils_one.c\
				utils_two.c\
				chained_list.c\
				add_sign_to_content.c\
				add_padding.c\
				add_precision.c\
				add_content_to_chained_list.c\
				case_csp.c\
				case_duxxmajpercent.c\
				specifier_tree.c\
				cursor_jump_specifier.c\
				parsing.c\
				ft_printf.c\

NAME		= libftprintf.a

INC			= ft_printf.h

OBJS		= ${SRCS:.c=.o}

OBJSBONUS	= ${SRCSBONUS:.c=.o}

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

AR			= ar

ARFLAGS		= rcs

RAN			= ranlib

%.o: %.c
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS}
			${AR} ${ARFLAGS} ${NAME} ${OBJS} ${INC}

bonus:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSBONUS}

cleanb:		clean
			${RM} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		re clean fclean all bonus
