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

#include "annuaire.hpp"
#include "Contact.hpp"

class PhoneBook
{
	
public:

	PhoneBook(void);
	~PhoneBook(void);

	Contact	contact[MAX_CONTACTS];
	int		length;
	
	int		display_phonebook(void);

};

#endif
