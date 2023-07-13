#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{

private:

    const Fixed     _x;
    const Fixed     _y;

public:

	Point( void );

	Point( const Fixed& , const Fixed& );
	~Point( void );

	Point( const Point& );
	Point& operator=( const Point& );

	Fixed		getPositionX( void ) const;
    Fixed		getPositionY( void ) const;

};

#endif
