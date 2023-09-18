#include "Fixed.hpp"

Fixed::Fixed( void )
{
	_rawBits = 0;
}

Fixed::Fixed( int numValue )
{
	_rawBits = (numValue << _fractBits);
}

Fixed::Fixed( int fixedPoint, int fractionalBits)
{
	if (fractionalBits == _fractBits)
		_rawBits = fixedPoint;
}

Fixed::Fixed( float numValue )
{
	_rawBits = (int) roundf((numValue * (1 << _fractBits)));
}

Fixed::~Fixed( void )
{
    return ;
}

Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	if (this != &obj)
		_rawBits = obj.getRawBits();
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
	currentIntPart = _rawBits >> _fractBits;
    currentFracPart = _rawBits & _maskFractBits;
    newIntPart = obj.getRawBits() >> _fractBits;
    newFracPart = obj.getRawBits() & _maskFractBits;
    rawBitsResult += (currentIntPart * newIntPart) << _fractBits;
    rawBitsResult += (currentIntPart * newFracPart);
    rawBitsResult += (currentFracPart * newIntPart);
    rawBitsResult += ((currentFracPart * newFracPart) >> _fractBits) & _maskFractBits;
	return (Fixed(rawBitsResult, _fractBits));
}

Fixed Fixed::operator/( const Fixed &obj ) const
{
	int	rawBitsResult;

	rawBitsResult = (int)((long)(_rawBits << _fractBits) / obj.getRawBits());
	return (Fixed(rawBitsResult, _fractBits));
}

Fixed Fixed::operator++( void )
{
	_rawBits++;
	return (Fixed(_rawBits, _fractBits));
}

Fixed Fixed::operator++( int )
{
	int tempBits;

	tempBits = _rawBits;
	_rawBits++;
	return (Fixed(tempBits, _fractBits));
}

Fixed Fixed::operator--( void )
{
	_rawBits--;
	return (Fixed(_rawBits, _fractBits));
}

Fixed Fixed::operator--( int )
{
	int tempBits;

	tempBits = _rawBits;
	_rawBits--;
	return (Fixed(tempBits, _fractBits));
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
