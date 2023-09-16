# include <iostream>
# include <exception>
# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) : AForm("PresidentialPardonForm", requiredGradeToSign, requiredGradeToExecute)
{
    this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm("PresidentialPardonForm", requiredGradeToSign, requiredGradeToExecute)
{
    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &toCopyFrom)
{
    if (this != &toCopyFrom)
    {
        this->_target = toCopyFrom.getTarget();
        this->setIsSigned(toCopyFrom.getIsSigned());
    }
    return (*this);
}

std::string PresidentialPardonForm::getTarget( void ) const
{
    return (this->_target);
}

void	PresidentialPardonForm::execute( Bureaucrat const& officeWorker ) const
{
    AForm::execute(officeWorker);
    pardon();
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm &obj)
{
	os << "Form " << obj.getName() << ", form grade " << obj.getRequiredGradeToSign() << " to sign and grade " << obj.getRequiredGradeToExecute() << " to execute.";
	return os;
}

void PresidentialPardonForm::pardon( void ) const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}