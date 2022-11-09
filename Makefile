# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 17:27:55 by rrouille          #+#    #+#              #
#    Updated: 2022/11/09 14:08:47 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Folders
LIBDIR		= lib
SRCDIR		= srcs
OBJDIR		= objs
HDRDIR		= includes

# Files
SRCS		= 
OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a

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
			@make -C ${LIBDIR}
			@cp ${LIBDIR}/libft.a .
			@mv libft.a ${NAME}
			@${AR} ${NAME} ${OBJS}
			@echo "${GREEN}ft_printf compiled!${DEF_COLOR}"

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
			@make clean -C ${LIBDIR}
			@echo "${BLUE}ft_printf object files cleaned!${DEFCOLOR}"

fclean:		clean
			@${RM} ${NAME}
			@${RM} ${LIBDIR}/libft.a
			@echo "${CYAN}ft_printf files cleaned!"
			@echo "Library cleaned!${DEFCOLOR}"

re: 		fclean all
			@echo "${GREEN}Cleaned and rebuilt everything!${DEFCOLOR}"

.PHONY:		all clean fclean re .c.o