/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 04:26:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/30 20:34:51 by acesar-l         ###   ########.fr       */
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
	int sunFloatOne = (1 << this->fractBits); 
	int intPart = (int) numValue;
	float fracPart = numValue - intPart;

	this->_rawBits = intPart << this->fractBits;
	this->_rawBits += (int)(sunFloatOne * fracPart);
}

Fixed::~Fixed( void )
{
    return ;
}

Fixed::Fixed(const Fixed &obj)
{
	this->_rawBits = obj.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &obj) const
{
	if (this != &obj)
		this->_rawBits = obj.getRawBits();
	return (*this);
}

Fixed Fixed::operator+( const Fixed &obj ) const
{
	return (Fixed(_rawBits + obj.getRawBits(), _fractBits));
}

Fixed Fixed::operator-( const Fixed &obj ) const
{
	return (Fixed(_rawBits - obj.getRawBits(), _fractBits));
}

Fixed Fixed::operator*( const Fixed &obj ) const
{
	int currentIntPart, currentFracPart;
	int newIntPart, newFracPart;
	int	rawBitsResult;

	rawBitsResult = 0;
	currentIntPart = _rawBits >> fractBits;
    currentFracPart = _rawBits & MaskFractBits;
    newIntPart = obj.getRawBits() >> fractBits;
    newFracPart = obj.getRawBits() & MaskFractBits;
    rawBitsResult += (currentIntPart * newIntPart) << fractBits;
    rawBitsResult += (currentIntPart * newFracPart);
    rawBitsResult += (currentFracPart * newIntPart);
    rawBitsResult += ((currentFracPart * newFracPart) >> fractBits) & MaskFractBits;
	return (Fixed(rawBitsResult, fractBits));
}

Fixed Fixed::operator/( const Fixed &obj ) const
{
	int	rawBitsResult;

	rawBitsResult = (int)((long)(_rawBits << fractBits) / obj.getRawBits());
	return (Fixed(rawBitsResult, fractBits));
}

Fixed Fixed::operator++( void )
{
	this->_rawBits++;
	return (Fixed(this->_rawBits, this->fractBits));
}

Fixed Fixed::operator++( int )
{
	int tempBits;

	tempBits = this->_rawBits;
	this->_rawBits++;
	return (Fixed(tempBits, this->fractBits));
}

Fixed Fixed::operator--( void )
{
	this->_rawBits--;
	return (Fixed(this->_rawBits, this->fractBits));
}

Fixed Fixed::operator--( int )
{
	int tempBits;

	tempBits = this->_rawBits;
	this->_rawBits--;
	return (Fixed(tempBits, this->fractBits));
}

bool Fixed::operator==( const Fixed &compare ) const
{
	return (_rawBits == compare.getRawBits());
}

bool Fixed::operator!=( const Fixed &compare ) const
{
	return (_rawBits != compare.getRawBits());
}

bool Fixed::operator<( const Fixed &compare ) const
{
	return (_rawBits < compare.getRawBits());
}

bool Fixed::operator>( const Fixed &compare ) const
{
	return (_rawBits > compare.getRawBits());
}

bool Fixed::operator>=( const Fixed &compare ) const
{
	return (_rawBits >= compare.getRawBits());
}

bool Fixed::operator<=( const Fixed &compare ) const
{
	return (_rawBits <= compare.getRawBits());
}

Fixed& Fixed::min( Fixed &obj1 , Fixed &obj2 ) const
{
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}

const Fixed& Fixed::min( const Fixed&obj1 , const Fixed &obj2 ) const
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return (obj1);
	return (obj2);
}

Fixed& Fixed::max( Fixed &obj1, Fixed &obj2 ) const
{
	if (obj1 > obj2)
		return (obj1);
	return (obj2);
}

const Fixed& Fixed::max( const Fixed &obj1 , const Fixed& obj2 ) const
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
	floatNum = static_cast<float>(fractionalPart) / MaskFractBits;
	floatNum += intPart;
	return (floatNum);
}

std::ostream& operator<<(std::ostream& os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}
