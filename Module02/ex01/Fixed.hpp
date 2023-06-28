/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 04:26:03 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/23 04:26:34 by acesar-l         ###   ########.fr       */
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

	const static int	fractBits = 8;

	Fixed( void );
	Fixed( int );
	//Fixed( float );
	~Fixed( void );

	Fixed(const Fixed &obj);
	Fixed& operator=(const Fixed &obj);

	int		getRawBits( void ) const;
	void	setRawBits( const int );

	int		toInt( void ) const;
	//float	toFloat( void ) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed &obj);

#endif
