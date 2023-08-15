#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{

protected:

	const std::string	_name;
	int					_range;

public:

	Bureaucrat( const std::string );
	Bureaucrat( const std::string, const int );
	~Bureaucrat( void );

	Bureaucrat(Bureaucrat &);
	Bureaucrat& operator=(Bureaucrat &);

	std::string getName( void ) const;
	int			getRange( void ) const;

};

std::ostream& operator<<(std::ostream &, const Bureaucrat &);

#endif
