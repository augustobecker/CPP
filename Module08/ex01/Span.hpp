#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <algorithm>

class Span
{

private:

    const unsigned int     _maxNumOfElements;

public:

    Span( unsigned int );
    ~Span( void );

    Span( const Span& );
    Span& operator=(const Span &);

    void addNumber( const int );

    unsigned int    shortestSpan( void ) const;
    unsigned int    longestSpan( void ) const;
}


#endif
