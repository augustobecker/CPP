# include "Span.hpp"
# include <iostream>
# include <exception>

Span::Span( unsigned int spanMaxSize ) : _maxSize(spanMaxSize)
{

}

Span::~Span( void )
{

}

Span::Span(const Span &obj) : _maxSize(obj._maxSize)
{
    *this = obj;
}

Span& Span::operator=(const Span &toCopyFrom)
{
    if (this != &toCopyFrom)
        return (*this);
    return (*this);
}

void Span::addNumber( const int &newNbr )
{
    if (_elements.size() >= _maxSize)
        throw std::overflow_error("Reached Max capacity of Vector");
    _elements.push_back(newNbr);
}

unsigned int    Span::shortestSpan( void ) const
{
    return (1);
}

unsigned int    Span::longestSpan( void ) const
{
    return (1);
}

void Span::displayElem( void ) const
{
    std::cout << "Span: ";
    for (int i = 0; i < (int) _elements.size(); i++)
        std::cout << "[" << _elements.at(i) << "] ";
    std::cout << std::endl;
}
