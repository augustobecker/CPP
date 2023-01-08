/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_contact.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:54:56 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/08 21:57:54 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

void		message_no_data_found(void);
int			search_contact(PhoneBook *annuaire);
std::string	get_index_from_user(void);
int			find_index(PhoneBook *annuaire, std::string index);

void	message_no_data_found(void)
{
	std::cout \
	<< std::endl << GREY "No data found" RESET << std::endl << std::endl;
}

int	search_contact(PhoneBook *annuaire)
{
	std::string	index;

	index = get_index_from_user();
	return (find_index(annuaire, index));
}

std::string	get_index_from_user(void)
{
	std::string	index;

	while (!index[0])
	{
		std::cout << "Type the index: ";
		std::getline(std::cin, index);
	}
	return (index);
}

int	find_index(PhoneBook *annuaire, std::string index)
{
	int	index_contact;

	index_contact = index[0] - '0' - 1;
	if (index.length() > MAX_CONTACTS_IN_TENS)
		return (1);
	else if(!isdigit(index[0]))
		return (1);
	else if ((index[0] > '0')
	&& (index[0] <= annuaire->length + '0'))
	{
		annuaire->contact[index_contact].print_data();
		return (0);
	}
	return (1);
}
