# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name ) : _name(name)
{
    this->_grade = this->_lowestGrade;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
    try {
        this->_grade = grade;
        if (this->_grade < this->_higestGrade)
        {
            this->_grade = this->_higestGrade;
            throw (Bureaucrat::GradeTooHighException());
        }
        else if (this->_grade > this->_lowestGrade)
        {
            this->_grade = this->_lowestGrade;
            throw (Bureaucrat::GradeTooLowException());
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
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

void    Bureaucrat::signForm( Form* document ) const
{
    try {
        document->beSigned(*this);
    }
    catch (const std::exception &e)
    {
        std::cout << this->_name << " couldn’t sign " << document->getName() << " because Bureaucrat's grade isn't enough to sign this Form" << std::endl;
        return;
    }
    std::cout << this->_name << " signed " << document->getName() << std::endl;
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
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}
