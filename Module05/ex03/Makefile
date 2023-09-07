NAME			= Intern

COMPILER		= c++
STANDARD_FLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS			=	AForm.cpp					\
				  	Bureaucrat.cpp				\
					Intern.cpp					\
				  	ShrubberyCreationForm.cpp	\
					RobotomyRequestForm.cpp		\
					PresidentialPardonForm.cpp	\
					main.cpp

OBJS			= ${SRCS:.cpp=.o}

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

%.o:			%.cpp
				${COMPILER} ${STANDARD_FLAGS} -c $< -o $@

${NAME}:		${OBJS}
				${COMPILER} -o ${NAME} ${OBJS} ${STANDARD_FLAGS}
				@echo "${NAME}: ${GREEN}${NAME} was generated${RESET}"

all:			${NAME}

clean:
				rm -f ${OBJS}
				@echo "${NAME}: ${RED} Objects were destroyed ${RESET}"

fclean:			clean
				rm -f ${NAME}
				@echo "${NAME}: ${RED}${NAME} was destroyed ${RESET}"

re:				clean all

.PHONY:			all clean fclean re
