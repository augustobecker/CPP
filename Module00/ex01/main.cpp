/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:33:47 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/04 15:50:01 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

int main(void)
{
	PhoneBook	annuaire;
	std::string	command;
	std::string	value;
	int			i;

	i = 0;  
	while (true)
	{
		std::cin >> command;
		if (!command.compare("ADD"))
		{
			std::cout << "    First Name: ";
			std::cin >> value;
			annuaire.contact[i].set_first_name(value);
			std::cout << "     Last Name: ";
			std::cin >> value;
			annuaire.contact[i].set_last_name(value);
			std::cout << "      Nickname: ";
			std::cin >> value;
			annuaire.contact[i].set_nickname(value);
			std::cout << "  Phone Number: ";
			std::cin >> value;
			annuaire.contact[i].set_phone_number(value);
			std::cout << "Darkest Secret: ";
			std::cin >> value;
			annuaire.contact[i].set_dark_secret(value);
			if (i != MAX_CONTACTS)
				i++;
		}
		if (!command.compare("SEARCH"))
		{
			std::cout << "Type the index: ";
			std::cin >> value;
			if ((!value.compare("1") || !value.compare("2") \
			|| !value.compare("3") || !value.compare("4") \
			|| !value.compare("5") || !value.compare("6") \
			|| !value.compare("7") || !value.compare("8")))
			{
				if (i >= (value[0] - 48 - 1))
					annuaire.contact[i].display_info();
			}
		}
		if (!command.compare("EXIT"))
			break;
	}
	return (0);
}
