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

# include "annuaire.hpp"
# include "PhoneBook.hpp"
# include "Contact.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	int			command;

	std::cout << L_ANNUAIRE_HEADER;
	while (true)
	{
		command = phoneBook.getUserInputCommand();
		switch (command)
		{
			case ADD:
				phoneBook.addContact();
				break;
			case SEARCH:
				phoneBook.searchContact();
				break;
			case EXIT:
				return (0);
			default:
				break ;
		}
	}
	return (0);
}
