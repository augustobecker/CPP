#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"
# include <time.h>

class RobotomyRequestForm : public AForm
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

std::ostream& operator<<(std::ostream &, const RobotomyRequestForm &);

#endif
