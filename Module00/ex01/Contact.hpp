#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "annuaire.hpp"

class	Contact
{

public:

	Contact(void);
	~Contact(void);

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;

	void	display_info(void);

private:

	unsigned int	_phone_number;
	std::string		_dark_secret;

};

#endif
