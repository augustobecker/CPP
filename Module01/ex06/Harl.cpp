/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:36:11 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/28 16:50:14 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(int argc, char **argv)
{
	std::string	argComplain;

	if (argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		exit (1);
	}
	if (!argv[argc - 1][0])
	{
		std::cout << "Null parameter passed" << std::endl;
		exit (1);
	}
	argComplain = argv[1];
	setComplainLevel(argComplain);
}

Harl::~Harl(void)
{
	return ;
}

Level   Harl::getComplainLevel(void)
{
	return (this->_complainLevel);
}

void    Harl::setComplainLevel(Level complain)
{
	this->_complainLevel = complain;
}

void    Harl::setComplainLevel(std::string complain)
{
	if (!complain.compare("DEBUG"))
	{
		this->_complainLevel = DEBUG;
		return ;
	}
	else if (!complain.compare("INFO"))
	{
		this->_complainLevel = INFO;
		return ;
	}
	else if (!complain.compare("WARNING"))
	{
		this->_complainLevel = WARNING;
		return ;
	}
	else if (!complain.compare("ERROR"))
	{
		this->_complainLevel = ERROR;
		return ;
	}
	this->_complainLevel = INSIGNIFICANT;
}

void Harl::complain( void )
{
	Harl::ComplainFunction	function[OPTIONS_NUM] = {
		&Harl::insignificant, &Harl::debug, &Harl::info, 
		&Harl::warning, &Harl::error};

	switch (this->_complainLevel)
	{
		case (INSIGNIFICANT):
			(this->*function[INSIGNIFICANT])();
			return ;
		case (ERROR):
			(this->*function[ERROR])();
			return ;
		case (WARNING):
			(this->*function[WARNING])();
			(this->*function[ERROR])();
			return ;
		case (INFO):
			(this->*function[INFO])();
			(this->*function[WARNING])();
			(this->*function[ERROR])();
			return ;
		case (DEBUG):
			(this->*function[DEBUG])();
			(this->*function[INFO])();
			(this->*function[WARNING])();
			(this->*function[ERROR])();
			return ;
	}
}

void Harl::insignificant( void )
{
	std::cout << "Not relevant";
	std::cout << std::endl;
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]";
	std::cout << std::endl;
	std::cout << "\tThe code works so far";
	std::cout << std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]";
	std::cout << std::endl;
	std::cout << "\tThis program is a debugger. It is composed by ";
	std::cout << "a class named Harl, that can display 4 different ";
	std::cout << std::endl;
	std::cout <<  "\tkind of messages to help you with the development.";
	std::cout << std::endl;
	std::cout <<  "\tThese 4 are divided in: ";
	std::cout <<  "debug, info, warning and error";
	std::cout << std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]";
	std::cout << std::endl;
	std::cout << "\tBe careful when doing this";
	std::cout << std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]";
	std::cout << std::endl;
	std::cout << "\tIt didn't work";
	std::cout << std::endl << std::endl;
}
