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
	
	int		print_abrev_first_name(void);
	int		print_abrev_last_name(void);
	int		print_abrev_nickname(void);

private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_dark_secret;

};

#endif
