/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:21:21 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/08 21:52:23 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

Contact::Contact(void)
{
	//std::cout << "Contact Created" <<std::endl;
	return ;
}

Contact::~Contact(void)
{
	//std::cout << "Contact Destroyed" <<std::endl;
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

void	Contact::brief_description(int index)
{
	std::cout << " |         " << index + 1 << "|";
	_print_abrev(this->_first_name, MAX_WIDE_ANNUAIRE_LIST);
	_print_abrev(this->_last_name, MAX_WIDE_ANNUAIRE_LIST);
	_print_abrev(this->_nickname, MAX_WIDE_ANNUAIRE_LIST);
	std::cout << std::endl;
}

void	Contact::print_data(void)
{
	std::cout << std::endl;
	std::cout << "	First name     : " << this->_first_name << std::endl;
	std::cout << "	Last name      : " << this->_last_name << std::endl;
	std::cout << "	Nickame        : " << this->_nickname << std::endl;
	std::cout << "	Phone Number   : " << this->_phone_number << std::endl;
	std::cout << "	Darkest Secret : " << this->_dark_secret << std::endl;
	std::cout << std::endl;
}

void	Contact::_print_abrev(std::string str, long unsigned int max_length)
{
	int spaces;
	int	i;

	i = 0;
	if (str.length() == max_length)
		std::cout << str;
	else if (str.length() >= max_length)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		spaces = max_length - str.length();
		while (i < spaces)
		{
			std::cout << " ";
			i++;
		}
		std::cout << str;
	}
	std::cout << "|";
}
