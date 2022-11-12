# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 17:27:55 by rrouille          #+#    #+#              #
#    Updated: 2022/11/12 19:06:53 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Folders
LIBDIR		= lib
SRCDIR		= srcs
OBJDIR		= objs
HDRDIR		= includes

# Files
SRCS		= ${shell find ${SRCDIR} -name '*.c'}
#OBJS		= ${addprefix ${OBJDIR}, ${addsuffix .o, ${SRCS}}}
OBJS		= ${SRCS:${SRCDIR}%.c=${OBJDIR}%.o}
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

all:		${NAME}

# First rule
${NAME}:	${OBJS}
			@cp ${LIBDIR}/libft.a .
			@mv libft.a ${NAME}
			@${AR} ${NAME} ${OBJS}
			@echo "${GREEN}ft_printf compiled!${DEFCOLOR}"

# Compilation rule
${OBJDIR}/%.o: ${SRCDIR}/%.c
			@make -C ${LIBDIR}
			@${MKDIR} -p ${OBJDIR}
			@echo "${YELLOW}Compiling: $< ${DEFCOLOR}"
			@${CC} ${CFLAGS} -I ${HDRDIR} -c $< -o $@

# Norminette
norm:
			@norminette -R CheckForbiddenSourceHeader

# Cleaning
clean:
			@${RM} -rf ${OBJDIR}
			@make clean -C ${LIBDIR}
			@echo "${BLUE}ft_printf object files cleaned!${DEFCOLOR}"

fclean:		clean
			@${RM} -f ${NAME}
			@${RM} -f ${LIBDIR}/libft.a
			@echo "${CYAN}ft_printf executable files cleaned!"
			@echo "${CYAN}libft executable files cleaned!${DEFCOLOR}"

re:			fclean all
			@echo "${GREEN}Cleaned and rebuilt everything for ft_printf!${DEFCOLOR}"

.PHONY:		all clean fclean re norm
