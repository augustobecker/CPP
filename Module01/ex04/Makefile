# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 20:20:14 by acesar-l          #+#    #+#              #
#    Updated: 2023/01/20 00:41:17 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Replacer

COMPILER		= g++

STANDARD_FLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS			= main.cpp						\
				  error_messages.cpp			\
				  validations.cpp

OBJS			= ${SRCS:.cpp=.o}

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

%.o:			%.cpp
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
