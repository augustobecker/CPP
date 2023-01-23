/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:36:11 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/23 04:04:01 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain( t_level complain )
{
	void    (Harl::*f[OPTIONS_NUM])( void );

	f[INSIGNIFICANT] = &Harl::insignificant;
	f[DEBUG] = &Harl::debug;
	f[INFO] = &Harl::info;
	f[WARNING] = &Harl::warning;
    f[ERROR] = &Harl::error;
    switch (complain)
    {
        case (INSIGNIFICANT):
            (this->*f[INSIGNIFICANT])();
            return ;
        case (ERROR):
            (this->*f[ERROR])();
            return ;
        case (WARNING):
            (this->*f[WARNING])();
            (this->*f[ERROR])();
            return ;
        case (INFO):
            (this->*f[INFO])();
            (this->*f[WARNING])();
            (this->*f[ERROR])();
            return ;
        case (DEBUG):
            (this->*f[DEBUG])();
            (this->*f[INFO])();
            (this->*f[WARNING])();
            (this->*f[ERROR])();
            return ;
    }
}

void Harl::insignificant( void )
{
	std::cout << "Not relevant";
	std::cout << std::endl << std::endl;
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
