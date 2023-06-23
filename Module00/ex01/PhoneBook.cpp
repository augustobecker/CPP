/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:11:43 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/08 21:51:20 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->_numContacts = 0;
	this->_idNewestContact = 0;
    return ;
}

PhoneBook::~PhoneBook(void)
{
    return ;
}

void    PhoneBook::addContact(void)
{
    int i;

	this->_idNewestContact++;
	if (this->_idNewestContact > MAX_CONTACTS)
		this->_idNewestContact = 1;
    i = this->_idNewestContact - 1;
	this->contact[i].setFirstName(staticGetUserParameter(FIRST_NAME));
	this->contact[i].setLastName(staticGetUserParameter(LAST_NAME));
	this->contact[i].setNickname(staticGetUserParameter(NICKNAME));
	this->contact[i].setPhoneNumber(staticGetUserParameter(PHONE_NBR));
	this->contact[i].setDarkSecret(staticGetUserParameter(DARK_SECRET));
	staticMessageContactCreated();
	if (this->_numContacts < MAX_CONTACTS)
		this->_numContacts++;
}

void	PhoneBook::searchContact(void)
{
	std::string	str_index;
	int			index;

	displayContactsBriefData();
	str_index = staticGetUserInputNonEmptyString("Type the index: ");
	index = atoi(str_index.c_str());
	if (index <= 0 || index > MAX_CONTACTS || index > this->_numContacts)
	{
		staticMessageNoDataFound();
		return ;
	}
	this->contact[index - 1].displayData();
}

int PhoneBook::displayContactsBriefData(void)
{
    int     index;

    index = 0;
    if (this->_numContacts == 0)
        return (1);
    std::cout << std::endl;
    std::cout << " .-------------------------------------------." << std::endl;
    std::cout << " |     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
    std::cout << " |-------------------------------------------|" << std::endl;
    while (index < this->_numContacts)
    {
        contact[index].briefDescription(index);
        index++;
    }
    std::cout << " '-------------------------------------------'" << std::endl;
    std::cout << std::endl;
    return (0);
}

int	PhoneBook::getUserInputCommand(void)
{
	std::string	command;

	command = staticGetUserInputNonEmptyString("Type a command(ADD, SEARCH, EXIT): ");
	if (!command.compare("ADD"))
		return (ADD);
	else if (!command.compare("SEARCH"))
		return (SEARCH);
	else if (!command.compare("EXIT"))
		return (EXIT);
	return (NONE);
}

std::string	PhoneBook::staticGetUserParameter(Parameter parameter)
{
	switch (parameter)
	{
		case FIRST_NAME:
			return (staticGetUserInputNonEmptyString("    First Name: "));
		case LAST_NAME:
			return (staticGetUserInputNonEmptyString("     Last Name: "));
		case NICKNAME:
			return (staticGetUserInputNonEmptyString("      Nickname: "));
		case PHONE_NBR:
			return (staticGetUserInputNonEmptyString("  Phone Number: "));
		case DARK_SECRET:
			return (staticGetUserInputNonEmptyString("Darkest Secret: "));
		default:
			std::cout << "Bad usage get_parameter" << std::endl;
			return (NULL);
	}
}

std::string PhoneBook::staticGetUserInputNonEmptyString(
	const std::string& message)
{
	std::string	content;
	
	while (content.empty())
	{
		std::cout << message;
		std::getline(std::cin, content);
	}
	return (content);
}

void PhoneBook::staticMessageContactCreated(void)
{
	std::cout << std::endl << GREEN "Contact was created" RESET << std::endl << std::endl;
}

void PhoneBook::staticMessageNoDataFound(void)
{
	std::cout << std::endl << GREY "No data found" RESET << std::endl << std::endl;
}