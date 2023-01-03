#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "annuaire.hpp"

class PhoneBook
{
	
public:

	PhoneBook(void);
	~PhoneBook(void);

	Contact	Contacts[8];
	int		length;
	
};

#endif
