#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <numeric>
# include <algorithm>
# include <vector>

class Span
{

private:

	const unsigned int	_maxSize;
	std::vector<int>	_elements;

public:

	Span( unsigned int );
	~Span( void );

	Span( const Span& );
	Span& operator=(const Span &);

	void addNumber( const int& );

	unsigned int    shortestSpan( void ) const;
	unsigned int    longestSpan( void ) const;

	void displayElem( void ) const;
};

#endif
