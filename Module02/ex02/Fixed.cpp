/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:21:36 by codespace         #+#    #+#             */
/*   Updated: 2023/06/29 17:24:52 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	this->_rawBits = 0;
}

Fixed::Fixed( int numValue )
{
	if (numValue >= maxInt)
		this->_rawBits = (maxInt << fractBits);
	else if (numValue <= minInt)
		this->_rawBits = (minInt << fractBits);
	else
		this->_rawBits = (numValue << fractBits);
}

Fixed::Fixed( float numValue )
{
	this->_rawBits = static_cast<int>(numValue * 256);
}

Fixed::~Fixed( void )
{
    return ;
}

Fixed::Fixed(const Fixed &obj)
{
	this->_rawBits = obj.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	if (this != &obj)
		this->_rawBits = obj.getRawBits();
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
    fractionalPart = _rawBits & 0xFF;
	floatNum = static_cast<float>(fractionalPart) / (0xFF - 1);
	floatNum += intPart;
	return (floatNum);
}

std::ostream& operator<<(std::ostream& os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}
