# include "Intern.hpp"

Intern::Intern( void )
{

}

Intern::~Intern( void )
{

}

Intern::Intern(const Intern &obj)
{
    *this = obj;
}

Intern& Intern::operator=(const Intern &toCopyFrom)
{
    if (this != &toCopyFrom)
        return (*this);
    return (*this);
}

Form *Intern::makeShrubberyCreationForm( const std::string target ) const
{
    return (new ShrubberyCreationForm(target));
}

Form *Intern::makeRobotomyRequestForm( const std::string target ) const
{
    return (new RobotomyRequestForm(target));
}

Form *Intern::makePresidentialPardonForm( const std::string target ) const
{
    return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm( const std::string formType, const std::string target ) const
{
    Form* (Intern::*formConstructor[AVAILABLE_FORMS])(const std::string) const = {
        &Intern::makeShrubberyCreationForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm
    };
	std::string	options[AVAILABLE_FORMS] = {
		"shrubbery creation",
        "robotomy request",
        "presidential pardon"
        };
	
    for (int i = 0; i < AVAILABLE_FORMS; i++)
	{
		if (formType == (options[i]))
            return (this->*formConstructor[i])(target);
	}
    throw Intern::FormNotFoundException();
    return (NULL);
}

const char* Intern::FormNotFoundException::what() const throw() 
{
	return ("The form could not be created because it was not found in our database");
}