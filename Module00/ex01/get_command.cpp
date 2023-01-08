/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:00:19 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/08 19:00:57 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

int			user_input_command(void);
std::string	get_user_command(void);
int			set_command(std::string command);

int user_input_command(void)
{
	std::string	command;

	command = get_user_command();
	return (set_command(command));
}

std::string get_user_command(void)
{
	std::string	command;

	std::cout << "[commands]: ADD, SEARCH, EXIT" << std::endl << std::endl;
	std::cout << "Please type a command:	";
	std::getline (std::cin, command);
	return (command);
}

int	set_command(std::string command)
{
	if (!command.compare("ADD"))
		return (ADD);
	else if (!command.compare("SEARCH"))
		return (SEARCH);
	else if (!command.compare("EXIT"))
		return (EXIT);
	else
		return (NONE);
}
