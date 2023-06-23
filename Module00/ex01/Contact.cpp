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

# include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getFirstName(void)
{
	return(_firstName);
}

void    Contact::setFirstName(std::string name)
{
	this->_firstName = name;
}

std::string	Contact::getLastName(void)
{
	return(_lastName);
}

void    Contact::setLastName(std::string name)
{
	this->_lastName = name;
}

std::string	Contact::getNickname(void)
{
	return(_nickname);
}

void    Contact::setNickname(std::string name)
{
	this->_nickname = name;
}

std::string	Contact::getPhoneNumber(void)
{
	return(_phoneNumber);
}

void    Contact::setPhoneNumber(std::string number)
{
	this->_phoneNumber = number;
}

std::string	Contact::getDarkSecret(void)
{
	return(_darkSecret);
}

void	Contact::setDarkSecret(std::string secret)
{
	this->_darkSecret = secret;
}

void	Contact::briefDescription(int index)
{
	std::cout << " |         " << index + 1 << "|";
	staticDisplayDataAbrev(_firstName, MAX_WIDE_ANNUAIRE_LIST);
	staticDisplayDataAbrev(_lastName, MAX_WIDE_ANNUAIRE_LIST);
	staticDisplayDataAbrev(_nickname, MAX_WIDE_ANNUAIRE_LIST);
	std::cout << std::endl;
}

void	Contact::displayData(void)
{
	std::cout << std::endl;
	std::cout << "	First name     : " << _firstName << std::endl;
	std::cout << "	Last name      : " << _lastName << std::endl;
	std::cout << "	Nickame        : " << _nickname << std::endl;
	std::cout << "	Phone Number   : " << _phoneNumber << std::endl;
	std::cout << "	Darkest Secret : " << _darkSecret << std::endl;
	std::cout << std::endl;
}

void	Contact::staticDisplayDataAbrev(
	const std::string& str, long unsigned int max_length)
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
