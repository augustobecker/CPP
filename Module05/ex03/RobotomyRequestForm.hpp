#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"
# include <time.h>

class RobotomyRequestForm : public Form
{

private:

	std::string			_target;

	static const int	requiredGradeToSign = 72;
	static const int	requiredGradeToExecute = 45;

public:

	RobotomyRequestForm( std::string );
	~RobotomyRequestForm( void );

	RobotomyRequestForm(const RobotomyRequestForm& );
	RobotomyRequestForm& operator=(const RobotomyRequestForm& );

	std::string getTarget( void ) const;

    void	execute( Bureaucrat const& ) const;

	void 	randomRobotomy( void ) const;

};

#endif
