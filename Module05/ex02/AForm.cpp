# include <iostream>
# include <exception>
# include "AForm.hpp"

Form::Form( const std::string name, int requiredGradeToSign, int requiredGradeToExecute ) : _name(name), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
    this->_isSigned = false;
    if (requiredGradeToSign < this->higestGrade || requiredGradeToExecute < this->higestGrade )
        throw (Form::GradeTooHighException());
    else if (requiredGradeToSign > this->lowestGrade || requiredGradeToExecute > this->lowestGrade)
        throw (Form::GradeTooLowException());
}

Form::~Form( void )
{

}

Form::Form(const Form &obj) : _name(obj.getName()),  _requiredGradeToSign(obj.getRequiredGradeToSign()), _requiredGradeToExecute(obj.getRequiredGradeToExecute())
{
    *this = obj;
}

Form& Form::operator=(const Form &toCopyFrom)
{
    if (this != &toCopyFrom)
        this->_isSigned = toCopyFrom.getIsSigned();
    return (*this);
}

std::string Form::getName( void ) const
{
    return (this->_name);
}

bool Form::getIsSigned( void ) const
{
    return (this->_isSigned);
}

int Form::getRequiredGradeToSign( void ) const
{
    return (this->_requiredGradeToSign);
}

int Form::getRequiredGradeToExecute( void ) const
{
    return (this->_requiredGradeToExecute);
}

void Form::setIsSigned( bool isSigned )
{
    this->_isSigned = isSigned;
}

void Form::beSigned( Bureaucrat const& officeWorker )
{
    if (officeWorker.getGrade() > this->_requiredGradeToSign)
        throw (Form::GradeTooLowException());
    this->setIsSigned(true);
}

void Form::execute( Bureaucrat const& executor ) const
{
    if (!_isSigned)
        throw (Form::NotSignedException());
    if (executor.getGrade() > this->_requiredGradeToExecute)
        throw (Form::GradeTooLowException());
}

const char* Form::GradeTooHighException::what() const throw () 
{
	return ("Grade is too High for Form");
}

const char* Form::GradeTooLowException::what() const throw() 
{
	return ("Grade is too Low for Form");
}

const char* Form::NotSignedException::what() const throw() 
{
	return ("Form could not be executed yet because it is not signed.");
}