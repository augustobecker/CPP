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

Bureaucrat Bureaucrat::operator++( void )
{
	try {
        _grade--;
        if (_grade < _higestGrade)
        {
            throw (Bureaucrat::GradeTooHighException());
            _grade++;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
	return (Bureaucrat(_name, _grade));
}

Bureaucrat Bureaucrat::operator++( int )
{
	int tempGrade;

	tempGrade = _grade;
    try {
        _grade--;
        if (_grade < _higestGrade)
        {
            throw (Bureaucrat::GradeTooHighException());
            _grade++;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
	return (Bureaucrat(_name, tempGrade));
}

Bureaucrat Bureaucrat::operator--( void )
{
    try {
        _grade++;
        if (_grade > _lowestGrade)
        {
            throw (Bureaucrat::GradeTooLowException());
            _grade--;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
	return (Bureaucrat(_name, _grade));
}

Bureaucrat Bureaucrat::operator--( int )
{
	int tempGrade;

	tempGrade = _grade;
    try {
        _grade++;
        if (_grade > _lowestGrade)
        {
            throw (Bureaucrat::GradeTooLowException());
            _grade--;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
	return (Bureaucrat(_name, tempGrade));
}

std::string Bureaucrat::getName( void ) const
{
    return (this->_name);
}

int Bureaucrat::getGrade( void ) const
{
    return (this->_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
