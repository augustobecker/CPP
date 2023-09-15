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

	template<typename T>
    void addNumbersRange(const T& begin, const T& end);

	unsigned int    shortestSpan( void ) const;
	unsigned int    longestSpan( void ) const;

	void displayElem( void ) const;
};

template<typename T>
void Span::addNumbersRange(const T& begin, const T& end) {
    for (T it = begin; it != end; ++it) {
        addNumber(*it);
    }
}

#endif
