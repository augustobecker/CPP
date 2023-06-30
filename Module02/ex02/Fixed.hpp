/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 04:26:03 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/30 15:34:36 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{

private:

	int			_rawBits;

public:

	const static int	maxInt = 8388607;
	const static int	minInt = -8388608;
	const static int	fractBits = 8;

	Fixed( void );
	Fixed( int );
	Fixed( int , int);
	Fixed( float );
	~Fixed( void );

	Fixed(const Fixed &obj);
	Fixed& operator=(const Fixed &obj);
	
	Fixed operator+( const Fixed &obj );
	Fixed operator-( const Fixed &obj );
	Fixed operator*( const Fixed &obj );
	Fixed operator/( const Fixed &obj );

	Fixed operator++( void );
	Fixed operator++( int );

	Fixed operator--( void );
	Fixed operator--( int );

	bool operator==( const Fixed& );
	bool operator!=( const Fixed& );
	bool operator<( const Fixed&);
	bool operator>( const Fixed& );
	bool operator>=( const Fixed& );
	bool operator<=( const Fixed& );

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
