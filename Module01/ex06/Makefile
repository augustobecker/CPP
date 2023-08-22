# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 03:35:39 by acesar-l          #+#    #+#              #
#    Updated: 2023/01/23 03:37:03 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= harlFilter

COMPILER		= c++

STANDARD_FLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS			= main.cpp	\
				  Harl.cpp

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
