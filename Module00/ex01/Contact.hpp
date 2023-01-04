#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "annuaire.hpp"

class	Contact
{

public:

	Contact(void);
	~Contact(void);

	void	set_first_name(std::string);
	void	set_last_name(std::string);
	void	set_nickname(std::string);
	void	set_phone_number(std::string);
	void	set_dark_secret(std::string);
	void	display_info(void);

private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	_phone_number;
	std::string	_dark_secret;

};

#endif
