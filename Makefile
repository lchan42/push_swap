# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 20:57:58 by lchan             #+#    #+#              #
#    Updated: 2022/02/25 14:56:39 by lchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	push_swap_del.c\
			push_swap_utils.c\
			push_swap_entrycheck.c\

SRCSBONUS =	

NAME		= push_swap

INC			= push_swap.h

OBJS		= ${SRCS:.c=.o}

OBJSBONUS	= ${SRCSBONUS:.c=.o}

CC			= gcc
MAKE		= make
PATH		= libraries/libft/
RM			= rm -f

CFLAGS		= -g3 -fsanitize=address -Wall -Werror -Wextra

LIB			=	libraries/libft/libft.a
#				libraries/ft_printf/libftprintf.a

AR			= ar

ARFLAGS		= rcs

RAN			= ranlib

%.o: %.c
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS}{}
			${AR} ${ARFLAGS} ${NAME} ${OBJS} ${LIB} ${INC}



bonus:		${NAME} ${OBJS} ${OBJSBONUS}
			${AR} ${ARFLAGS} ${NAME} ${OBJSBONUS}

clean:
			${RM} ${OBJS} ${OBJSBONUS}

cleanb:		clean
			${RM} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		re clean fclean all bonus
