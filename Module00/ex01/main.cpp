/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:33:47 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/08 21:55:27 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

int main(void)
{
	PhoneBook	annuaire;
	int			command;

	std::cout << L_ANNUAIRE_HEADER;
	while (true)
	{
		command = user_input_command();
		if (command == ADD)
		{
			if (annuaire.length != MAX_CONTACTS)
				annuaire.length++;
			if (add_contact(&annuaire))
				break;
			message_contact_created();
		}
		else if (command == SEARCH)
		{
			if (annuaire.display_phonebook())
				message_no_data_found();
			if (search_contact(&annuaire))
				message_no_data_found();
		}
		else if (command == EXIT)
			break;
	}
	return (0);
}
