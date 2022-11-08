# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 17:27:55 by rrouille          #+#    #+#              #
#    Updated: 2022/11/08 14:33:01 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Folders
SRCDIR		= srcs
OBJDIR		= objs
LIBDIR		= lib
DOCDIR		= doc
HDRDIR		= includes

SRCS		= $(shell find $(SRCDIR) -name '*.c')
OBJS		= ${SRCS:.c=.o}
NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
MV			= mv
MKDIR		= mkdir
AR			= ar rcs

${NAME}:	${OBJS}
			@echo "Creating the library."
			@${AR} ${NAME} ${OBJS}
			@${RM} ${OBJDIR}
			@${MKDIR} ${OBJDIR}
			@${MV} $(shell find ${SRCDIR} -name '*.o') ${OBJDIR}

.c.o :
			@echo "Creating $?."
			$(CC) $(CFLAGS) -c -o $@ $?

all:		${NAME}

clean:
			@echo "Cleaning *.o files..."
			@${RM} ${OBJDIR}
			@${RM} $(shell find $(SRCDIR) -name '*.o')

fclean:		clean
			@echo "Cleaning the library."
			@${RM} ${NAME} 

re: 		fclean all

.PHONY:		all clean fclean re .c.o