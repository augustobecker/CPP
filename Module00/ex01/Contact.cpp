/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:21:21 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/05 01:01:19 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

Contact::Contact(void)
{
	//std::cout << "Constructor Called Contact" <<std::endl;
	return ;
}

Contact::~Contact(void)
{
	//std::cout << "Destructor Called Contact" <<std::endl;
	return ;
}

void    Contact::set_first_name(std::string name)
{
	this->_first_name = name;
}

void    Contact::set_last_name(std::string name)
{
	this->_last_name = name;
}

void    Contact::set_nickname(std::string name)
{
	this->_nickname = name;
}

void    Contact::set_phone_number(std::string number)
{
	this->_phone_number = number;
}

void	Contact::set_dark_secret(std::string secret)
{
	this->_dark_secret = secret;
}

int Contact::print_abrev_first_name(void)
{
	std::cout << this->_first_name;
	return ((MAX_WIDE_ANNUAIRE_LIST - 1) - this->_first_name.length());
}

int Contact::print_abrev_last_name(void)
{
	if ((int) _last_name.length() >= MAX_WIDE_ANNUAIRE_LIST - 1)
		return (0);
	else
	{
		std::cout << _last_name;
		return ((MAX_WIDE_ANNUAIRE_LIST - 1) - _last_name.length());
	}
	return 1;
}

int Contact::print_abrev_nickname(void)
{
	if ((int) _nickname.length() >= MAX_WIDE_ANNUAIRE_LIST - 1)
		return (0);
	else
	{
		std::cout << _nickname;
		return ((MAX_WIDE_ANNUAIRE_LIST - 1) - _nickname.length());
	}
	return 1;
}