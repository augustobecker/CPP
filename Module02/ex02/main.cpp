/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:22:03 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/29 17:24:15 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

int main( void )
{
    Fixed a;
    //Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    //std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    //std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    //std::cout << b << std::endl;
    //std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}
