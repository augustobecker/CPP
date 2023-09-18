#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{

private:

	int					_rawBits;
	const static int	_fractBits = 8;
	const static int	_maskFractBits = 0xFF;

public:


	Fixed( void );
	Fixed( int );
	Fixed( int , int);
	Fixed( float );
	~Fixed( void );

	Fixed(const Fixed &obj);
	Fixed& operator=(const Fixed &obj);
	
	Fixed operator+( const Fixed &obj ) const;
	Fixed operator-( const Fixed &obj ) const;
	Fixed operator*( const Fixed &obj ) const;
	Fixed operator/( const Fixed &obj ) const;

	Fixed operator++( void );
	Fixed operator++( int );

	Fixed operator--( void );
	Fixed operator--( int );

	bool operator==( const Fixed& ) const;
	bool operator!=( const Fixed& ) const;
	bool operator<( const Fixed&) const;
	bool operator>( const Fixed& ) const;
	bool operator>=( const Fixed& ) const;
	bool operator<=( const Fixed& ) const;

	static Fixed& min( Fixed&, Fixed& );
	const static Fixed& min( const Fixed&, const Fixed& );
	static Fixed& max( Fixed&, Fixed& );
	const static Fixed& max( const Fixed&, const Fixed& );

	int		getRawBits( void ) const;
	void	setRawBits( const int );

	int		toInt( void ) const;
	float	toFloat( void ) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed &obj);

#endif