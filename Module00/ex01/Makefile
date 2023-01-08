# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 15:48:17 by acesar-l          #+#    #+#              #
#    Updated: 2023/01/08 21:59:06 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= annuaire

COMPILER		= g++

STANDARD_FLAGS	= -Wall -Wextra -Werror -std=c++98

FILES			= main.cpp			\
				  Contact.cpp		\
				  PhoneBook.cpp 	\
				  add_contact.cpp	\
				  get_command.cpp	\
				  search_contact.cpp

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

all:			${NAME}

${NAME}:
				${COMPILER} -o ${NAME} ${FILES} ${STANDARD_FLAGS}
				@echo "${NAME}: ${GREEN}${NAME} was created :)${RESET}\n"

clean:
				rm -f ${NAME}
				@echo "${NAME}: ${RED}${NAME} was burned ${RESET}\n"

fclean:			clean

re:				clean all

.PHONY:			all clean fclean re
