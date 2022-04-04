# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 00:05:52 by acesar-l          #+#    #+#              #
#    Updated: 2022/04/04 14:19:22 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= megaphone

COMPILER 	= g++

STANDARD_FLAGS	= -Wall -Wextra -Werror -std=c++98

FILES		= megaphone.cpp

GREEN		= \033[0;32m
RED		= \033[0;31m
RESET		= \033[0m

all:		${NAME}
		
${NAME}:			
		$(COMPILER) -o $(NAME) $(FILES) $(STANDARD_FLAGS)
		@echo "\n$(NAME): $(GREEN)$(NAME) was created :)$(RESET)"
		@echo

clean:
		@echo "\n$(NAME): $(RED)$(NAME) was deleted$(RESET)"
		rm -f $(NAME)
		@echo

re :		clean all

.PHONY:		all clean re
