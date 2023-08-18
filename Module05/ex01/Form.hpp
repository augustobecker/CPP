#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Form
{

protected:

	const std::string	_name;
	bool                _isSigned;
	const int			_requiredGradeToSign;
	const int	        _requiredGradeToExecute;

public:

	Form( std::string );
	Form( std::string, int );
	~Form( void );

	Form(const Form &);
	Form& operator=(const Form &);

	std::string getName( void ) const;
	bool		getIsSigned( void ) const;
	int			getrequiredGradeToSign( void ) const;
	int			requiredGradeToExecute( void ) const;

	class GradeTooHighException : public std::exception
	{

	public:

		virtual ~GradeTooHighException() throw () {}

		virtual const char* what() const throw () {
			return "Grade Too High to sign this Form";
		}
	};

	class GradeTooLowException : public std::exception
	{

	public:

		virtual ~GradeTooLowException() throw () {}

		const char* what() const throw() 
		{
			return "Grade Too Low to sign this Form";
		}
	};

};

std::ostream& operator<<(std::ostream &, const Form &);

#endif
