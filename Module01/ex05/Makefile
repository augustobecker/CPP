# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 20:15:43 by acesar-l          #+#    #+#              #
#    Updated: 2023/01/22 20:15:48 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Harl_debugger

COMPILER		= g++

STANDARD_FLAGS	= -Wall -Wextra -Werror -std=c++98

FILES			= main.cpp	\
				  Harl.cpp

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

all:			${NAME}

${NAME}:
				${COMPILER} -o ${NAME} ${FILES} ${STANDARD_FLAGS}
				@echo "${NAME}: ${GREEN}${NAME} was generated${RESET}\n"

clean:
				rm -f ${NAME}
				@echo "${NAME}: ${RED}${NAME} was destroyed ${RESET}\n"

fclean:			clean

re:				clean all

.PHONY:			all clean fclean re
