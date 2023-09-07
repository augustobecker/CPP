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

	Form *makeShrubberyCreationForm( const std::string ) const;
	Form *makeRobotomyRequestForm( const std::string ) const;
	Form *makePresidentialPardonForm( const std::string ) const;

    Form *makeForm( const std::string, const std::string ) const;

	class FormNotFoundException : public std::exception
	{

	public:
		const char* what() const throw();
	};

};

#endif
