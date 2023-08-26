# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name ) : _name(name)
{
    this->_grade = this->_lowestGrade;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade)
{
    if (grade < this->_higestGrade)
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > this->_lowestGrade)
        throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::~Bureaucrat( void )
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj.getName())
{
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &toCopyFrom)
{
    if (this != &toCopyFrom)
        this->_grade = toCopyFrom.getGrade();
    return (*this);
}

void Bureaucrat::incrementGrade( int increment )
{  
    if ((this->_grade - increment) < this->_higestGrade)
        throw (Bureaucrat::GradeTooHighException());
    this->_grade -= increment;
}

void Bureaucrat::decrementGrade( int decrement )
{
    if ((this->_grade + decrement) > this->_lowestGrade)
        throw (Bureaucrat::GradeTooLowException());
    this->_grade += decrement;
}

std::string Bureaucrat::getName( void ) const
{
    return (this->_name);
}

int Bureaucrat::getGrade( void ) const
{
    return (this->_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat's grade is too High (the highest possible grade is 1)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat's grade is too Low (the lowest possible grade is 150)");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
