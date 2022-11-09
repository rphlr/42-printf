# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 17:27:55 by rrouille          #+#    #+#              #
#    Updated: 2022/11/09 14:13:20 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Folders
SRCDIR		= srcs
OBJDIR		= objs
HDRDIR		= includes

# Files
SRCS		= $(shell find ${SRCDIR} -name '*.c')
OBJS		= ${SRCS:.c=.o}
NAME		= libft.a

# Compilation
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# Usefuls commands
RM			= rm -rf
MV			= mv
MKDIR		= mkdir

# Archive
AR			= ar rcs

# Colors
DEFCOLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

# First rule
${NAME}:	${OBJS}
			@${AR} ${NAME} ${OBJS}
			@${RM} ${OBJDIR}
			@${MKDIR} ${OBJDIR}
			@${MV} $(shell find ${SRCDIR} -name '*.o') ${OBJDIR}
			@echo "${GREEN}Library compiled!${DEF_COLOR}"

# Compilation rule
.c.o :
			@echo "${YELLOW}Creating $?.${DEF_COLOR}"
			@${CC} ${CFLAGS} -c -o $@ $?

all:		${NAME}

# Norminette
norm:
			@norminette -R CheckForbiddenSourceHeader

# Cleaning
clean:
			@${RM} ${OBJDIR}
			@${RM} $(shell find ${SRCDIR} -name '*.o')
			@echo "${CYAN}Object files cleaned!${DEF_COLOR}"

fclean:		clean
			@${RM} ${NAME} 
			@echo "${CYAN}Library cleaned!${DEF_COLOR}"

re: 		fclean all

.PHONY:		all clean fclean re .c.o