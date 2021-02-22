# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gscala <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 14:46:16 by gscala            #+#    #+#              #
#    Updated: 2021/02/18 14:46:18 by gscala           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	ft_printchar.c ft_printf.c ft_printint.c ft_printstr.c ft_x.c \
			ft_printpoint.c

OBJS	= ${SRCS:.c=.o}
CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror -c
NAME	= libftprintf.a
RM		= /bin/rm -f

%.o: %.c
	${CC} ${CFLAGS} $<

${NAME} :	${OBJS}
			ar -rc ${NAME} ${OBJS}
			ranlib ${NAME}

all :		${NAME}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}
			
re :		fclean all
	
.PHONY :	all clean fclean re
