/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 04:26:39 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/29 20:43:59 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

void subjectTests( void );
void showSubjectExpectedOutput( void );
void ExtraTests( void );

int main( void )
{
	subjectTests();
	showSubjectExpectedOutput();
	ExtraTests();
}

void subjectTests( void )
{
	std::cout << "_________| Subject Tests |__________" << std::endl;
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

void showSubjectExpectedOutput( void )
{
	std::cout << std::endl << "_________| Subject Expected Output |__________" << std::endl;
	std::cout << "\t" << "Default constructor called" << std::endl;
	std::cout << "\t" << "Int constructor called" << std::endl;
	std::cout << "\t" << "Float constructor called" << std::endl;
	std::cout << "\t" << "Copy constructor called" << std::endl;
	std::cout << "\t" << "Copy assignment operator called" << std::endl;
	std::cout << "\t" << "Float constructor called" << std::endl;
	std::cout << "\t" << "Copy assignment operator called" << std::endl;
	std::cout << "\t" << "Destructor called" << std::endl;
	std::cout << "\t" << "a is 1234.43" << std::endl;
	std::cout << "\t" << "b is 10" << std::endl;
	std::cout << "\t" << "c is 42.4219" << std::endl;
	std::cout << "\t" << "d is 10" << std::endl;
	std::cout << "\t" << "a is 1234 as integer" << std::endl;
	std::cout << "\t" << "b is 10 as integer" << std::endl;
	std::cout << "\t" << "c is 42 as integer" << std::endl;
	std::cout << "\t" << "d is 10 as integer" << std::endl;
	std::cout << "\t" << "Destructor called" << std::endl;
	std::cout << "\t" << "Destructor called" << std::endl;
	std::cout << "\t" << "Destructor called" << std::endl;
	std::cout << "\t" << "Destructor called" << std::endl;
}

void ExtraTests( void )
{
	std::cout << std::endl << "_________| Extra Tests |__________" << std::endl;
	Fixed a;
	Fixed const b( 113 );
	Fixed const c( 42.421f );
	Fixed const d( c );
	Fixed const e( 8388606 );
	Fixed const f( -8388606 );

	a = Fixed( 1234.567f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << "f is " << f.toInt() << " as integer" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	std::cout << "e is " << e.toFloat() << " as float" << std::endl;
	std::cout << "f is " << f.toFloat() << " as float" << std::endl;
}
