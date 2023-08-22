#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

private:

	const std::string	_name;
	bool                _isSigned;
	const int			_requiredGradeToSign;
	const int	        _requiredGradeToExecute;

	static const int	_higestGrade = 1;
	static const int	_lowestGrade = 150;

public:

	Form( std::string, int, int );
	~Form( void );

	Form(const Form& );
	Form& operator=(const Form& );

	std::string getName( void ) const;
	bool		getIsSigned( void ) const;
	int			getRequiredGradeToSign( void ) const;
	int			getRequiredGradeToExecute( void ) const;

	bool		beSigned( const Bureaucrat& );

	int			validateGrade( int );

	class GradeTooHighException : public std::exception
	{

	public:

		virtual ~GradeTooHighException() throw () {}

		virtual const char* what() const throw () {
			return "Form's grade is too High (the highest possible grade is 1)";
		}
	};

	class GradeTooLowException : public std::exception
	{

	public:

		virtual ~GradeTooLowException() throw () {}

		const char* what() const throw() 
		{
			return "Form's grade is too Low (the lowest possible grade is 150)";
		}
	};

};

std::ostream& operator<<(std::ostream &, const Form &);

#endif
