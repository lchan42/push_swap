# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 20:57:58 by lchan             #+#    #+#              #
#    Updated: 2022/04/08 22:38:52 by lchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PATH	= libraries/libft/
LIB		=	libft.a

SRCS	=	ps_parsing_entrycheck.c\
			ps_parsing_buildstack.c\
			ps_utils_stacklen.c\
			ps_utils_general.c\
			ps_sorted_checker.c\
			ps_mvt_a.c\
			ps_mvt_b.c\
			ps_smart_rot_pivot.c\
			ps_smart_rot_target.c\
			ps_sort_6_cir.c\
			ps_sort_6_findpivot.c\
			ps_longest_sub_get.c\
			ps_longest_sub_utils.c\
			ps_longest_sub_algo.c\
			ps_cost_tab_get.c\
			ps_opti_cost_tab.c\
			ps_opti_mvtbook.c\
			ps_free_struct.c\
			main.c\

SRCSBONUS =	

NAME		= push_swap

INC			= push_swap.h

OBJS		= ${SRCS:.c=.o}

OBJSBONUS	= ${SRCSBONUS:.c=.o}

CC			= gcc
MAKE		= make
RM			= rm -f

CFLAGS		= -g3 -fsanitize=address -Wall -Werror -Wextra


AR			= ar

ARFLAGS		= rcs

RAN			= ranlib

%.o: %.c
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS}{}
			${AR} ${ARFLAGS} ${NAME} ${OBJS} ${INC}

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



#####################################################
# %.o: %.c means anytext.o depends on that sametext.c
# 		it shows how to create a .o
# $@ whatever is on the left side of the rule (%.o)
# $^ whatever is on the right side of the rule colomn (%.c)
#
