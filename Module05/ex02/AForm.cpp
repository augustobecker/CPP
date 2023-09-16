# include <iostream>
# include <exception>
# include "AForm.hpp"

AForm::AForm( const std::string name, int requiredGradeToSign, int requiredGradeToExecute ) : _name(name), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
    this->_isSigned = false;
    if (requiredGradeToSign < this->higestGrade || requiredGradeToExecute < this->higestGrade )
        throw (AForm::GradeTooHighException());
    else if (requiredGradeToSign > this->lowestGrade || requiredGradeToExecute > this->lowestGrade)
        throw (AForm::GradeTooLowException());
}

AForm::~AForm( void )
{

}

AForm::AForm(const AForm &obj) : _name(obj.getName()),  _requiredGradeToSign(obj.getRequiredGradeToSign()), _requiredGradeToExecute(obj.getRequiredGradeToExecute())
{
    *this = obj;
}

AForm& AForm::operator=(const AForm &toCopyFrom)
{
    if (this != &toCopyFrom)
        this->_isSigned = toCopyFrom.getIsSigned();
    return (*this);
}

std::string AForm::getName( void ) const
{
    return (this->_name);
}

bool AForm::getIsSigned( void ) const
{
    return (this->_isSigned);
}

int AForm::getRequiredGradeToSign( void ) const
{
    return (this->_requiredGradeToSign);
}

int AForm::getRequiredGradeToExecute( void ) const
{
    return (this->_requiredGradeToExecute);
}

void AForm::setIsSigned( bool isSigned )
{
    this->_isSigned = isSigned;
}

void AForm::beSigned( Bureaucrat const& officeWorker )
{
    if (officeWorker.getGrade() > this->_requiredGradeToSign)
        throw (AForm::GradeTooLowException());
    this->setIsSigned(true);
}

void AForm::execute( Bureaucrat const& executor ) const
{
    if (!_isSigned)
        throw (AForm::NotSignedException());
    if (executor.getGrade() > this->_requiredGradeToExecute)
        throw (AForm::GradeTooLowException());
}

const char* AForm::GradeTooHighException::what() const throw () 
{
	return ("Grade is too High for Form");
}

const char* AForm::GradeTooLowException::what() const throw() 
{
	return ("Grade is too Low for Form");
}

const char* AForm::AlreadySignedException::what() const throw() 
{
	return ("Form's is already signed.");
}

const char* AForm::NotSignedException::what() const throw() 
{
	return ("Form could not be executed yet because it is not signed.");
}