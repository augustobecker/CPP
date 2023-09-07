#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{

private:

	const std::string	_name;
	int					_grade;
	static const int	_higestGrade = 1;
	static const int	_lowestGrade = 150;

public:

	Bureaucrat( std::string );
	Bureaucrat( std::string, int );
	~Bureaucrat( void );

	Bureaucrat(const Bureaucrat &);
	Bureaucrat& operator=(const Bureaucrat &);

	void		incrementGrade( const int );
	void		decrementGrade( const int );

	std::string getName( void ) const;
	int			getGrade( void ) const;

	class GradeTooHighException : public std::exception
	{

	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{

	public:
        virtual const char* what() const throw ();
	};

};

std::ostream& operator<<(std::ostream &, const Bureaucrat &);

#endif
