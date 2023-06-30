/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:22:03 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/30 15:58:20 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "|||| Subject Main Tests ||||||" << std::endl << std::endl;
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a + a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl << std::endl;

    std::cout << "||||||||||||||||||||||||||||||||" << std::endl << std::endl;
    std::cout << "|||| Comparison Operators ||||||" << std::endl << std::endl;

    Fixed c( 5.5f );
    Fixed d( 4.34f );
    Fixed e( 1.5f );
    Fixed f( e );

    if ( c > d )
        std::cout << "\t > : (c > d) : true" << std::endl;
    else
        std::cout << "\t > : (c > d) : false" << std::endl;
    std::cout << "\tc : " << c << std::endl;
    std::cout << "\td : " << d << std::endl << std::endl;

    if (d < c)
        std::cout << "\t < : (d < c) : true" << std::endl;
    else
        std::cout << "\t < : (d < c) : false" << std::endl;
    std::cout << "\td : " << d << std::endl;
    std::cout << "\tc : " << c << std::endl << std::endl;

    if (f == e)
        std::cout << "\t == : (f == e) : true" << std::endl;
    else
        std::cout << "\t == : (f == e) : false" << std::endl;
    std::cout << "\tf : " << f << std::endl;
    std::cout << "\te : " << e << std::endl << std::endl;

    if ( d != e)
        std::cout << "\t != : (d != e) : true" << std::endl;
    else
        std::cout << "\t != : (d != e) : false" << std::endl;
    std::cout << "\td : " << d << std::endl;
    std::cout << "\te : " << e << std::endl << std::endl;
    
    if (f <= e)
        std::cout << "\t <= : (f <= e) : true" << std::endl;
    else
        std::cout << "\t <= : (f <= e) : false" << std::endl;
    std::cout << "\tf : " << f << std::endl;
    std::cout << "\te : " << e << std::endl << std::endl;

    if (c >= d)
        std::cout << "\t >= : (c >= d) : true" << std::endl;
    else
        std::cout << "\t >= : (c >= d) : false" << std::endl;
    std::cout << "\tc : " << c << std::endl;
    std::cout << "\td : " << d << std::endl << std::endl;

    std::cout << "||||||||||||||||||||||||||||||||" << std::endl << std::endl;

    std::cout << "|||| Arithmetic Operators ||||||" << std::endl << std::endl;

    Fixed g( 15.52f );
    Fixed h( 16.39f );
    Fixed i( 15353.1f );
    Fixed j( h );
    Fixed k( 5.5f );
    Fixed l( 3.2f );

    std::cout << "\t[*] Multiplication Operator" << std::endl;
    std::cout << "\tg : " << g << std::endl;
    std::cout << "\th : " << h << std::endl;
    std::cout << "\ti : " << i << std::endl;
    std::cout << "\tj : " << j << std::endl;
    std::cout << "\tk : " << k << std::endl;
    std::cout << "\tl : " << l << std::endl;
    std::cout << "\tk * l : " << k * l << std::endl;
    std::cout << "\tg * h : " << g * h << std::endl;
    std::cout << "\tg * j : " << g * j << std::endl;
    std::cout << "\tg * i : " << g * i << std::endl << std::endl;

    std::cout << "\t[+] Addition Operator" << std::endl;
    std::cout << "\tg : " << g << std::endl;
    std::cout << "\th : " << h << std::endl;
    std::cout << "\ti : " << i << std::endl;
    std::cout << "\tj : " << j << std::endl;
    std::cout << "\tk : " << k << std::endl;
    std::cout << "\tl : " << l << std::endl;
    std::cout << "\tk + l : " << k + l << std::endl;
    std::cout << "\tj + i: " << j + i << std::endl;
    std::cout << "\tg + h : " << g + h << std::endl << std::endl;

    std::cout << "\t[-] Subtraction Operator" << std::endl;
    std::cout << "\tg : " << g << std::endl;
    std::cout << "\th : " << h << std::endl;
    std::cout << "\ti : " << i << std::endl;
    std::cout << "\tj : " << j << std::endl;
    std::cout << "\tk : " << k << std::endl;
    std::cout << "\tl : " << l << std::endl;
    std::cout << "\tk - l : " << k - l << std::endl;
    std::cout << "\tj - i: " << j - i << std::endl;
    std::cout << "\tg - h : " << g - h << std::endl << std::endl;

    std::cout << "\t[/] Division Operator" << std::endl;
    std::cout << "\tg : " << g << std::endl;
    std::cout << "\th : " << h << std::endl;
    std::cout << "\tk : " << k << std::endl;
    std::cout << "\tl : " << l << std::endl;
    std::cout << "\tk / l : " << k / l << std::endl;
    std::cout << "\th / j: " << h / j << std::endl;
    std::cout << "\tg / h : " << g / h << std::endl << std::endl;

    std::cout << "||||||||||||||||||||||||||||||||" << std::endl << std::endl;
    return 0;
}
