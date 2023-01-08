/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:33:06 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/08 21:51:43 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	void	brief_description(int index);
	void	print_data(void);

private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_dark_secret;

	void	_print_abrev(std::string str, long unsigned int max_length);
	
};

#endif
