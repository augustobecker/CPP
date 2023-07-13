/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:22:03 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/30 20:22:30 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

void subjectTests( void );
void showSubjectExpectedOutput( void );

void testComparisonOperators( void );
void testArithmeticOperators( void );
void testMinMaxMethods( void );

int main( void )
{
    subjectTests();
    showSubjectExpectedOutput();
    testComparisonOperators();
    testArithmeticOperators();
    testMinMaxMethods();

    return 0;
}


void subjectTests( void )
{
	std::cout << "_________| Subject Tests |__________" << std::endl;
	Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    return ;
}

void showSubjectExpectedOutput( void )
{
	std::cout << std::endl << "_________| Subject Expected Output |__________" << std::endl;
	std::cout << "\t" << "0" << std::endl;
	std::cout << "\t" << "0.00390625" << std::endl;
	std::cout << "\t" << "0.00390625" << std::endl;
	std::cout << "\t" << "0.00390625" << std::endl;
	std::cout << "\t" << "0.0078125" << std::endl;
	std::cout << "\t" << "10.1016" << std::endl;
	std::cout << "\t" << "10.1016" << std::endl << std::endl;
}

void testComparisonOperators( void )
{

    Fixed c( 5.5f );
    const Fixed d( 4.34f );
    Fixed e( 1.5f );
    Fixed f( e );

    std::cout << "||||||||||||||||||||||||||||||||" << std::endl << std::endl;
    std::cout << "|||| Comparison Operators ||||||" << std::endl << std::endl;

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
}

void testArithmeticOperators( void )
{

    const Fixed g( 5 );
    Fixed h( 1.5f );
    const Fixed i( 100 );
    Fixed j( h );
    Fixed k( 2.4f );
    Fixed l( 3.3f );

    std::cout << "|||| Arithmetic Operators ||||||" << std::endl << std::endl;

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
    std::cout << "\tj : " << j << std::endl;
    std::cout << "\tk : " << k << std::endl;
    std::cout << "\tl : " << l << std::endl;
    std::cout << "\tk / l : " << k / l << std::endl;
    std::cout << "\th / j: " << h / j << std::endl;
    std::cout << "\tg / h : " << g / h << std::endl << std::endl;

    std::cout << "||||||||||||||||||||||||||||||||" << std::endl << std::endl;
}

void testMinMaxMethods( void )
{
    Fixed c( 5.5f );
    const Fixed d( 4.34f );
    Fixed e( 1.5f );
    Fixed f( e );
    const Fixed g( 5 );
    Fixed h( 1.5f );
    const Fixed i( 100 );
    Fixed j( h );
    Fixed k( 2.4f );
    Fixed l( 3.3f );

    std::cout << "|||||||| Min Max Methods |||||||" << std::endl << std::endl;

    std::cout << "\tFixed::max(c , d) : (c :: " << c << ")" << std::endl;
    std::cout << "\tReturn: " << Fixed::max( c, d ) << std::endl;
    std::cout << "\tc : " << c << std::endl;
    std::cout << "\td : " << d << std::endl << std::endl;

    std::cout << "\tFixed::min(c , d) : (d :: " << d << ")" << std::endl;
    std::cout << "\tReturn: " << Fixed::min( c, d ) << std::endl;
    std::cout << "\tc : " << c << std::endl;
    std::cout << "\td : " << d << std::endl << std::endl;

    std::cout << "\tFixed::max(e , f) : They're equal" << std::endl;
    std::cout << "\tReturn: " << Fixed::max( e, f ) << std::endl;
    std::cout << "\tf : " << f << std::endl;
    std::cout << "\te : " << e << std::endl << std::endl;

    std::cout << "\tFixed::min(e , f) : They're equal" << std::endl;
    std::cout << "\tReturn: " << Fixed::min( e, f ) << std::endl;
    std::cout << "\tf : " << f << std::endl;
    std::cout << "\te : " << e << std::endl << std::endl;

    std::cout << "\tFixed::max(d , e) : (d :: " << d << ")" << std::endl;
    std::cout << "\tReturn: " << Fixed::max( d, e ) << std::endl;
    std::cout << "\td : " << d << std::endl;
    std::cout << "\te : " << e << std::endl << std::endl;

    std::cout << "\tFixed::min(d , e) : (e :: " << e << ")" << std::endl;
    std::cout << "\tReturn: " << Fixed::min( d, e ) << std::endl;
    std::cout << "\td : " << d << std::endl;
    std::cout << "\te : " << e << std::endl << std::endl;
    
    std::cout << "||||||||||||||||||||||||||||||||" << std::endl << std::endl;
}