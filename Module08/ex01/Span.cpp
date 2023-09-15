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
    unsigned int copySize = std::min(
        static_cast<unsigned int>(toCopyFrom._elements.size()),
        this->_maxSize);

    if (this != &toCopyFrom)
    {
        this->_elements.clear();
        this->_elements.insert(
            this->_elements.end(), 
            toCopyFrom._elements.begin(), 
            toCopyFrom._elements.begin() + copySize);
    }
    return (*this);
}

void Span::addNumber( const int &newNbr )
{
    if (_elements.size() >= _maxSize)
        throw std::overflow_error("Reached Max capacity of Vector");
    _elements.push_back(newNbr);
}

unsigned int absoluteValue (int value)
{
    return (std::abs(value));
}

unsigned int    Span::shortestSpan( void ) const
{
    if (_elements.size() <= 1)
        throw std::out_of_range("Insufficient values to calculate Span");

    std::vector<int> differences(_elements.size());

    std::adjacent_difference(_elements.begin(), _elements.end(), differences.begin());
    std::transform(differences.begin(), differences.end(), differences.begin(), absoluteValue);

    return (*std::min_element(differences.begin(), differences.end()));

}

unsigned int    Span::longestSpan( void ) const
{
    if (_elements.size() <= 1)
        throw std::out_of_range("Insufficient values to calculate Span");
    return (
        *std::max_element(_elements.begin(), _elements.end()) -
        *std::min_element(_elements.begin(), _elements.end()));
}

void Span::displayElem( void ) const
{
    std::cout << "Span: ";
    for (int i = 0; i < (int) _elements.size(); i++)
        std::cout << "[" << _elements.at(i) << "] ";
    std::cout << std::endl;
}
