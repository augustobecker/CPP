/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 04:26:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/30 15:34:59 by acesar-l         ###   ########.fr       */
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

Fixed::Fixed( int fixedPoint, int fractionalBits)
{
	if (fractionalBits == this->fractBits)
		this->_rawBits = fixedPoint; 
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

Fixed Fixed::operator+( const Fixed &obj )
{
	return (Fixed(_rawBits + obj.getRawBits(), fractBits));
}

Fixed Fixed::operator-( const Fixed &obj )
{
	return (Fixed(_rawBits - obj.getRawBits(), fractBits));
}

Fixed Fixed::operator*( const Fixed &obj )
{
	return (Fixed(_rawBits + obj.getRawBits(), fractBits));
}

Fixed Fixed::operator/( const Fixed &obj )
{
	return (Fixed(_rawBits + obj.getRawBits(), fractBits));
}

Fixed Fixed::operator++( void )
{
	int	increment;

	increment = 1 << fractBits;
	this->_rawBits += increment;
	return (Fixed(this->_rawBits, this->fractBits));
}

Fixed Fixed::operator++( int )
{
	int	increment;

	increment = 1 << fractBits;
	this->_rawBits += increment;
	return (Fixed(this->_rawBits - increment, this->fractBits));
}

Fixed Fixed::operator--( void )
{
	int	increment;

	increment = 1 << fractBits;
	this->_rawBits -= increment;
	return (Fixed(this->_rawBits, this->fractBits));
}

Fixed Fixed::operator--( int )
{
	int	increment;

	increment = 1 << fractBits;
	this->_rawBits -= increment;
	return (Fixed(this->_rawBits + increment, this->fractBits));
}

bool Fixed::operator==( const Fixed &compare )
{
	return (_rawBits == compare.getRawBits());
}

bool Fixed::operator!=( const Fixed &compare )
{
	return (_rawBits != compare.getRawBits());
}

bool Fixed::operator<( const Fixed &compare )
{
	return (_rawBits < compare.getRawBits());
}

bool Fixed::operator>( const Fixed &compare )
{
	return (_rawBits > compare.getRawBits());
}

bool Fixed::operator>=( const Fixed &compare )
{
	return (_rawBits >= compare.getRawBits());
}

bool Fixed::operator<=( const Fixed &compare )
{
	return (_rawBits <= compare.getRawBits());
}

Fixed& Fixed::min( Fixed &obj1 , Fixed &obj2 )
{
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}

const Fixed& Fixed::min( const Fixed&obj1 , const Fixed &obj2 )
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return (obj1);
	return (obj2);
}

Fixed& Fixed::max( Fixed &obj1, Fixed &obj2 )
{
	if (obj1 > obj2)
		return (obj1);
	return (obj2);
}

const Fixed& Fixed::max( const Fixed &obj1 , const Fixed& obj2 )
{
	Fixed max;

	if (obj1.getRawBits() > obj2.getRawBits())
		return (obj1);
	return (obj2);
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
