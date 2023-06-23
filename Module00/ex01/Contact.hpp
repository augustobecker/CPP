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

# include "annuaire.hpp"

class	Contact
{

public:

	Contact(void);
	~Contact(void);

	void		setFirstName(std::string);
	std::string	getFirstName(void);

	void		setLastName(std::string);
	std::string	getLastName(void);

	void		setNickname(std::string);
	std::string	getNickname(void);

	void		setPhoneNumber(std::string);
	std::string	getPhoneNumber(void);

	void		setDarkSecret(std::string);
	std::string	getDarkSecret(void);

	void		briefDescription(int index);
	void		displayData(void);

private:

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkSecret;

	static void	staticDisplayDataAbrev(
	const std::string& str, long unsigned int max_length);

};

#endif
