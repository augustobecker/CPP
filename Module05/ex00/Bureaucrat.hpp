#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{

protected:

public:

	Bureaucrat( void );
	~Bureaucrat( void );

	Bureaucrat(Bureaucrat &);
	Bureaucrat& operator=(Bureaucrat &);

};

#endif
