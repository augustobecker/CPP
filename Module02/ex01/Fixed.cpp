/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 04:26:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/30 19:54:56 by acesar-l         ###   ########.fr       */
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
	if (numValue >= maxInt)
		this->_rawBits = (maxInt << fractBits);
	else if (numValue <= minInt)
		this->_rawBits = (minInt << fractBits);
	else
		this->_rawBits = (numValue << fractBits);
}

Fixed::Fixed( float numValue )
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = static_cast<int>(numValue * 256);
}

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

float	Fixed::toFloat( void ) const
{
	int		intPart;
    int		fractionalPart;
	float	floatNum;

	intPart = _rawBits >> fractBits;
    fractionalPart = _rawBits & MaskFractBits;
	floatNum = static_cast<float>(fractionalPart) / MaskFractBits;
	floatNum += intPart;
	return (floatNum);
}

std::ostream& operator<<(std::ostream& os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}