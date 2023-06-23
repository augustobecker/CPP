/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:33:24 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/08 21:58:37 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "annuaire.hpp"
# include "Contact.hpp"

class PhoneBook
{
public:

	PhoneBook(void);
	~PhoneBook(void);

	static const int MAX_CONTACTS = 8;

	Contact	contact[MAX_CONTACTS];
	
	int		getUserInputCommand(void);

	void	addContact(void);
	void	searchContact(void);

	int 	displayContactsBriefData(void);

private:

	int		_numContacts;
	int		_idNewestContact;

	static std::string	staticGetUserParameter(Parameter parameter);
	static std::string	staticGetUserInputNonEmptyString(
		const std::string& promptMessage);

	static void			staticMessageContactCreated(void);
	static void			staticMessageNoDataFound(void);
	
};


#endif
