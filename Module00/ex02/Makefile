# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 22:09:25 by acesar-l          #+#    #+#              #
#    Updated: 2023/01/17 17:21:38 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= accounts_log

COMPILER		= g++

STANDARD_FLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS			= tests.cpp		\
				  Account.cpp

OBJS 			= ${SRCS:.cpp=.o}

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

%.o: 			%.cpp
				${COMPILER} ${STANDARD_FLAGS} -c $< -o $@

all:			${NAME}

${NAME}:		${OBJS}
				${COMPILER} -o ${NAME} ${OBJS} ${STANDARD_FLAGS}
				@echo "${NAME}: ${GREEN}${NAME} was generated${RESET}"

clean:
				rm -f ${OBJS}
				@echo "${NAME}: ${RED} Objects were destroyed ${RESET}"

fclean:			clean
				rm -f ${NAME}
				@echo "${NAME}: ${RED}${NAME} was destroyed ${RESET}"

re:				clean all

.PHONY:			all clean fclean re
