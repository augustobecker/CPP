/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annuaire.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:29:38 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/08 21:59:24 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANNUAIRE_HPP
# define ANNUAIRE_HPP

# include <iostream>
# include <cctype>
# include "defines.hpp"
# include "types.hpp"
# include "PhoneBook.hpp"
# include "Contact.hpp"

int			user_input_command(void);
std::string	get_user_command(void);
int			set_command(std::string command);

int			add_contact(PhoneBook *annuaire);
std::string	get_parameter(int parameter);
int			set_parameter(PhoneBook *annuaire, int parameter, std::string value);
std::string	get_string(std::string message);
void		message_contact_created(void);

void		message_no_data_found(void);
int			search_contact(PhoneBook *annuaire);
std::string	get_index_from_user(void);
int			find_index(PhoneBook *annuaire, std::string index);

#endif