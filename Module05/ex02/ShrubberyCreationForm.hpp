#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"
# include <fstream> 
# include <stdlib.h> 

class ShrubberyCreationForm : public Form
{

private:

	std::string			_target;

	static const int	requiredGradeToSign = 145;
	static const int	requiredGradeToExecute = 137;

public:

	ShrubberyCreationForm( std::string );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm(const ShrubberyCreationForm& );
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& );

	std::string getTarget( void ) const;

	void	execute( Bureaucrat const& ) const;

	void 	createShrubberyTree( void ) const;

};

std::ostream& operator<<(std::ostream &, const ShrubberyCreationForm &);

#endif
