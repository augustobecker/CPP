# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name ) : _name(name)
{
    this->_range = 150;
}

Bureaucrat::Bureaucrat( const std::string name, const int grade ) : _name(name)
{
    this->_range = grade;
}


Bureaucrat::~Bureaucrat( void )
{

}

Bureaucrat::Bureaucrat(Bureaucrat &obj) : _name(obj.getName())
{
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &toCopyFrom)
{
    if (this != &toCopyFrom)
        this->_range = toCopyFrom.getRange();
    return (*this);
}

std::string Bureaucrat::getName( void ) const
{
    return (this->_name);
}

int Bureaucrat::getRange( void ) const
{
    return (this->_range);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getRange();
	return os;
}
