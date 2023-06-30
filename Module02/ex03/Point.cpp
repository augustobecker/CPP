/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:50:41 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/30 21:45:39 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
    return ;
}

Point::Point( const Fixed &xObj , const Fixed &yObj ): _x(xObj), _y(yObj)
{
    return ;
}

Point::~Point( void )
{
    return ;
}

Point::Point( const Point &obj ) : _x(obj.getPositionX()), _y(obj.getPositionY())
{
    return ;
}

Point &Point::operator=( const Point &obj )
{
    if (this != &obj)
	    return (*this);
    return (*this);
}

Fixed Point::getPositionX( void ) const
{
	return (_x);
}

Fixed Point::getPositionY( void ) const
{
	return (_y);
}
