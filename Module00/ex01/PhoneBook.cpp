/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:11:43 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/05 00:49:46 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

PhoneBook::PhoneBook(void)
{
    //std::cout << "Constructor Called" <<std::endl;
    return ;
}

PhoneBook::~PhoneBook(void)
{
    //std::cout << "Destructor Called" <<std::endl;
    return ;
}

int PhoneBook::display_phonebook(void)
{
    int     index;

    index = 0;
    if (this->length == 0)
        return (1);
    std::cout << std::endl;
    std::cout << " .-------------------------------------------." << std::endl;
    std::cout << " |     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
    std::cout << " |-------------------------------------------|" << std::endl;
    while (index < this->length)
    {
        std::cout << " |         " << index << "|";
        contact[index].print_abrev_first_name();
        std::cout << "|";
        contact[index].print_abrev_last_name();
        std::cout << "|";
        contact[index].print_abrev_nickname();
        std::cout << "|" << std::endl;
        index++;
    }
    std::cout << " '-------------------------------------------'" << std::endl;
    std::cout << std::endl;
    return (0);
}


//  |  NICKNAME|
//  | LAST NAME|
//  |FIRST NAME|
//  |     INDEX|
//  |1234567890|
//  |12345KKKKK|