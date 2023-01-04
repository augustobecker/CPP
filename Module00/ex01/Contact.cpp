/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:21:21 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/04 15:52:21 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

Contact::Contact(void)
{
    std::cout << "Constructor Called Contact" <<std::endl;
    return ;
}

Contact::~Contact(void)
{
    std::cout << "Destructor Called Contact" <<std::endl;
    return ;
}

void    Contact::set_first_name(std::string name)
{
    this->first_name = name;
}

void    Contact::set_last_name(std::string name)
{
    this->last_name = name;
}

void    Contact::set_nickname(std::string name)
{
    this->nickname = name;
}

void    Contact::set_phone_number(std::string)
{
    
}

void	Contact::set_dark_secret(std::string)
{
    
}

void    Contact::display_info(void)
{
    std::cout << this->first_name <<std::endl;
    std::cout << this->last_name <<std::endl;
    std::cout << this->nickname <<std::endl;
}
