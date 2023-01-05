/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:33:47 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/05 00:17:46 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

int			user_input_command(void);
std::string	get_user_command(void);
int			set_command(std::string command);

int			add_contact(PhoneBook annuaire);
std::string	get_parameter(int parameter);
int			set_parameter(PhoneBook annuaire, int parameter, std::string value);
std::string	get_string(std::string message);
void		message_contact_created(void);

int			print_annuaire(PhoneBook annuaire);
void		message_no_data_found(void);

int			search_contact(PhoneBook annuaire);

std::string	get_index_from_user(void);
int			find_index(PhoneBook annuaire, std::string index);

void		print_abrev_string(std::string str, int max_wide);

int main(void)
{
	PhoneBook	annuaire;
	int			command;

	annuaire.length = 0;
	std::cout << L_ANNUAIRE_HEADER;
	while (true)
	{
		command = user_input_command();
		if (command == ADD)
		{
			if (add_contact(annuaire))
				break;
			message_contact_created();
			if (annuaire.length != MAX_CONTACTS)
				annuaire.length++;
		}
		else if (command == SEARCH)
		{
			if (annuaire.display_phonebook())
				message_no_data_found();
			if (search_contact(annuaire))
				message_no_data_found();
		}
		else if (command == EXIT)
			break;
	}
	return (0);
}

int user_input_command(void)
{
	std::string	command;

	command = get_user_command();
	return (set_command(command));
}

std::string get_user_command(void)
{
	std::string	command;

	std::cout << "[commands]: ADD, SEARCH, EXIT" << std::endl << std::endl;
	std::cout << "Please type a command:	";
	std::getline (std::cin, command);
	return (command);
}

int	set_command(std::string command)
{
	if (!command.compare("ADD"))
		return (ADD);
	else if (!command.compare("SEARCH"))
		return (SEARCH);
	else if (!command.compare("EXIT"))
		return (EXIT);
	else
		return (NONE);
}

int	add_contact(PhoneBook annuaire)
{
	std::string	content;
	
	content = get_parameter(FIRST_NAME);
	if (set_parameter(annuaire, FIRST_NAME, content))
		return (1);
	content = get_parameter(LAST_NAME);
	if (set_parameter(annuaire, LAST_NAME, content))
		return (1);
	content = get_parameter(NICKNAME);
	if (set_parameter(annuaire, NICKNAME, content))
		return (1);
	content = get_parameter(PHONE_NBR);
	if (set_parameter(annuaire, PHONE_NBR, content))
		return (1);
	content = get_parameter(DARK_SECRET);
	if (set_parameter(annuaire, DARK_SECRET, content))
		return (1);
	return (0);
}

std::string	get_parameter(int parameter)
{
	switch (parameter)
	{
		case FIRST_NAME:
			return (get_string("    First Name: "));
		case LAST_NAME:
			return (get_string("     Last Name: "));
		case NICKNAME:
			return (get_string("      Nickname: "));
		case PHONE_NBR:
			return (get_string("  Phone Number: "));
		case DARK_SECRET:
			return (get_string("Darkest Secret: "));
		default:
			std::cout << "Bad usage get_parameter" << std::endl;
			return (NULL);
	}
}

int	set_parameter(PhoneBook annuaire, int parameter, std::string value)
{
	int	i;

	i = annuaire.length;
	switch (parameter)
	{
		case FIRST_NAME:
			annuaire.contact[i].set_first_name(value);
			return (0);
		case LAST_NAME:
			annuaire.contact[i].set_last_name(value);
			return (0);
		case NICKNAME:
			annuaire.contact[i].set_nickname(value);
			return (0);
		case PHONE_NBR:
			annuaire.contact[i].set_phone_number(value);
			return (0);
		case DARK_SECRET:
			annuaire.contact[i].set_dark_secret(value);
			return (0);
		default:
			std::cout << RED "Bad usage set_parameter" RESET << std::endl;
			return (1);
	}
}

std::string	get_string(std::string message)
{
	std::string	content;
	
	while (!content[0])
	{
		std::cout << message;
		std::getline(std::cin, content);
	}
	return (content);
}

void	message_contact_created(void)
{
	std::cout \
	<< std::endl << GREEN "Contact was created" RESET << std::endl << std::endl;
}

int	print_annuaire(PhoneBook annuaire)
{
	annuaire.length--;
	annuaire.length++;
	return (1);
}

void	message_no_data_found(void)
{
	std::cout \
	<< std::endl << GREY "No data found" RESET << std::endl << std::endl;
}

int	search_contact(PhoneBook annuaire)
{
	std::string index;

	index = get_index_from_user();
	return (find_index(annuaire, index));
}

std::string	get_index_from_user(void)
{
	std::string index;

	std::cout << "Type the index: ";
	std::getline (std::cin, index);
	return (index);
}

int	find_index(PhoneBook annuaire, std::string index)
{
	if (index.length() > MAX_CONTACTS_IN_TENS)
		return (1);
	else if(!isdigit(index[0]))
		return (1);
	else if (index[0] <= annuaire.length + '0')
	{
		//annuaire.contact[index[0]].display_info();
		return (0);
	}
	return (1);
}

void	print_abrev_string(std::string str, int max_wide)
{
	int i;

	i = 0;
	while (str[i] && i < max_wide)
	{
		if (i == max_wide - 1 && str[i + 1])
		{
			std::cout << '.';
			break;
		}
		std::cout << str[i];
	}
}
