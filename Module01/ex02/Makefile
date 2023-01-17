# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 21:36:41 by acesar-l          #+#    #+#              #
#    Updated: 2023/01/17 21:57:20 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Reference

COMPILER		= g++

STANDARD_FLAGS	= -Wall -Wextra -Werror -std=c++98

FILES			= main.cpp

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
