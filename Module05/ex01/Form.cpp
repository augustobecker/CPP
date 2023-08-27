# include <iostream>
# include <exception>
# include "Form.hpp"

Form::Form( const std::string name, int requiredGradeToSign, int requiredGradeToExecute ) : _name(name), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
    this->_isSigned = false;
    if (requiredGradeToSign < this->_higestGrade || requiredGradeToExecute < this->_higestGrade )
        throw (Form::GradeTooHighException());
    else if (requiredGradeToSign > this->_lowestGrade || requiredGradeToExecute > this->_lowestGrade)
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

void    Form::beSigned( const Bureaucrat& officeWorker )
{
    if (officeWorker.getGrade() > this->_requiredGradeToSign)
        throw (Form::GradeTooLowException());
    this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw () 
{
	return ("Form's grade is too High (the highest possible grade is 1)");
}

const char* Form::GradeTooLowException::what() const throw() 
{
	return ("Form's grade is too Low (the lowest possible grade is 150)");
}

std::ostream& operator<<(std::ostream& os, const Form &obj)
{
	os << "Form " << obj.getName() << ", form grade " << obj.getRequiredGradeToSign() << " to sign and grade " << obj.getRequiredGradeToExecute() << " to execute.";
	return os;
}