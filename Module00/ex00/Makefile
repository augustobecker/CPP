# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 00:05:52 by acesar-l          #+#    #+#              #
#    Updated: 2023/01/02 15:37:37 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= megaphone

COMPILER 		= g++

STANDARD_FLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS			= megaphone.cpp

OBJS 			= ${SRCS:.cpp=.o}

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

%.o:			%.cpp
				${COMPILER} ${STANDARD_FLAGS} -c $< -o $@

all:			${NAME}
		
${NAME}:		${OBJS}
				$(COMPILER) -o $(NAME) $(OBJS) $(STANDARD_FLAGS)
				@echo "$(NAME): $(GREEN)$(NAME) was created :)$(RESET)"

clean:
				rm -f ${OBJS}
				@echo "${NAME}: ${RED} Objects were destroyed ${RESET}"

fclean:			clean
				rm -f ${NAME}
				@echo "${NAME}: ${RED}${NAME} was destroyed ${RESET}"

re :			clean all

.PHONY:			all clean fclean re
