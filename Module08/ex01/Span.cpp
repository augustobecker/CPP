# include "Span.hpp"
# include <iostream>
# include <exception>

Span::Span( unsigned int spanMaxSize ) : _maxNumOfElements(spanMaxSize)
{

}

Span::~Span( void )
{

}

Span::Span(const Span &obj) : _maxNumOfElements(obj._maxNumOfElements)
{
    *this = obj;
}

Span& Span::operator=(const Span &toCopyFrom)
{
    if (this != &toCopyFrom)
        return (*this);
    return (*this);
}


void Span::addNumber( const int newNbr )
{

}


void Span::decrementGrade( int decrement )
{
    if ((this->_grade + decrement) > this->_lowestGrade)
        throw (Span::GradeTooLowException());
    this->_grade += decrement;
}

std::string Span::getName( void ) const
{
    return (this->_name);
}

int Span::getGrade( void ) const
{
    return (this->_grade);
}

const char* Span::GradeTooHighException::what() const throw()
{
    return ("Span's grade is too High (the highest possible grade is 1)");
}

const char* Span::GradeTooLowException::what() const throw()
{
    return ("Span's grade is too Low (the lowest possible grade is 150)");
}
