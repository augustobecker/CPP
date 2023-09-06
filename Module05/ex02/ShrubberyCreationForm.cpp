# include <iostream>
# include <exception>
# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) : Form("ShrubberyCreationForm", requiredGradeToSign, requiredGradeToExecute)
{
    this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : Form("ShrubberyCreationForm", requiredGradeToSign, requiredGradeToExecute)
{
    *this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &toCopyFrom)
{
    if (this != &toCopyFrom)
    {
        this->_target = toCopyFrom.getTarget();
        this->setIsSigned(toCopyFrom.getIsSigned());
    }
    return (*this);
}

std::string ShrubberyCreationForm::getTarget( void ) const
{
    return (this->_target);
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm &obj)
{
	os << "Form " << obj.getName() << ", form grade " << obj.getRequiredGradeToSign() << " to sign and grade " << obj.getRequiredGradeToExecute() << " to execute.";
	return os;
}