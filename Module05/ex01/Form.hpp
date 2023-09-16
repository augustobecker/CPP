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

	void		beSigned( const Bureaucrat& );

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

	class AlreadySignedException : public std::exception
	{

	public:
        virtual const char* what() const throw ();
	};

};

std::ostream& operator<<(std::ostream &, const Form &);

#endif
