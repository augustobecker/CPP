# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
{
    std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &obj)
{
    std::cout << "Bureaucrat Copy Constructor called" << std::endl;
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &toCopyFrom)
{
    std::cout << "Bureaucrat Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
        return (*this);
    return (*this);
}
