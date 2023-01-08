/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:55:08 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/08 21:45:28 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

int			add_contact(PhoneBook *annuaire);
std::string	get_parameter(int parameter);
int			set_parameter(PhoneBook *annuaire, int parameter, std::string value);
std::string	get_string(std::string message);
void		message_contact_created(void);

int	add_contact(PhoneBook *annuaire)
{
	std::string	content;
	
	content = get_parameter(FIRST_NAME);
	if (set_parameter(annuaire, FIRST_NAME, content))
		return (1);
	content = get_parameter(LAST_NAME);
	if (set_parameter(annuaire, LAST_NAME, content))
		return (1);
	content = get_parameter(NICKNAME);
	if (set_parameter(annuaire, NICKNAME, content))
		return (1);
	content = get_parameter(PHONE_NBR);
	if (set_parameter(annuaire, PHONE_NBR, content))
		return (1);
	content = get_parameter(DARK_SECRET);
	if (set_parameter(annuaire, DARK_SECRET, content))
		return (1);
	return (0);
}

std::string	get_parameter(int parameter)
{
	switch (parameter)
	{
		case FIRST_NAME:
			return (get_string("    First Name: "));
		case LAST_NAME:
			return (get_string("     Last Name: "));
		case NICKNAME:
			return (get_string("      Nickname: "));
		case PHONE_NBR:
			return (get_string("  Phone Number: "));
		case DARK_SECRET:
			return (get_string("Darkest Secret: "));
		default:
			std::cout << "Bad usage get_parameter" << std::endl;
			return (NULL);
	}
}

int	set_parameter(PhoneBook *annuaire, int parameter, std::string value)
{
	int	i;

	i = annuaire->length - 1;
	switch (parameter)
	{
		case FIRST_NAME:
			annuaire->contact[i].set_first_name(value);
			return (0);
		case LAST_NAME:
			annuaire->contact[i].set_last_name(value);
			return (0);
		case NICKNAME:
			annuaire->contact[i].set_nickname(value);
			return (0);
		case PHONE_NBR:
			annuaire->contact[i].set_phone_number(value);
			return (0);
		case DARK_SECRET:
			annuaire->contact[i].set_dark_secret(value);
			return (0);
		default:
			std::cout << RED "Bad usage set_parameter" RESET << std::endl;
			return (1);
	}
}

std::string	get_string(std::string message)
{
	std::string	content;
	
	while (!content[0])
	{
		std::cout << message;
		std::getline(std::cin, content);
	}
	return (content);
}

void	message_contact_created(void)
{
	std::cout \
	<< std::endl << GREEN "Contact was created" RESET << std::endl << std::endl;
}
