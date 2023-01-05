#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "annuaire.hpp"
#include "Contact.hpp"

class PhoneBook
{
	
public:

	PhoneBook(void);
	~PhoneBook(void);

	Contact	contact[8];
	int		length;

	int	display_phonebook(void);

};

#endif
