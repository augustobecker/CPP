/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:11:43 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/08 21:51:20 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

PhoneBook::PhoneBook(void)
{
    this->length = 0;
    //std::cout << "PhoneBook Created" <<std::endl;
    return ;
}

PhoneBook::~PhoneBook(void)
{
    //std::cout << "PhoneBook Destroyed" <<std::endl;
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
        contact[index].brief_description(index);
        index++;
    }
    std::cout << " '-------------------------------------------'" << std::endl;
    std::cout << std::endl;
    return (0);
}
