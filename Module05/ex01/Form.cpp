# include <iostream>
# include <exception>
# include "Form.hpp"

Form::Form( const std::string name, int requiredGradeToSign, int requiredGradeToExecute ) : _name(name), _requiredGradeToSign(validateGrade(requiredGradeToSign)), _requiredGradeToExecute(validateGrade(requiredGradeToExecute))
{
    this->_isSigned = false;
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

bool    Form::beSigned( const Bureaucrat& officeWorker )
{
    try {
        if (officeWorker.getGrade() > this->_requiredGradeToSign)
            throw (Form::GradeTooLowException());
        this->_isSigned = true;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: Bureaucrat's grade isn't enough to sign this Form" << std::endl;
        return (false);
    }
    return (true);
}

int   Form::validateGrade( int grade )
{
    try {
        if (grade < this->_higestGrade)
        {
            grade = this->_higestGrade;
            throw (Bureaucrat::GradeTooHighException());
        }
        else if (grade > this->_lowestGrade)
        {
            grade = this->_lowestGrade;
            throw (Bureaucrat::GradeTooLowException());
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << "Invalid Grade passed as Parameter :" << e.what() << std::endl;
    }
    return (grade);
}

std::ostream& operator<<(std::ostream& os, const Form &obj)
{
	os << "Form " << obj.getName();
	return os;
}