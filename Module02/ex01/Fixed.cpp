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
	_rawBits = 0;
}

Fixed::Fixed( int numValue )
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = (numValue << _fractBits);
}

Fixed::Fixed( float numValue )
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = (int) roundf((numValue * (1 << _fractBits)));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &obj )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed &Fixed::operator=( const Fixed &obj )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		_rawBits = obj.getRawBits();
	}
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	return (_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	_rawBits = raw;
}

int		Fixed::toInt( void ) const
{
	return (_rawBits >> _fractBits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)_rawBits / (float)(1 << _fractBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}