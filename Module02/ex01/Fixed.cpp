/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 04:26:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/23 04:27:29 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}

Fixed::Fixed( int numValue )
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = 0;
	this->_rawBits = (numValue << fractBits);
}

/*
Fixed::Fixed( float numValue )
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = 0;
}
*/

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawBits = obj.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_rawBits = obj.getRawBits();
	}
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}

int		Fixed::toInt( void ) const
{
	return (this->_rawBits >> this->fractBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed &obj)
{
        os << (obj.getRawBits() >> obj.fractBits);
        return os;
}