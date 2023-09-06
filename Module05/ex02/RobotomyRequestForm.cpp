# include <iostream>
# include <exception>
# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : Form("RobotomyRequestForm", requiredGradeToSign, requiredGradeToExecute)
{
    this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : Form("RobotomyRequestForm", requiredGradeToSign, requiredGradeToExecute)
{
    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &toCopyFrom)
{
    if (this != &toCopyFrom)
    {
        this->_target = toCopyFrom.getTarget();
        this->setIsSigned(toCopyFrom.getIsSigned());
    }
    return (*this);
}

std::string RobotomyRequestForm::getTarget( void ) const
{
    return (this->_target);
}

void	RobotomyRequestForm::execute( Bureaucrat const& officeWorker ) const
{
    Form::execute(officeWorker);
    std::cout << "Bzzzz bzzzzzz" << std::endl;
    if (1)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << _target << " robotomy failed." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm &obj)
{
	os << "Form " << obj.getName() << ", form grade " << obj.getRequiredGradeToSign() << " to sign and grade " << obj.getRequiredGradeToExecute() << " to execute.";
	return os;
}