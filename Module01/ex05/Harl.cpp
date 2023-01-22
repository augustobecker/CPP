/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:14:05 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/22 20:24:08 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain( std::string level )
{
	std::string options[OPTIONS_NUM] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*f[OPTIONS_NUM])( void );
	int			i;

	i = 0;
	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
	while (i < OPTIONS_NUM)
	{
		if (!level.compare(options[i]))
		{
			(this->*f[i])();
			return ;
		}
		i++;
	}
	std::cout << "Bad usage: Harl::complain : passed param is not an option";
	std::cout << std::endl << std::endl;
}

void Harl::debug( void )
{
	std::cout << "Debug: The code works so far";
	std::cout << std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << "Info: This program is a debugger. It is composed by ";
	std::cout << "a class named Harl, that can display 4 different ";
	std::cout << std::endl;
	std::cout <<  "kind of messages to help you with the development.";
	std::cout << std::endl;
	std::cout <<  "These 4 are divided in: ";
	std::cout <<  "debug, info, warning and error";
	std::cout << std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << "Warning: Be careful when doing this";
	std::cout << std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout << "Error: It didn't work";
	std::cout << std::endl << std::endl;
}
