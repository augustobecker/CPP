#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define AVAILABLE_FORMS 3

class Intern
{

public:

	Intern( void );
	~Intern( void );

	Intern(const Intern& );
	Intern& operator=(const Intern& );

	AForm *makeShrubberyCreationForm( const std::string ) const;
	AForm *makeRobotomyRequestForm( const std::string ) const;
	AForm *makePresidentialPardonForm( const std::string ) const;

    AForm *makeForm( const std::string, const std::string ) const;

	class FormNotFoundException : public std::exception
	{

	public:
		const char* what() const throw();
	};

};

#endif
