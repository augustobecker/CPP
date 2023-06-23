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
	int		value;
	static int	fract_bits;

public:
	Fixed( void );
	~Fixed( void );

	Fixed(const Fixed &obj);
    	Fixed& operator=(const Fixed &obj);

	int	getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif