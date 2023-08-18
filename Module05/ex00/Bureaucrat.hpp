#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{

protected:

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

	Bureaucrat operator++( void );
	Bureaucrat operator++( int );

	Bureaucrat operator--( void );
	Bureaucrat operator--( int );

	std::string getName( void ) const;
	int			getGrade( void ) const;

	class GradeTooHighException : public std::exception
	{

	public:

		virtual ~GradeTooHighException() throw () {}

        virtual const char* what() const throw () {
            return "Bureaucrat's grade is too High (the highest possible grade is 1)";
        }
	};

	class GradeTooLowException : public std::exception
	{

	public:

		virtual ~GradeTooLowException() throw () {}

        const char* what() const throw() 
		{
            return "Bureaucrat's grade is too Low (the lowest possible grade is 150)";
    	}
	};

};

std::ostream& operator<<(std::ostream &, const Bureaucrat &);

#endif
