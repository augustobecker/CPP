# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : AForm("RobotomyRequestForm", requiredGradeToSign, requiredGradeToExecute)
{
    this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm("RobotomyRequestForm", requiredGradeToSign, requiredGradeToExecute)
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
    AForm::execute(officeWorker);
    randomRobotomy();
}

void RobotomyRequestForm::randomRobotomy( void ) const
{
    int random_num;

    srand(time(NULL));
    random_num = (std::rand() % 100);
    std::cout << "Bzzzz bzzzzzz" << std::endl;
    if (random_num % 2)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << _target << " robotomy failed." << std::endl;
}
